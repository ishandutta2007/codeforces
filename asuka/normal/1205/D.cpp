#include<bits/stdc++.h>
#define ll long long
#define N 1051
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
int n, siz[N], fa[N], dis[N], ptr[2];
bool g[N][N], from[N][N];
VI e[N], v[2];
void dfs(int u, int pa) {
	fa[u] = pa;
	siz[u] = 1;
	for(auto v : e[u]) if(v != pa) {
		dfs(v, u);
		siz[u] += siz[v];
	}
}
void getdis(int u, int pa, int p) {
	dis[u] = v[p][ptr[p]++];
	for(auto v : e[u]) if(v != pa) {
		getdis(v, u, p);
	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &n);
	rep(i, 2, n) {
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].pb(v);
		e[v].pb(u);
	}
	int need = (2 * n * n) / 9;
	rep(u, 1, n) {
		dfs(u, 0);
		int m = SZ(e[u]);
		rep(i, 1, m) rep(j, 0, n) g[i][j] = 0;
		g[0][0] = 1;
		rep(i, 1, m) {
			rep(j, 0, n) {
				if(g[i - 1][j]) g[i][j] = 1, from[i][j] = 0;
				if(j >= siz[e[u][i - 1]] && g[i - 1][j - siz[e[u][i - 1]]]) g[i][j] = 1, from[i][j] = 1;
			}
		}
		rep(j, 0, n) {
			if(!g[m][j]) continue;
			if(j * (n - j) >= need) {
				v[0].clear();
				v[1].clear();
				rep(i, 1, j) v[0].pb(i);
				rep(i, 1, n - j - 1) v[1].pb(i * j);
				int x = m, y = j;
				VI vec[2];
				while(x > 0) {
					if(from[x][y]) vec[0].pb(e[u][x - 1]), y -= siz[e[u][x - 1]];
					else vec[1].pb(e[u][x - 1]);
					x--;
				}
				rep(p, 0, 1) for(auto v : vec[p]) getdis(v, u, p);
				rep(i, 1, n) if(i != u) printf("%d %d %d\n", i, fa[i], dis[i] - dis[fa[i]]);
				return 0;
			}
		}
	}
	return 0;
}