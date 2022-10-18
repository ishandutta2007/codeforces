#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());


int bpow(int x, int64_t n, int m) {
	return n ? n % 2 ? x * bpow(x, n - 1, m) % m : bpow(x * x % m, n / 2, m) : 1;
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	vector<int> cnt(m);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(all(a));
	vector<int64_t> pw(m);
	int ans = 1;
	for(int i = 0; i < n; i++) {
		a[i] %= m;
		for(int j = 0; j < m; j++) {
			int pwr = a[i] - j + (a[i] < j ? m : 0);
			pw[pwr] += cnt[j];
		}
		cnt[a[i]]++;
	}
	for(int i = 0; i < m; i++) {
		ans *= bpow(i, pw[i], m);
		ans %= m;
	}
	cout << ans << endl;
}

signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	t = 1;//cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}