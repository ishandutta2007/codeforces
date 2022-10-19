#include<bits/stdc++.h>
#define ll long long
#define N 55
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
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
int n,s,m,siz[N],deg[N];
int dp[N<<1][N][N];
struct edge{
	int to,nxt,w;
	edge(){};
	edge(int a,int b,int c){to = a;nxt = b;w = c;}
};
int tot = 1;
edge e[N<<1];
int head[N];
void add(int u,int v,int w){
	e[++tot] = edge(v,head[u],w); head[u] = tot;
	e[++tot] = edge(u,head[v],w); head[v] = tot;
}
void dfs(int u,int fa){
	for(int i = head[u]; ~i; i = e[i].nxt){
		int v = e[i].to;
		if(v == fa) continue;
		dfs(v,u);
		siz[u] += siz[v];
	}
}
int solve(int from,int in,int out){
	int u = e[from].to;
	if(in == 0 && out == 0) return dp[from][in][out] = 0;
	if(~dp[from][in][out]) return dp[from][in][out];
	if(deg[u] == 1){
		if(out == 0) return dp[from][in][out] = 0;
		return dp[from][in][out] = solve(from^1,out,0)+e[from].w;
	}
	int g[N]; 
	memset(g,0,sizeof g);
	g[0] = inf;
	for(int i = head[u]; ~i; i = e[i].nxt){
		if(i == (from^1)) continue;
		per(j,1,in) rep(k,1,j){
			g[j] = max(g[j],min(g[j-k],solve(i,k,in+out-k)+e[i].w));
		}
	}
	return dp[from][in][out] = g[in];
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d",&n);
	memset(head,-1,sizeof head);
	memset(dp,-1,sizeof dp);
	rep(i,2,n){
		int u,v,w; scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
		deg[u] ++; deg[v] ++;
	}
	scanf("%d%d",&s,&m);
	rep(i,1,m){
		int u; scanf("%d",&u);
		siz[u]++;
	}
	dfs(s,0);
	// puts("OK");
	int ans = inf;
	for(int i = head[s]; ~i; i = e[i].nxt){
		int v = e[i].to;
		ans = min(ans,solve(i,siz[v],m-siz[v]) + e[i].w);
	}
	printf("%d\n",ans);
	return 0;
}