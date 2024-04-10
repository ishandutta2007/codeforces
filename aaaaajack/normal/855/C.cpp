#include<bits/stdc++.h>
#define N 100100
#define Q 1000000007
using namespace std;
int dp[N][3][11];
//s: s+m+l, m: s, l:s+l
vector<int> g[N];
void DFS(int u,int p,int h,int m,int k){
	long long tmp[2][3][11]={};
	int fl=0;
	tmp[0][0][0]=k-1;
	tmp[0][1][1]=1;
	tmp[0][2][0]=m-k;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(v==p) continue;
		fl^=1;
		DFS(v,u,h,m,k);
		for(int j=0;j<3;j++){
			for(int a=0;a<=h;a++){
				tmp[fl][j][a]=0;
				for(int b=0;b<=a;b++){
					tmp[fl][j][a]+=1LL*dp[v][j][b]*tmp[fl^1][j][a-b]%Q;
				}
				tmp[fl][j][a]%=Q;
			}
		}
	}
	for(int j=0;j<=h;j++){
		
		dp[u][1][j]=tmp[fl][0][j];
		dp[u][2][j]=(dp[u][1][j]+tmp[fl][2][j])%Q;
		dp[u][0][j]=(dp[u][2][j]+tmp[fl][1][j])%Q;
	}
	//printf("%d: %d %d %d %d %d %d\n",u,dp[u][0][0],dp[u][1][0],dp[u][2][0],dp[u][0][1],dp[u][1][1],dp[u][2][1]);
}
int main(){
	int n,m,x,y,k,h;
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	scanf("%d%d",&k,&h);
	DFS(1,-1,h,m,k);
	int ans=0;
	for(int j=0;j<=h;j++){
		ans+=dp[1][0][j];
		ans%=Q;
	}
	printf("%d\n",ans);
	return 0;
}