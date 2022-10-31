#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;
typedef long long LL;
const int maxn = 5005;
const LL inf = 1ll<<50;

LL dp[maxn][maxn][2];
struct edge {
	int u,v,next;
}edg[maxn*2];
int ehead[maxn],ecnt,n,K,c[maxn],d[maxn],siz[maxn];
void add(int u,int v) {
	edg[++ecnt]=(edge){u,v,ehead[u]};
	ehead[u]=ecnt;
}

void upd(LL &x,LL y) {x>y?x=y:0;}
void work(int u)
{
	dp[u][0][0]=0;dp[u][1][0]=c[u];
	dp[u][1][1]=c[u]-d[u];siz[u]=1;
	for (int v,j=ehead[u];j;j=edg[j].next)
	{
		v=edg[j].v;work(v);
		for (int j=siz[u];j>=0;j--)
		for (int k=siz[v];k>=1;k--)
			upd(dp[u][j+k][0],dp[u][j][0]+dp[v][k][0]),
			upd(dp[u][j+k][1],dp[u][j][1]+dp[v][k][1]),
			upd(dp[u][j+k][1],dp[u][j][1]+dp[v][k][0]);
		siz[u]+=siz[v];
	}
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("karen.in","r",stdin);
		//freopen("karen.out","w",stdout);
	#endif
	scanf("%d %d %d %d",&n,&K,&c[1],&d[1]);
	for (int fa,i=2;i<=n;i++)
		scanf("%d %d %d",&c[i],&d[i],&fa),add(fa,i);
	memset(dp,1,sizeof dp);work(1);int ans=0;
	for (int j=1;j<=n;j++) {
		if (dp[1][j][0]<=K) ans=j;
		if (dp[1][j][1]<=K) ans=j;
	}
	printf("%d",ans);
	return 0;
}