#include<bits/stdc++.h>
#define int long long
#define N 505
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
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
int f[N][N], n, ans;
int a[N];
const int mod = 998244353;
signed main() {
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%lld", &n);
	rep(i, 1, n) {
		char s[3];
		scanf("%s", s + 1);
		if (s[1] == '+') scanf("%lld", &a[i]);
		else a[i] = -1;
	}
	rep(i, 1, n) {
		if (a[i] == -1) continue;
		memset(f, 0, sizeof f);
		f[0][0] = 1;
		rep(j, 1, n) {
			if (j == i) {
				rep(k, 0, n) f[j][k] = f[j - 1][k];
				continue;
			}
			// printf("j %lld\n",j);
			rep(k, 0, n) {
				if (a[j] == -1) {
					if (k == 0) f[j][k] = ((j < i ? f[j - 1][k] : 0) + f[j - 1][k] + f[j - 1][k + 1])% mod;
					else f[j][k] = (f[j - 1][k] + f[j - 1][k + 1]) % mod;
				} else {
					if (a[j] < a[i] || (j > i && a[i] == a[j])) f[j][k] = (f[j - 1][k] + (k > 0 ? f[j - 1][k - 1] : 0)) % mod;
					else f[j][k] = (f[j - 1][k] + f[j - 1][k]) % mod;
				}
				// printf("%lld ",f[j][k]);
			}
			// printf("\n");
		}
		rep(k, 0, n) ans = (ans + f[n][k] * a[i] % mod ) % mod;
	}
	printf("%lld\n", ans);
	return 0;
}