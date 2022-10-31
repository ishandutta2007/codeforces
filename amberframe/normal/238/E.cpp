#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string.h>
#include <vector>

using namespace std;
typedef long long LL;
#define pb push_back
const int maxn = 105;
const int inf = 1<<29;
int dis[maxn][maxn];
int s[maxn],t[maxn];
int a,b,n,m,p,f[maxn],g[maxn];
vector<int> juc[maxn][maxn];
bool judge(int u,int v,int w) {
	return dis[u][v]==dis[u][w]+dis[w][v];
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("meeting.in","r",stdin);
		freopen("meeting.out","w",stdout);
	#endif
	scanf("%d %d %d %d",&n,&m,&a,&b);
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
		dis[i][j]=i!=j?inf:0;
	for (int i=1;i<=n;i++)
		f[i]=i!=b?inf:0;
	for (int u,v,i=1;i<=m;i++)
		scanf("%d %d",&u,&v),dis[u][v]=1;
	scanf("%d",&p);
	for (int i=1;i<=p;i++) 
		scanf("%d %d",&s[i],&t[i]);
		
	for (int k=1;k<=n;k++)
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
		dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		
	for (int j=1;j<=p;j++) {
		if (dis[s[j]][t[j]]>=inf) continue;
		for (int k=1;k<=n;k++)
		if (judge(s[j],t[j],k))
			juc[j][dis[s[j]][k]].pb(k);
	}
	
	for (int r=1;r<=n;r++)
	for (int j=1;j<=p;j++) {
		if (dis[s[j]][t[j]]>=inf) continue;
		int _dis=dis[s[j]][t[j]];
		for (int i=1;i<=n;i++) g[i]=f[i];
		for (int d=_dis-1;d>=0;d--) 
		for (int k=0;k<juc[j][d].size();k++) {
			int u=juc[j][d][k],tmp=0;
			for (int i=1;i<=n;i++)
			if (judge(u,t[j],i)&&dis[u][i]==1) 
				tmp=max(tmp,g[i]);
			g[u]=min(g[u],tmp);
			if (juc[j][d].size()<2)
				f[u]=min(f[u],g[u]+1);
		}
	}
	if (f[a]!=inf) printf("%d\n",f[a]);
	else puts("-1");
	return 0;
}