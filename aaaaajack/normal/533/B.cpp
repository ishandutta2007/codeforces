#include<cstdio>
#include<vector>
#define N 200100
using namespace std;
int w[N];
long long dp[N][2];
vector<int> g[N];
void DFS(int u){
	if(g[u].empty()){
		dp[u][0]=0;
		dp[u][1]=w[u];
	}
	else{
		long long t[2];
		DFS(g[u][0]);
		dp[u][0]=dp[g[u][0]][0];
		dp[u][1]=dp[g[u][0]][1];
		for(int i=1;i<g[u].size();i++){
			DFS(g[u][i]);
			t[0]=max(dp[u][0]+dp[g[u][i]][0],dp[u][1]+dp[g[u][i]][1]);
			t[1]=max(dp[u][0]+dp[g[u][i]][1],dp[u][1]+dp[g[u][i]][0]);
			dp[u][0]=t[0];
			dp[u][1]=t[1];
		}
		dp[u][1]=max(dp[u][1],dp[u][0]+w[u]);
	}
}
int main(){
	int r,p,n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&p,&w[i]);
		if(p==-1) r=i;
		else g[p].push_back(i);
	}
	DFS(r);
	printf("%I64d\n",max(dp[r][0],dp[r][1]));
	return 0;
}