#include<bits/stdc++.h>
#define N 200100
using namespace std;
vector<int> g[N];
int dp[N][2];
bool vis[N];
void DFS(int u){
	vis[u]=true;
	int m[2]={0};
	int tt=0;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(vis[v]) continue;
		DFS(v);
		if(dp[v][0]-dp[v][1]>m[0]){
			m[1]=m[0];
			m[0]=dp[v][0]-dp[v][1];
		}
		else if(dp[v][0]-dp[v][1]>m[1]){
			m[1]=dp[v][0]-dp[v][1];
		}
		tt+=dp[v][0];
	}
	dp[u][0]=tt+1-m[0]-m[1];
	dp[u][1]=tt-m[0];
}
int main(){
	int n,x,y,a,b;
	scanf("%d%d%d",&n,&x,&y);
	for(int i=1;i<n;i++){
		scanf("%d%d",&a,&b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	if(x>y){
		bool star=false;
		for(int i=1;i<=n;i++){
			if(g[i].size()==n-1){
				star=true;
				break;
			}
		}
		if(star) printf("%I64d\n",1LL*y*(n-2)+x);
		else printf("%I64d\n",1LL*y*(n-1));
	}
	else{
		DFS(1);
		printf("%I64d\n",1LL*x*(n-dp[1][0])+1LL*y*(dp[1][0]-1));
	}
	return 0;
}