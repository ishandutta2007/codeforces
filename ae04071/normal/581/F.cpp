#include <bits/stdc++.h>
using namespace std;

const int inf=1e9;

int n,r=-1;
vector<int> adj[5001];
int dp[5001][2][5001],sz[5001];

int tmp[2][5001];

int merge(int a,int b,int as,int bs) {
	for(int i=0;i<=as+bs;i++) tmp[0][i] = tmp[1][i] = inf;
	for(int i=0;i<=as;i++) for(int j=0;j<=bs;j++) {
		tmp[0][i+j] = min({tmp[0][i+j], dp[a][0][i]+dp[b][0][j],dp[a][0][i]+dp[b][1][j]+1});
		tmp[1][i+j] = min({tmp[1][i+j], dp[a][1][i]+dp[b][0][j]+1,dp[a][1][i]+dp[b][1][j]});
	}
	for(int i=0;i<=as+bs;i++) 
		dp[a][0][i] = tmp[0][i], dp[a][1][i] = tmp[1][i];
	return as+bs;
}
void dfs(int cur,int p) {
	for(int i=0;i<=n;i++) dp[cur][0][i] = dp[cur][1][i] = inf;
	if((int)adj[cur].size()==1) {
		sz[cur]=1;
		dp[cur][0][1]=0;
		dp[cur][1][0]=0;
		return;
	}
	dp[cur][0][0] = dp[cur][1][0] = 0;
	for(auto &it:adj[cur]) if(it!=p) {
		dfs(it,cur);
		sz[cur] = merge(cur,it,sz[cur],sz[it]);
	}
}

int main() {
	scanf("%d",&n);
	for(int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	if(n<=2) {
		puts("1");
		return 0;
	}

	for(int i=1;i<=n;i++) if(adj[i].size()>1) {
		r=i;
		break;
	}

	dfs(r,0);

	printf("%d\n",min(dp[r][0][sz[r]/2],dp[r][1][sz[r]/2]));

	return 0;
}