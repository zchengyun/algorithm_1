#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
#include <numeric>

//find

int main()
{
	std::vector<int> foo;// 构造一个 vector 对象
	foo.resize(10);
	std::iota(foo.begin(), foo.end(), 5);// 将从 5开始的 10 次递增值赋值给 foo
	// 输出 foo 中的内容
	std::copy(foo.begin(), foo.end(), std::ostream_iterator<int>(std::cout, " "));//以空格隔开
	std::cout << std::endl;

	std::copy_if(foo.begin(), foo.end(),
		std::ostream_iterator<int>(std::cout, " "),
		[](int x) { return (x % 2) == 1; });//奇数才输出

	namespace ranges = std::ranges;//C++20
	auto result1 = ranges::find(foo, 8);
	auto result2 = ranges::find(foo.begin(), foo.end(), 20);
	if (result1 != foo.end()) {
		std::cout << "\nv contains: " << 8 << '\n';
	}
	else {
		std::cout << "v does not contain: " << 8 << '\n';
	}

	if (result2 != foo.end()) {
		std::cout << "v contains: " << 20 << '\n';
	}
	else {
		std::cout << "v does not contain: " << 20 << '\n';
	}

	//在范围[first, last) 中搜索序列[s_first, s_last) 的最后一次出现。
	std::vector<int> v{1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4};
	std::vector<int> t1{ 1, 2, 3 };
	std::vector<int>::iterator result;

	result = std::find_end(v.begin(), v.end(), t1.begin(), t1.end());
	if (result == v.end()) {
		std::cout << "not found\n";
	}
	else {
		std::cout << "last subsequence is at: "
			<< std::distance(v.begin(), result) << "\n";
	}

}