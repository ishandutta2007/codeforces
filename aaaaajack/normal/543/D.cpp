#include<cstdio>
#include<vector>
#define N 200100
#define Q 1000000007
using namespace std;
vector<int> g[N],s[N][2],r[N][2];
int p[N],dp[N][2],ans[N];
void build(int u){
	int pre[2],v;
	pre[0]=1;
	pre[1]=1;
	for(int i=0;i<g[u].size();i++){
		s[u][0].push_back(pre[0]);
		s[u][1].push_back(pre[1]);
		v=g[u][i];
		build(v);
		pre[1]=1LL*pre[1]*(dp[v][0]+dp[v][1])%Q;
		pre[0]=1LL*pre[0]*dp[v][0]%Q;
	}
	pre[0]=1;
	pre[1]=1;
	for(int i=g[u].size()-1;i>=0;i--){
		r[u][0].push_back(pre[0]);
		r[u][1].push_back(pre[1]);
		v=g[u][i];
		pre[1]=1LL*pre[1]*(dp[v][0]+dp[v][1])%Q;
		pre[0]=1LL*pre[0]*dp[v][0]%Q;
	}
	dp[u][0]=pre[0];
	dp[u][1]=pre[1];
}
void solve(int u,int p0,int p1){
	ans[u]=1LL*dp[u][1]*(p0+p1)%Q;
	int t0,t1,j;
	for(int i=0;i<g[u].size();i++){
		j=g[u].size()-1-i;
		t0=1LL*s[u][0][i]*r[u][0][j]%Q*p0%Q;
		t1=1LL*s[u][1][i]*r[u][1][j]%Q*(p0+p1)%Q;
		solve(g[u][i],t0,t1);
	}
}
int main(){
	int n,i,u;
	scanf("%d",&n);
	for(i=2;i<=n;i++){
		scanf("%d",&p[i]);
		g[p[i]].push_back(i);
	}
	build(1);
	solve(1,1,0);
	printf("%d",dp[1][1]);
	for(i=2;i<=n;i++) printf(" %d",ans[i]);
	putchar('\n');
	return 0;
}