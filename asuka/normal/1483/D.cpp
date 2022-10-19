#include<bits/stdc++.h>
#define int long long
#define N 605
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
int n,m,q;
int dp[N][N],f[N][N];
struct edge{
	int u,v,w;
	edge(){}
	edge(int a,int b,int c){u = a;v = b;w = c;}
}e[N*N];
vector<pii> g[N];
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%lld%lld",&n,&m);
	memset(dp,0x3f,sizeof dp);
	rep(i,1,n) dp[i][i] = 0;
	rep(i,1,m){
		int u,v,w; scanf("%lld%lld%lld",&u,&v,&w);
		e[i] = edge(u,v,w);
		dp[u][v] = dp[v][u] = w;
	}
	rep(i,1,n){
		rep(j,1,n){
			rep(k,1,n){
				dp[j][k] = min(dp[j][k],dp[j][i]+dp[i][k]);
			}
		}
	}
	scanf("%lld",&q);
	rep(i,1,q){
		int l,s,t; scanf("%lld%lld%lld",&s,&t,&l);
		g[s].pb(mp(t,l));
		g[t].pb(mp(s,l));
	}
	rep(u,1,n){
		rep(t,1,n){
			for(auto V:g[t]){
				int s = V.fi,l = V.se;
				f[u][t] = max(f[u][t],l-dp[s][u]);
			}
		}
	}
	int ans = 0;
	rep(i,1,m){
		int u = e[i].u,v = e[i].v,w = e[i].w;
		rep(t,1,n){
			if(dp[v][t] + w <= f[u][t] || dp[u][t] + w <= f[v][t]) {
				ans++; break;
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}