#include<bits/stdc++.h>
#define N 3010
using namespace std;
int e[N],x[N],y[N];
long long add[N][N];
int to[N][N];
long long dp[N][N];
vector<int> g[N];
vector<int> bg[N][N];
int sz[N][N];
void DFS(int u,int fr,int lv){
	sz[lv][u]=1;
	int res=0;
	for(int i=0;i<g[u].size();i++){
		int j=g[u][i];
		if(j==fr) continue;
		int v=u^e[j];
		bg[lv][u].push_back(v);
		DFS(v,j,lv);
		sz[lv][u]+=sz[lv][v];
	}
}
long long solve(int u,int v){
	if(dp[u][v]||dp[v][u]) return max(dp[u][v],dp[v][u]);
	dp[u][v]=sz[u][v]*sz[v][u];
	long long mx=0;
	for(int i=0;i<bg[v][u].size();i++){
		mx=max(mx,solve(bg[v][u][i],v));
	}
	for(int i=0;i<bg[u][v].size();i++){
		mx=max(mx,solve(bg[u][v][i],u));
	}
	dp[u][v]+=mx;
	return dp[u][v];
}
int main(){
	int n;
	long long ans=0;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d%d",&x[i],&y[i]);
		g[x[i]].push_back(i);
		g[y[i]].push_back(i);
		e[i]=x[i]^y[i];
	}
	for(int i=1;i<n;i++){
		DFS(x[i],i,y[i]);
		DFS(y[i],i,x[i]);
	}
	for(int i=1;i<n;i++){
		ans=max(ans,solve(x[i],y[i]));
	}
	printf("%lld\n",ans);
	return 0;
}