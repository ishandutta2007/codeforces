#pragma GCC optimize("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
using ll = long long;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> ks(n);
	for (auto& k : ks) {
		cin >> k;
		--k;
	}
	vector<int> c(m);
	vector<ll> cs(m);
	for (int i = 0; i < m; i++) {
		cin >> c[i];
		cs[i] = c[i] + (i ? cs[i - 1] : 0);
	}
	sort(ks.begin(), ks.end());
	vector<ll> lol(n);
	for (int i = 0; i < n; i++) {
		lol[i] = c[ks[i]] + (i ? lol[i - 1] : 0);
	}
	vector<int> podkek(n);
	for (int i = n - 1; i >= 0; i--) {
		podkek[i] = ks[i] - i;
		if (i < n - 1) {
			podkek[i] = min(podkek[i], podkek[i + 1]);
		}
	}
	ll ans = lol.back();
	for (int i = 0; i < n; i++) {
		if (podkek[i] + i >= 0) {
			ans = min(ans, (i ? lol[i - 1] : 0) + cs[n - 1 - i]);
		}
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}
}