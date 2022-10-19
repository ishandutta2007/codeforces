#include <bits/stdc++.h>
#define MIN(x,y) x=x<y?x:y
#define bp __builtin_popcountll
#define pb push_back
#define in(s) freopen(s, "r", stdin);
#define inout(s) freopen(string(s) + ".inp", "r", stdin), freopen(string(s) + ".out", "w", stdout);
#define fi first
#define se second
#define bw(i, r, l) for (int i = r - 1; i >= l; i--)
#define fw(i, l, r) for (int i = l; i < r; i++)
#define fa(i, x) for (auto i: x)
using namespace std;
const int mod = 1e9 + 7, inf = 1061109567;
const long long infll = 4557430888798830399;
typedef pair<int, int> ii;
int d, s, dp[5005][505];
vector<int> div10[505];
signed main() {
	#ifdef BLU
	in("blu.inp");
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> d >> s;
	/*
	Store dp[i][j]: If we already have a number with sum as i and mod j, how many digits does it take
	to reach the end state. Then for finding the number is easy.
	*/
	memset(dp, 63, sizeof dp);
	dp[s][0] = 0;
	fw (i, 0, d) if (i * 10 % d != i) div10[i * 10 % d].pb(i);
	int tmp = 0;
	fw (i, 0, d) tmp += div10[i].size();
	bw (i, s + 1, 0) {
		fw (j, 0, d) fw (k, 1, 10) {
			int nxtj = (j * 10 + k) % d, nxti = i + k;
			if (nxti <= s && dp[nxti][nxtj] != inf) MIN(dp[i][j], dp[nxti][nxtj] + 1);
		}
		vector<ii> v;
		fw (j, 0, d) if (dp[i][j] != inf) v.pb(ii(dp[i][j], j));
		sort(v.begin(), v.end());
		queue<ii> q;
		fa (i, v) q.push(i);
		while (!q.empty()) {
			ii tmp = q.front(); q.pop();
			int j = tmp.se;
			if (tmp.fi != dp[i][j]) continue;
			fa (prvj, div10[j]) {
				if (dp[i][j] + 1 < dp[i][prvj]) {
					dp[i][prvj] = dp[i][j] + 1;
					q.push(ii(dp[i][prvj], prvj));
				}
			}
		}
	}
	if (dp[0][0] == inf) cout << "-1";
	else {
		int i = 0, j = 0;
		while (1) {
			if (i == s && j == 0) break;
			int nxtdig = -1, mn = inf;
			fw (k, 0, 10) if (i + k <= s) {
				if (dp[i + k][(j * 10 + k) % d] < mn) {
					mn = dp[i + k][(j * 10 + k) % d];
					nxtdig = k;
				}
			}
			cout << nxtdig;
			i += nxtdig, j = (j * 10 + nxtdig) % d;
		}
	}
	return 0;
}