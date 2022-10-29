#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
const int N=200005;
struct node
{
	int h;
	ll d;
}t,p1[N],p2[N];
bool operator <(node a,node b)
{
	return a.d>b.d;
}
priority_queue<node> q;
int n,m,a[N],i,j,k,x,head[N],adj[N],nxt[N],len[N],id1[N],id2[N],st,ed;
ll dis[N],f[2005][2005][2],s,sum1[2005][2005],sum2[2005][2005],mx1[2005][2005],mx2[2005][2005];
bool v[N];
bool cmp(node a,node b)
{
	return a.d<b.d;
}
int main()
{
	scanf("%d%d",&n,&m);
	scanf("%d%d",&st,&ed);
	for(i=1;i<=n;++i)
		scanf("%d",a+i);
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
	for(i=1;i<=n;++i)
		dis[i]=1ll<<60,v[i]=false;
	dis[st]=0;
	q.push((node){st,0});
	while(!q.empty())
	{
		t=q.top();
		q.pop();
		if(v[t.h])
			continue;
		v[t.h]=true;
		for(i=head[t.h];i;i=nxt[i])
			if(t.d+len[i]<dis[adj[i]])
			{
				dis[adj[i]]=t.d+len[i];
				q.push((node){adj[i],dis[adj[i]]});
			}
	}
	for(i=1;i<=n;++i)
		p1[i]=(node){i,dis[i]};
	for(i=1;i<=n;++i)
		dis[i]=1ll<<60,v[i]=false;
	dis[ed]=0;
	q.push((node){ed,0});
	while(!q.empty())
	{
		t=q.top();
		q.pop();
		if(v[t.h])
			continue;
		v[t.h]=true;
		for(i=head[t.h];i;i=nxt[i])
			if(t.d+len[i]<dis[adj[i]])
			{
				dis[adj[i]]=t.d+len[i];
				q.push((node){adj[i],dis[adj[i]]});
			}
	}
	for(i=1;i<=n;++i)
		p2[i]=(node){i,dis[i]};
	sort(p1+1,p1+1+n,cmp);
	sort(p2+1,p2+1+n,cmp);
	for(i=1;i<=n;++i)
		id1[p1[i].h]=i,id2[p2[i].h]=i;
	for(i=0;i<=n;++i)
		for(j=1;j<=n;++j)
		{
			sum1[i][j]=sum1[i][j-1]+(id2[p1[j].h]>i?a[p1[j].h]:0);
			sum2[i][j]=sum2[i][j-1]+(id1[p2[j].h]>i?a[p2[j].h]:0);
		}
	for(i=0;i<=n+1;++i)
		for(j=0;j<=n+1;++j)
			mx1[i][j]=mx2[i][j]=-(1ll<<60);
	for(i=0;i<n;++i)
		for(j=0;j<n;++j)
			f[i][j][0]=f[i][j][1]=-(1ll<<60);
	i=n;
	for(j=0;j<=n;++j)
		mx1[i][j]=max(mx1[i+1][j],-f[i][j][1]+sum1[j][i]),mx2[i][j]=max(mx2[i][j+1],-f[i][j][0]+sum2[i][j]);
	j=n;
	for(i=0;i<=n;++i)
		mx1[i][j]=max(mx1[i+1][j],-f[i][j][1]+sum1[j][i]),mx2[i][j]=max(mx2[i][j+1],-f[i][j][0]+sum2[i][j]);
	for(i=n-1;i>=0;--i)
		for(j=n-1;j>=0;--j)
		{
			if(id2[p1[i+1].h]<=j)
			{
				f[i][j][0]=f[i+1][j][0],f[i][j][1]=f[i+1][j][1];
				mx1[i][j]=max(mx1[i+1][j],-f[i][j][1]+sum1[j][i]),mx2[i][j]=max(mx2[i][j+1],-f[i][j][0]+sum2[i][j]);
				continue;
			}
			if(id1[p2[j+1].h]<=i)
			{
				f[i][j][0]=f[i][j+1][0],f[i][j][1]=f[i][j+1][1];
				mx1[i][j]=max(mx1[i+1][j],-f[i][j][1]+sum1[j][i]),mx2[i][j]=max(mx2[i][j+1],-f[i][j][0]+sum2[i][j]);
				continue;
			}
			//for(k=i+1;k<=n;++k)
				//f[i][j][0]=max(f[i][j][0],-f[k][j][1]+sum1[j][k]);
			//printf("%d %d %lld %lld\n",i+1,j,f[i][j][0],mx1[i+1][j]);
			f[i][j][0]=mx1[i+1][j];
			f[i][j][0]-=sum1[j][i];
			//for(k=j+1;k<=n;++k)
				//f[i][j][1]=max(f[i][j][1],-f[i][k][0]+sum2[i][k]);
			//printf("%lld %lld\n",f[i][j][1],mx2[i][j+1]);
			f[i][j][1]=mx2[i][j+1];
			f[i][j][1]-=sum2[i][j];
			mx1[i][j]=max(mx1[i+1][j],-f[i][j][1]+sum1[j][i]),mx2[i][j]=max(mx2[i][j+1],-f[i][j][0]+sum2[i][j]);
			//printf("%d %d %lld %lld\n",i,j,f[i][j][0],f[i][j][1]);
		}
	if(f[0][0][0]>0)
		printf("Break a heart");
	else if(f[0][0][0]==0)
		printf("Flowers");
	else
		printf("Cry");
	return 0;
}