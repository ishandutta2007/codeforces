#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, x, k; cin >> n >> x >> k;
	int a[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	map<int, int> l, cnt;
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		l[(a[i] - 1) / x]++;
		ans += l[a[i] / x - k];
		cnt[a[i]]++;
	}
	for(auto it = cnt.begin(); it != cnt.end(); it++)
		if(k == 0 && it->first % x != 0 || k == 1 && it->first % x == 0)
			ans += (ll)it->second * (it->second - 1) / 2;
	cout << ans;
}