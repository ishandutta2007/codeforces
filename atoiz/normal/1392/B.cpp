#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int tests;
	cin >> tests;
	while (tests--) {
		int n;
		int64_t k;
		cin >> n >> k;
		vector<int> vec(n);
		for (auto &x : vec) cin >> x;
		int d = *max_element(vec.begin(), vec.end());
		for (auto &x : vec) x = d - x;
		if (k % 2 == 0) {
			d = *max_element(vec.begin(), vec.end());
			for (auto &x : vec) x = d - x;
		}
		for (auto &x : vec) cout << x << ' ';
		cout << '\n';
	}
}