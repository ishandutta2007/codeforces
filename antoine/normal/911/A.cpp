#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int a[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	set<int> nums;
	int n;
	cin >> n;
	int m = 1e9 + 1000;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (a[i] < m)
			m = a[i];
	}
	int ans = 2 * n;
	int last = -2 * n;
	for (int i = 0; i < n; ++i) {
		if (m == a[i]) {
			ans = std::min(ans, i - last);
			last = i;
		}
	}
	cout << ans;
	return 0;
}