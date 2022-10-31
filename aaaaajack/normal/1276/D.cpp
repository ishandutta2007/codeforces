#include<bits/stdc++.h>
#define N 200100
const int Q=998244353;
using namespace std;
vector<int> g[N];
int dp[N][3];
int e[N];
void solve(int u,int p){
	for(int i=0;i<g[u].size();i++){
		int v=u^e[g[u][i]];
		if(v==p) continue;
		solve(v,u);
	}
	vector<int> suf;
	suf.push_back(1);
	for(int i=(int)g[u].size()-1;i>=0;i--){
		int v=u^e[g[u][i]],tmp=suf.back();
		if(v!=p) tmp=1LL*tmp*(dp[v][0]+dp[v][1])%Q;
		suf.push_back(tmp);
	}
	reverse(suf.begin(),suf.end());
	int c=0;//out
	int pre=1;
	for(int i=0;i<g[u].size();i++){
		int v=u^e[g[u][i]];
		if(v!=p) dp[u][c]=(dp[u][c]+1LL*pre*dp[v][1]%Q*suf[i+1]%Q)%Q;
		else dp[u][2]=1LL*pre*suf[i+1]%Q;
		if(v!=p) pre=1LL*pre*(dp[v][0]+dp[v][2])%Q;
		else c=1;
	}
	dp[u][c]=(dp[u][c]+pre)%Q;
}
int main(){
	int n,x,y;
	scanf("%d",&n);
	for(int i=0;i<n-1;i++){
		scanf("%d%d",&x,&y);
		e[i]=x^y;
		g[x].push_back(i);
		g[y].push_back(i);
	}
	solve(1,0);
	printf("%d\n",dp[1][0]);
	return 0;
}