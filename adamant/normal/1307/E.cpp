#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const int inf = 1e9;
const int mod = 1e9 + 7;

void solve() {
	int n, m;
	cin >> n >> m;
	n++;
	int s[n];
	for(int i = 1; i < n; i++) {
		cin >> s[i];
	}
	s[0] = 0;
	int f[m], h[m];
	int L[m], R[m];
	vector<pair<int, int>> cows[n];
	cows[0] = {{0, 0}};
	for(int i = 0; i < m; i++) {
		cin >> f[i] >> h[i];
		if(count(s, s + n, f[i]) < h[i]) {
			L[i] = R[i] = -1;
		} else {
			L[i] = 0;
			int cnt = 0;
			while(cnt < h[i]) {
				cnt += s[L[i]] == f[i];
				L[i]++;
			}
			cnt = 0;
			R[i] = n - 1;
			while(cnt < h[i]) {
				cnt += s[R[i]] == f[i];
				R[i]--;
			}
			L[i]--, R[i]++;
		}
		if(L[i] != -1) {
			cows[f[i]].push_back({L[i], R[i]});
		}
	}
	int ans = 1;
	int mx = 0;
	for(int i = 0; i < n; i++) {
		int dp[n + 1], cr[n + 1];
		memset(dp, 0, sizeof(dp));
		memset(cr, 0, sizeof(cr));
		dp[0] = 1;
		bool ok = false;
		for(int j = 0; j < n; j++) {
			int cnt[3][2];
			memset(cnt, 0, sizeof(cnt));
			for(auto it: cows[j]) {
				int A = it.first > i ? 0 : it.first < i ? 1 : 2;
				int B = it.second > i;
				cnt[A][B]++;
			}
			if(cnt[2][0] || cnt[2][1]) {
				if(cnt[1][1] || cnt[0][1]) {
					cr[j + 1] = cr[j] + 2;
					dp[j + 1] = dp[j] * (cnt[1][1] + cnt[0][1]) % mod;
				} else {
					cr[j + 1] = cr[j] + 1;
					dp[j + 1] = dp[j];
				}
				ok = true;
			} else if(cnt[1][1] >= 2 || 
					 (cnt[1][0] && cnt[0][1]) || 
					 (cnt[1][1] && (cnt[0][1] || cnt[1][0]))) {
				cr[j + 1] = cr[j] + 2;
				dp[j + 1] = dp[j] * ((cnt[1][1] * (cnt[1][1] - 1) % mod
				                  + cnt[1][0] * cnt[0][1] % mod
				                  + cnt[1][1] * (cnt[0][1] + cnt[1][0]) % mod) % mod) % mod;
			} else if(cnt[1][0] || cnt[0][1] || cnt[1][1]) {
				cr[j + 1] = cr[j] + 1;
				dp[j + 1] = dp[j] * (cnt[1][0] + cnt[0][1] + 2 * cnt[1][1]) % mod;
			} else {
				cr[j + 1] = cr[j];
				dp[j + 1] = dp[j];
			}
		}
		if(!ok) {
			continue;
		}
		if(cr[n] > mx) {
			mx = cr[n];
			ans = dp[n];
		} else if(cr[n] == mx) {
			ans = (ans + dp[n]) % mod;
		}
	}
	cout << mx - 1 << ' ' << ans << "\n";
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