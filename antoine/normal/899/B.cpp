#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <array>
#include <deque>
#include <cmath>

using namespace std;

auto f(std::vector<int> &v) {
	string s;
	for (auto &&x : v)
		s += std::to_string(x) + "_";
	return s;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	std::vector<int> A = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	std::vector<int> B = A;
	B[1] = 29;

	std::string s = f(A) + f(A) + f(B) + f(A) + f(A);
    s += s;
    s += s;
    
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i)
		std::cin >> a[i];

	string s2 = "_" + f(a);
	for(int i = 0; i < s.size(); ++i)
		for(int j = i; j < s.size(); ++j)
			if (s.substr(i, j - i) == s2) {
				std::cout << "Yes\n";
				return 0;
			}
	std::cout << "No\n";
	return 0;
}