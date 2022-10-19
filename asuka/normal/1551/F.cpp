#include<bits/stdc++.h>
#define ll long long
#define N 115
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
const int mod = 1e9 + 7;
int T, n, m, dep[N], siz[N][N], f[N], g[N];
VI e[N];
void dfs(int u, int fa) {
	rep(i, 0, n) siz[u][i] = 0;
	dep[u] = dep[fa] + 1;
	siz[u][dep[u]] = 1;
	for(auto v : e[u]) if(v != fa){
		dfs(v, u);
		rep(i, 0, n) siz[u][i] += siz[v][i];
	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &m);
		int ans = 0;
		rep(i, 1, n) e[i].clear();
		rep(i, 2, n) {
			int u, v;
			scanf("%d%d", &u, &v);
			e[u].pb(v);
			e[v].pb(u);
		}
		if(m == 2) {
			printf("%d\n", n * (n - 1) / 2);
			continue;
		}
		rep(rt, 1, n) {
			dfs(rt, 0);
			// printf("RT %d\n", rt);
			
			rep(d, 1, n) {
				rep(i, 0, n) f[i] = 0;
				f[0] = 1;
				// printf("D %d\n", d);
				for(auto son : e[rt]) { // (1 + kx)
					int k = siz[son][d];
					// printf("(1 + %dx)\n", k);
					rep(i, 1, n) g[i] = (ll) k * f[i - 1] % mod;
					rep(i, 1, n) f[i] = (f[i] + g[i]) % mod;
				}
				// printf("%d\n", f[m]);
				ans = (ans + f[m]) % mod;
			}
			// printf("%d %d\n", rt, f[m]);
			
		}
		printf("%d\n", ans);
	}
	return 0;
}