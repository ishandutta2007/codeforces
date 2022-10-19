#include<bits/stdc++.h>
using namespace std;
int a[300005],b[300005],s[300005],mn[1200005];
int q[300005],dist[300005],lst[300005],L[300005],head,tail;
vector<int>g[300005];
void build(int l,int r,int o)
{
	if(l==r)
	{
		mn[o]=s[l];
		return;
	}
	int mid=l+r>>1;
	build(l,mid,o<<1);
	build(mid+1,r,o<<1|1);
	mn[o]=min(mn[o<<1],mn[o<<1|1]);
}
void add(int l,int r,int o,int u,int v)
{
	if(l==r)
	{
		mn[o]=v;
		return;
	}
	int mid=l+r>>1;
	if(u<=mid)add(l,mid,o<<1,u,v);
	else add(mid+1,r,o<<1|1,u,v);
	mn[o]=min(mn[o<<1],mn[o<<1|1]);
}
void query(int l,int r,int o,int ll,int rr,int p,int x)
{
	if(mn[o]>p)return;
	if(l==r)
	{
		mn[o]=INT_MAX;
		lst[l]=x,L[l]=p,q[++tail]=l,dist[l]=dist[x]+1;
		return;
	}
	int mid=l+r>>1;
	if(mid>=ll&&mn[o<<1]<=p)query(l,mid,o<<1,ll,rr,p,x);
	if(mid<rr&&mn[o<<1|1]<=p)query(mid+1,r,o<<1|1,ll,rr,p,x);
	mn[o]=min(mn[o<<1],mn[o<<1|1]);
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	for(int i=1;i<=n;i++)
	{
		s[i]=max(0,i-a[i]);
		int c=min(n,i+b[i]);
		g[c].push_back(i);
	}
	g[0].push_back(0);
	build(1,n,1);
	memset(dist,63,sizeof(dist));
	head=0,tail=-1;
	dist[0]=0,q[++tail]=0;
	while(head<=tail)
	{
		int x=q[head++];
		for(int i=0;i<g[x].size();i++)
		{
			int p=g[x][i];
			query(1,n,1,max(1,p),n,p,x);
		}
	}
	if(dist[n]>1e9)printf("-1\n");
	else
	{
		printf("%d\n",dist[n]);
		int x=n;
		while(x)
		{
			printf("%d ",L[x]);
			x=lst[x];
		}
	}
	return 0;
}