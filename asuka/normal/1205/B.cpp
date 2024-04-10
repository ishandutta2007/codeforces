#include<bits/stdc++.h>
#define ll long long
#define N 155
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
int _n, n, g[N][N], f[N][N];
ll a[114514];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &_n);
	rep(i, 1, _n) {
		ll x;
		scanf("%lld", &x);
		if(x > 0) a[++n] = x;
	}
	if(n > 120) printf("%d\n", 3);
	else {
		memset(g, 0x3f, sizeof g);
		memset(f, 0x3f, sizeof f);
		int ans = inf;
		rep(i, 1, n) rep(j, i + 1, n) {
			if(a[i] & a[j]) g[i][j] = g[j][i] = f[i][j] = f[j][i] = 1;
		}
		rep(k, 1, n) {
			rep(i, 1, k - 1) rep(j, i + 1, k - 1) {
				if(f[i][j] == inf) continue;
				ans = min(ans, f[i][j] + g[i][k] + g[k][j]);
			}
			rep(i, 1, n) rep(j, 1, n) {
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
		printf("%d\n", ans == inf ? -1 : ans);
	}
	return 0;
}