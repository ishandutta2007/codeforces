#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct node
{
	int s,u,d;
}q1[10000000],q2[10000000],t;
int n,m,a,b,bg1,ed1,bg2,ed2,i,j,k,cnt,sz[1000],id[1000],p[1000],dis[300000][75],head[1000],adj[1000],nxt[1000],len[1000],bl[1000];
bool v[300000][75];
int find(int x)
{
	return !p[x]?x:p[x]=find(p[x]);
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&a,&b);
	for(i=1;i<=m;++i)
	{
		scanf("%d%d%d",&j,&k,&len[i*2]);
		adj[i*2-1]=k;
		nxt[i*2-1]=head[j];
		head[j]=i*2-1;
		adj[i*2]=j;
		nxt[i*2]=head[k];
		head[k]=i*2;
		len[i*2-1]=len[i*2];
	}
	for(i=1;i<=m;++i)
		if(len[i*2]==a&&find(adj[i*2-1])!=find(adj[i*2]))
			p[find(adj[i*2-1])]=find(adj[i*2]);
	for(i=1;i<=n;++i)
		sz[bl[i]=find(i)]++;
	for(i=1;i<=n;++i)
		if(bl[i]==i&&sz[i]>=4)
			id[i]=++cnt;
	for(i=0;i<(1<<cnt);++i)
		for(j=1;j<=n;++j)
			dis[i][j]=2147483647;
	dis[0][1]=0;
	bg1=bg2=1,ed1=ed2=0;
	q1[++ed1]=(node){0,1,0};
	while(bg1<=ed1||bg2<=ed2)
	{
		if(bg1<=ed1&&(bg2>ed2||q1[bg1].d<q2[bg2].d))
		{
			t=q1[bg1];
			++bg1;
		}
		else
		{
			t=q2[bg2];
			++bg2;
		}
		if(v[t.s][t.u])
			continue;
		v[t.s][t.u]=true;
		for(i=head[t.u];i;i=nxt[i])
			if((id[bl[adj[i]]]==0||!(t.s>>(id[bl[adj[i]]]-1)&1))&&(bl[t.u]!=bl[adj[i]]||len[i]==a)&&t.d+len[i]<dis[j=(id[bl[t.u]]&&id[bl[t.u]]!=id[bl[adj[i]]]?t.s|(1<<(id[bl[t.u]]-1)):t.s)][adj[i]])
			{
				dis[j][adj[i]]=t.d+len[i];
				if(len[i]==a)
					q1[++ed1]=(node){j,adj[i],dis[j][adj[i]]};
				else
					q2[++ed2]=(node){j,adj[i],dis[j][adj[i]]};
			}
	}
	for(i=1;i<=n;++i)
	{
		k=2147483647;
		for(j=0;j<(1<<cnt);++j)
			k=min(k,dis[j][i]);
		printf("%d ",k);
	}
	return 0;
}