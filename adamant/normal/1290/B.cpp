#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 2e5 + 42, sigma = 26;
int cnt[maxn][sigma];

void solve() {
	string s;
	cin >> s;
	int n = s.size();
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < sigma; j++) {
			cnt[i + 1][j] = cnt[i][j] + (s[i] == j + 'a');
		}
	}
	int q;
	cin >> q;
	for(int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		int letters = 0;
		for(int j = 0; j < sigma; j++) {
			letters += cnt[r][j] > cnt[l - 1][j];
		}
		if(letters > 2 || s[l - 1] != s[r - 1] || r == l) {
			cout << "Yes" << "\n";
		} else {
			cout << "No" << "\n";
		}
	}
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