#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

ll C[101][101];

ll solveWithLZs(int len, const vector<int> &cnt) {
	if (len == 0)
		return 1;
	int n = (int)cnt.size();
	vector<vector<ll>> dp(n + 1, vector<ll>(len + 1));
	dp[0][len] = 1;
	rep(i, n) {
		rer(j, 0, len) {
			ll x = dp[i][j];
			if (x == 0) continue;
			rer(k, 0, min(j, cnt[i]))
				dp[i + 1][j - k] += x * C[j][k];
		}
	}
	return dp[n][0];
}

ll solve(int len, vector<int> cnt) {
	if (len == 0)
		return 1;
	int n = (int)cnt.size();
	ll res = solveWithLZs(len, cnt);
	if (cnt[0] > 0) {
		--cnt[0];
		res -= solveWithLZs(len - 1, cnt);
	}
	return res;
}

int main() {
	for (int i = 0; i < (int)(sizeof(C) / sizeof(*C)); i++) {
		C[i][0] = 1;
		for (int j = 1; j <= i; j++)
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
	}
	long long k; int t;
	while (~scanf("%lld%d", &k, &t)) {
		ll remK = k - 1;
		int len = 1;
		vector<int> cur(16, t);
		for (; ; ++len) {
			ll cnt = solve(len, cur);
			if (remK < cnt)
				break;
			remK -= cnt;
		}
		string ans(len, '?');
		for (int i = len - 1; i >= 0; --i) {
			rep(d, 16) {
				if (i == len - 1 && d == 0) continue;
				if(cur[d] == 0) continue;
				--cur[d];
				ll cnt = solveWithLZs(i, cur);
				if (remK < cnt) {
					ans[len - 1 - i] = d <= 9 ? '0' + d : 'a' + (d - 10);
					break;
				}
				remK -= cnt;
				++cur[d];
			}
			assert(ans[len - 1 - i] != '?');
		}
		puts(ans.c_str());
	}
	return 0;
}