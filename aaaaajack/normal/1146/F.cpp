#include<bits/stdc++.h>
#define N 200100
#define Q 998244353
using namespace std;
int dp[N][3];
//0: root not used
//1: root not used but assigned
//2: root used
vector<int> g[N];
void solve(int u){
	if(g[u].empty()){
		dp[u][2]=1;
		dp[u][0]=dp[u][1]=0;
		return;
	}
	dp[u][0]=1;
	dp[u][1]=dp[u][2]=0;
	for(auto v:g[u]){
		solve(v);
		int con=(dp[v][1]+dp[v][2])%Q,ncon=(dp[v][0]+dp[v][2])%Q;
		int nxt[3];
		nxt[0]=1LL*dp[u][0]*ncon%Q;
		nxt[1]=(1LL*dp[u][1]*ncon+1LL*dp[u][0]*con)%Q;
		nxt[2]=(1LL*dp[u][1]*con+1LL*dp[u][2]*(con+ncon))%Q;
		for(int i=0;i<3;i++) dp[u][i]=nxt[i];
	}
}
int main(){
	int n,x;
	scanf("%d",&n);
	for(int i=2;i<=n;i++){
		scanf("%d",&x);
		g[x].push_back(i);
	}
	solve(1);
	printf("%d\n",(dp[1][0]+dp[1][2])%Q);
	return 0;
}