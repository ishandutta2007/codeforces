#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=1000+10;
const int M=2000+10;

int n,m,s,t,ans;
int d[N],dd[N];
int fir[N],nxt[M],to[M],tote;
int G[N][N];
queue<int> Q;

int main()
{
	scanf("%d%d%d%d",&n,&m,&s,&t);
	int i,j,u,v;
	for(i=1;i<=m;++i)
	{
		scanf("%d%d",&u,&v);
		to[++tote]=v;nxt[tote]=fir[u];fir[u]=tote;
		to[++tote]=u;nxt[tote]=fir[v];fir[v]=tote;
		G[u][v]=G[v][u]=true;
	}
	Q.push(s);d[s]=1;
	while(!Q.empty())
	{
		u=Q.front();Q.pop();
		for(i=fir[u];i;i=nxt[i])
		{
			v=to[i];
			if(!d[v])
			{
				d[v]=d[u]+1;
				Q.push(v);
			}
		}
	}
	Q.push(t);dd[t]=1;
	while(!Q.empty())
	{
		u=Q.front();Q.pop();
		for(i=fir[u];i;i=nxt[i])
		{
			v=to[i];
			if(!dd[v])
			{
				dd[v]=dd[u]+1;
				Q.push(v);
			}
		}
	}
	for(i=1;i<=n;++i)
		for(j=i+1;j<=n;++j)if(!G[i][j]&&d[i]+dd[j]>=d[t]&&dd[i]+d[j]>=d[t])
			++ans;
	printf("%d",ans);
	return 0;
}