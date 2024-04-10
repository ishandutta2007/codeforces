#include<bits/stdc++.h>
#define N 100100
#define all(x) begin(x),end(x)
using namespace std;
int dp[N][2][2];
int ans=0;
//first dimension: root not chosen/root chosen
//second dimension: root outside/root in the middle
vector<int> g[N];
void solve(int u,int p){
	vector<int> vc[2][2];
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(v!=p){
			solve(v,u);
			for(int j=0;j<2;j++){
				for(int k=0;k<2;k++){
					vc[j][k].push_back(dp[v][j][k]);
				}
			}
		}
	}
	for(int j=0;j<2;j++){
		for(int k=0;k<2;k++){
			sort(all(vc[j][k]),greater<int>());
		}
	}
	for(int j=0;j<2;j++){
		for(int k=0;k<2;k++){
			dp[u][j][k]=j;
			for(int l=0;l<=k && l<vc[j^1][0].size();l++){
				dp[u][j][k]+=vc[j^1][0][l];
			}
		}
	}
	for(int j=0;j<2;j++){
		if(vc[0][j].size()> j+1 ) dp[u][0][j]+=vc[0][j].size()-(j+1);
	}
	if(p){
		dp[u][0][1]++;
	}
	for(int j=0;j<2;j++){
		for(int k=0;k<2;k++){
			dp[u][j][k]=max(dp[u][j][0],dp[u][j][k]);
			dp[u][j][k]=max(dp[u][0][k],dp[u][j][k]);
		}
	}
	ans=max(ans,dp[u][1][1]);
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	solve(1,0);
	printf("%d\n",ans);
	return 0;
}