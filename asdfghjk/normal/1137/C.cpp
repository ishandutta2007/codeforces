#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=5000005;
int n,m,d,i,j,k,x,l,L,cnt,h[N],head[N],adj[2*N],nxt[2*N],rhead[N],radj[2*N],rnxt[2*N],Head[N],Adj[N],Nxt[N],col[N],c[N],w[N];
bool v[N];
char s[100];
void addedge(int u,int v)
{
	adj[++l]=v;
	nxt[l]=head[u];
	head[u]=l;
	radj[l]=u;
	rnxt[l]=rhead[v];
	rhead[v]=l;
}
void Addedge(int u,int v)
{
	Adj[++L]=v;
	Nxt[L]=Head[u];
	Head[u]=L;
}
void dfs(int x)
{
	v[x]=true;
	for(int y=head[x];y;y=nxt[y])
		if(!v[adj[y]])
			dfs(adj[y]);
	h[++j]=x;
}
void rdfs(int x)
{
	col[x]=cnt;
	for(int y=rhead[x];y;y=rnxt[y])
		if(!col[radj[y]])
			rdfs(radj[y]);
}
int work(int x)
{
	if(v[x])
		return h[x];
	int rtn=0;
	for(int y=Head[x];y;y=Nxt[y])
		rtn=max(rtn,work(Adj[y]));
	rtn+=w[x];
	v[x]=true;
	return h[x]=rtn;
}
int main()
{
	scanf("%d%d%d",&n,&m,&d);
	for(i=1;i<=m;++i)
	{
		scanf("%d%d",&j,&k);
		for(x=1;x<d;++x)
			addedge((j-1)*d+x,(k-1)*d+x+1);
		addedge(j*d,(k-1)*d+1);
	}
	j=0;
	for(i=1;i<=n*d;++i)
		if(!v[i])
			dfs(i);
	for(;j>=1;--j)
		if(!col[h[j]])
		{
			++cnt;
			rdfs(h[j]);
		}
	for(i=1;i<=n;++i)
	{
		scanf("%s",s+1);
		for(j=1;j<=d;++j)
			c[col[(i-1)*d+j]]=0;
		for(j=1;j<=d;++j)
			if(s[j]=='1')
				c[col[(i-1)*d+j]]=1;
		for(j=1;j<=d;++j)
			if(c[col[(i-1)*d+j]])
			{
				w[col[(i-1)*d+j]]++;
				c[col[(i-1)*d+j]]=0;
			}
	}
	for(i=1;i<=l;++i)
		if(col[adj[i]]!=col[radj[i]])
			Addedge(col[radj[i]],col[adj[i]]);
	for(i=1;i<=n*d;++i)
		v[i]=false;
	printf("%d",work(col[1]));
	return 0;
}