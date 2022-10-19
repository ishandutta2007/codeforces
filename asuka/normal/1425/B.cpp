#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
using namespace std;
const int N = 2e3+10,M = 4e3,T = (M<<1)+5;
const int mod = 1e9+7;
int n,m,f[N][T][2],g[N][T][2],cnt,a[N];
VI e[N];
bool vis[N];
void add(int u,int v){
	e[u].pb(v); e[v].pb(u);
}
int dfs(int u){
	vis[u] = 1;
	for(auto v:e[u]){
		if(vis[v]) continue;
		return dfs(v)+1;
	}
	return 1;
}
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d",&n,&m);
	rep(i,1,m) {
		int u,v;
		scanf("%d%d",&u,&v),add(u,v);
	}
	vis[1] = 1;
	for(auto v:e[1]){
		if(!vis[v]) a[++cnt] = dfs(v)+1;
	}
	int sz = 0;
	f[0][M][0] = g[0][M][0] = 1;
	rep(i,1,cnt){
		rep(j,-sz,sz){
			f[i][j+M+a[i]][0] = (f[i][j+M+a[i]][0]+f[i-1][j+M][0])%mod;
			f[i][j+M-a[i]][0] = (f[i][j+M-a[i]][0]+f[i-1][j+M][0])%mod;
			f[i][j+M][0] = (f[i][j+M][0]+f[i-1][j+M][0])%mod;

			f[i][j+M+a[i]][1] = (f[i][j+M+a[i]][1]+f[i-1][j+M][1])%mod;
			f[i][j+M-a[i]][1] = (f[i][j+M-a[i]][1]+f[i-1][j+M][1])%mod;
			f[i][j+M][1] = (f[i][j+M][1]+f[i-1][j+M][1])%mod;

			g[i][j+M+a[i]][0] = (g[i][j+M+a[i]][0]+g[i-1][j+M][0])%mod;
			g[i][j+M-a[i]][0] = (g[i][j+M-a[i]][0]+g[i-1][j+M][0])%mod;

			g[i][j+M+a[i]][1] = (g[i][j+M+a[i]][1]+g[i-1][j+M][1])%mod;
			g[i][j+M-a[i]][1] = (g[i][j+M-a[i]][1]+g[i-1][j+M][1])%mod;

			rep(x,1,a[i]-1){
				int y = a[i]-x;
				f[i][j+M+x-y][1] = (f[i][j+M+x-y][1]+2ll*f[i-1][j+M][0])%mod;
			}
			rep(x,1,a[i]-2){
				int y = a[i]-x-1;
				f[i][j+M+x-y][1] = (f[i][j+M+x-y][1]+2ll*f[i-1][j+M][0])%mod;
			}
			g[i][j+M+(a[i]-1)][1] = (g[i][j+M+(a[i]-1)][1]+2ll*g[i-1][j+M][0])%mod;
			g[i][j+M-(a[i]-1)][1] = (g[i][j+M-(a[i]-1)][1]+2ll*g[i-1][j+M][0])%mod;
		}
		sz += a[i];
	}
	int ans = 0;
	ans = ((g[cnt][M][0]+g[cnt][M][1])%mod+f[cnt][M][1])%mod;
	printf("%d\n",ans);
	return 0;
}