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
		cin >> n;
		vector<int> vec(n);
		for (auto &x : vec) cin >> x;
		int64_t ans = 0;
		for (int i = 1; i < n; ++i) ans += max(0, vec[i - 1] - vec[i]);
		cout << ans << '\n';
	}
}