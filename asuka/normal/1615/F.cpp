#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
const int N = 2015, sft = 2000, mod = 1e9 + 7;
int T, n;
pii dp[N][N << 1];
char s[N], t[N];
int main() {
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	for(scanf("%d", &T); T; T--) {
		scanf("%d", &n);
		scanf("%s%s", s + 1, t + 1);
		rep(i, 1, n) if(i & 1 && s[i] != '?') s[i] = !(s[i] - '0') + '0';
		rep(i, 1, n) if(i & 1 && t[i] != '?') t[i] = !(t[i] - '0') + '0';
		rep(i, 0, n) rep(j, -i, i) dp[i][j + sft] = mp(0, 0);
		dp[0][0 + sft] = mp(0, 1);
		rep(i, 1, n) rep(j, -i, i) {
			rep(p, 0, 1) if(s[i] == '?' || s[i] - '0' == p) rep(q, 0, 1) if(t[i] == '?' || t[i] - '0' == q) {
				(dp[i][j + p - q + sft].fi += ((ll) dp[i - 1][j + sft].se * abs(j + p - q) % mod + dp[i - 1][j + sft].fi) % mod) %= mod;
				(dp[i][j + p - q + sft].se += dp[i - 1][j + sft].se) %= mod;
			}
		}
		printf("%d\n", dp[n][0 + sft].fi);
	}
	return 0;
}