#include <bits/stdc++.h>
using namespace std;

map <int, long long> mp;
int main() {
	long long ans = 0;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		long long y = mp[i - x] + x;
		ans = max(ans, y);
		mp[i - x] = max(mp[i - x], y);
	}
	cout << ans;
	return 0;
}