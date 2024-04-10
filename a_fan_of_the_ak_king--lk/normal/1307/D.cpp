#include<bits/stdc++.h>
using namespace std;
const int N=200005,M=1000000007;
typedef long double lb;
int n,m,p,q[N],head[N],Next[N*2],adj[N*2],d[N],d2[N],vis[N],i,ans,mx,k,j,a[N],u,v;
void Push(int u,int v)
{
	Next[++k]=head[u];
	head[u]=k;
	adj[k]=v;
}
void BFS(int s)
{
	int i,r,j;
	q[r=1]=s;
	memset(d,-1,sizeof(d));
	d[s]=0;
	for(i=1;i<=r;++i)
		for(j=head[q[i]];j!=0;j=Next[j])
			if(d[adj[j]]==-1)
			{
				d[adj[j]]=d[q[i]]+1;
				q[++r]=adj[j];
			}
}
bool cmp(int a,int b)
{
	return d[a]<d[b];
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d %d %d",&n,&m,&p);
	for(i=1;i<=p;++i)
		scanf("%d",&a[i]);
	for(i=1;i<=m;++i)
	{
		scanf("%d %d",&u,&v);
		Push(u,v);
		Push(v,u);
	}
	BFS(1);
	for(i=1;i<=n;++i)
		d2[i]=d[i];
	BFS(n);
	sort(a+1,a+1+p,cmp);
	mx=-100000000;
	for(i=p;i>=1;--i)
	{
		ans=max(ans,mx+d[a[i]]+1);
		mx=max(mx,d2[a[i]]);
	}
	cout<<min(ans,d2[n]);
}