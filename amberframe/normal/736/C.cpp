#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;
typedef long long LL;
const int maxn = 105;
const int maxk = 25;
const int mod = 1e9+7;

int f[maxn][maxk][maxk];
int g[maxk][maxk];
int ehead[maxn],ecnt;
struct edge{
	int u,v,next;
}edg[maxn*2];
int n,K,ans;
void add(int u,int v) {
	edg[++ecnt]=(edge){u,v,ehead[u]};
	ehead[u]=ecnt;
	edg[++ecnt]=(edge){v,u,ehead[v]};
	ehead[v]=ecnt;
}

void dfs(int u,int fa) {
	f[u][0][0]=f[u][K+1][1]=1ll;
	for (int v,j=ehead[u];j;j=edg[j].next)
	if ((v=edg[j].v)!=fa) {
		dfs(v,u);
		for (int j=0;j<=K+1;j++)
		for (int k=0;k<=K+1;k++)
			g[j][k]=f[u][j][k],f[u][j][k]=0;
		for (int j=0;j<=K+1;j++)
		for (int k=0;k<=K+1;k++) {
			for (int p=0;p<=K+1;p++)
			for (int q=0;q<=K+1;q++)
				(f[u][min(j,p+1)][max(k,q?q+1:0)]+=(LL)g[j][k]*f[v][p][q]%mod)%=mod;
		}
	}
	for (int j=0;j<=K+1;j++)
	for (int k=1;k<=K+1;k++)
	if (j+k-1<=K) (f[u][j][0]+=f[u][j][k])%=mod,f[u][j][k]=0;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("tree.in","r",stdin);
		freopen("tree.out","w",stdout);
	#endif
	scanf("%d %d",&n,&K);
	for (int u,v,i=1;i<n;i++)
		scanf("%d %d",&u,&v),add(u,v);
	dfs(1,0);
	for (int j=0;j<=K+1;j++)
	for (int k=0;k<=K+1;k++)
	if (j+k<=K) (ans+=f[1][j][k])%=mod;
	printf("%d",ans);
	return 0;
}