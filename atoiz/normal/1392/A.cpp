#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tests;
	cin >> tests;
	while (tests--) {
		int n;
		cin >> n;
		vector<int> vec(n);
		for (auto &x : vec) cin >> x;
		cout << (*min_element(vec.begin(), vec.end()) == *max_element(vec.begin(), vec.end()) ? n : 1) << '\n';
	}
}