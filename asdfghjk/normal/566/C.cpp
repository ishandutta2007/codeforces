#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=500005;
int n,w[N],i,j,k,l,head[N],adj[N],nxt[N],len[N],root,Head[N],Adj[N],Nxt[N],sz[N],mx[N],pt[N],ans1;
bool v[N];
long double dao[N],ans2;
void Dfs(int x,int dad,int size)
{
	sz[x]=1;
	mx[x]=0;
	for(int y=head[x];y;y=nxt[y])
		if(adj[y]!=dad&&!v[adj[y]])
		{
			Dfs(adj[y],x,size);
			sz[x]+=sz[adj[y]];
			mx[x]=max(mx[x],sz[adj[y]]);
		}
	mx[x]=max(mx[x],size-sz[x]);
	if(!root||mx[x]<mx[root])
		root=x;
}
int dfs(int x,int size)
{
	root=0;
	Dfs(x,-1,size);
	v[root]=true;
	int rtn=root;
	for(int y=head[root];y;y=nxt[y])
		if(!v[adj[y]])
		{
			int z=dfs(adj[y],sz[adj[y]]);
			Adj[++l]=z;
			Nxt[l]=Head[rtn];
			Head[rtn]=l;
			pt[l]=adj[y];
		}
	return rtn;
}
long double dzx(int x,int dad,int d)
{
	long double rtn=sqrt(d)*w[x]*d;
	dao[x]=1.5*sqrt(d)*w[x];
	for(int y=head[x];y;y=nxt[y])
		if(adj[y]!=dad)
		{
			rtn+=dzx(adj[y],x,d+len[y]);
			dao[x]+=dao[adj[y]];
		}
	return rtn;
}
void work(int x)
{
	int y;
	long double w=dzx(x,-1,0);
	for(y=Head[x];y;y=Nxt[y])
		if(dao[x]-2*dao[pt[y]]<0)
			break;
	if(w<ans2)
	{
		ans1=x;
		ans2=w;
	}
	if(y)
		work(Adj[y]);
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
		scanf("%d",w+i);
	for(i=1;i<n;++i)
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
	root=dfs(1,n);
	ans2=1e50;
	work(root);
	printf("%d %.12lf",ans1,(double)ans2);
	return 0;
}