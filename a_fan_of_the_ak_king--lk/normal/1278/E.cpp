#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long LL;
typedef long double lb;
#define ri register int
const lb PI=3.141592653589793238462643383279;
const ll inf=1000000000000000000ll;
const int N=500005,M=998244353;
int n,m,i,u,v,head[N],Next[N*2],adj[N*2],a[N*2],k,l[N],r[N];
void Push(int u,int v)
{
	Next[++k]=head[u];
	head[u]=k;
	adj[k]=v;
}
void dfs(int i,int fa)
{
	int j,m=0;
	for(j=head[i];j!=0;j=Next[j])
		if(adj[j]!=fa)
		{
			a[++k]=adj[j];
			++m;
		}
	a[++k]=i;
	int p[m+2];
	m=0;
	for(j=head[i];j!=0;j=Next[j])
		if(adj[j]!=fa)
			p[++m]=adj[j];
	for(j=m;j>=1;--j)
		dfs(p[j],i);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&n);
	for(i=1;i<n;++i)
	{
		scanf("%d %d",&u,&v);
		Push(u,v);
		Push(v,u);
	}
	k=1;
	a[k]=1;
	dfs(1,0);
	for(i=1;i<=k;++i)
		if(l[a[i]])
			r[a[i]]=i;
		else
			l[a[i]]=i;
	for(i=1;i<=n;++i)
		printf("%d %d\n",l[i],r[i]);
}