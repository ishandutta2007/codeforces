#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const int inf = 1e9;

int cnt[26];
int cn[26][26];

void solve() {
	string s;
	cin >> s;
	int ans = 0;
	for(auto c: s) {
		c -= 'a';
		for(int i = 0; i < 26; i++) {
			cn[i][c] += cnt[i];
			ans = max(ans, cn[i][c]);
		}
		cnt[c]++;
		ans = max(ans, cnt[c]);
	}
	cout << ans << "\n";
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