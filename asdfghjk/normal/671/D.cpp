#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
const int N=300005;
int n,m,head[N],adj[N*2],nxt[N*2],X[N],Y[N],i,j,k,pt[N],w[N],fa[N],dep[N],size[N],son[N],tp[N],id[N];
long long ans,sum[N*5],tag[N];
multiset<long long> st[N];
vector<int> add[N],del[N];
void work(int x,int dad)
{
	size[x]=1;
	for(int y=head[x];y;y=nxt[y])
		if(adj[y]!=dad)
		{
			dep[adj[y]]=dep[x]+1;
			fa[adj[y]]=x;
			work(adj[y],x);
			size[x]+=size[adj[y]];
			if(!son[x]||size[adj[y]]>size[son[x]])
				son[x]=adj[y];
		}
}
void Work(int x,int dad)
{
	id[x]=++i;
	if(son[x])
	{
		tp[son[x]]=tp[x];
		Work(son[x],x);
	}
	for(int y=head[x];y;y=nxt[y])
		if(adj[y]!=dad&&adj[y]!=son[x])
		{
			tp[adj[y]]=adj[y];
			Work(adj[y],x);
		}
}
void update(int o,int l,int r,int x,int y)
{
	if(l==r)
	{
		sum[o]+=y;
		return;
	}
	int mid=l+r>>1;
	if(x<=mid)
		update(o<<1,l,mid,x,y);
	else
		update(o<<1|1,mid+1,r,x,y);
	sum[o]=sum[o<<1]+sum[o<<1|1];
}
long long query(int o,int l,int r,int x,int y)
{
	if(l>=x&&r<=y)
		return sum[o];
	int mid=l+r>>1;
	long long rtn=0;
	if(x<=mid)
		rtn=query(o<<1,l,mid,x,y);
	if(y>mid)
		rtn+=query(o<<1|1,mid+1,r,x,y);
	return rtn;
}
long long Sum(int x)
{
	long long rtn=0;
	while(x)
	{
		rtn+=query(1,1,n,id[tp[x]],id[x]);
		x=fa[tp[x]];
	}
	return rtn;
}
void dfs(int x,int dad)
{
	pt[x]=x;
	for(int y=head[x];y;y=nxt[y])
		if(adj[y]!=dad)
		{
			dfs(adj[y],x);
			if(ans==-1)
				return;
			if(st[pt[adj[y]]].size()>st[pt[x]].size())
				swap(pt[x],pt[adj[y]]);
			tag[pt[adj[y]]]-=tag[pt[x]];
			while(!st[pt[adj[y]]].empty())
			{
				st[pt[x]].insert(tag[pt[adj[y]]]+*(st[pt[adj[y]]].begin()));
				st[pt[adj[y]]].erase(st[pt[adj[y]]].begin());
			}
		}
	for(int i=add[x].size()-1;i>=0;--i)
		st[pt[x]].insert(w[add[x][i]]-tag[pt[x]]);
	for(int i=del[x].size()-1;i>=0;--i)
		st[pt[x]].erase(st[pt[x]].find(w[del[x][i]]-(Sum(X[del[x][i]])-Sum(Y[del[x][i]]))-tag[pt[x]]));
	if(dad!=-1)
	{
		if(!st[pt[x]].empty())
		{
			ans+=(*st[pt[x]].begin())+tag[pt[x]];
			update(1,1,n,id[x],(*st[pt[x]].begin())+tag[pt[x]]);
			tag[pt[x]]=-(*st[pt[x]].begin());
		}
		else
			ans=-1;
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<n;++i)
	{
		scanf("%d%d",&j,&k);
		adj[i*2-1]=k;
		nxt[i*2-1]=head[j];
		head[j]=i*2-1;
		adj[i*2]=j;
		nxt[i*2]=head[k];
		head[k]=i*2;
	}
	for(i=1;i<=m;++i)
	{
		scanf("%d%d%d",&j,&k,&w[i]);
		X[i]=j,Y[i]=k;
		add[j].push_back(i),del[k].push_back(i);
	}
	work(1,-1);
	tp[1]=1;
	i=0;
	Work(1,-1);
	dfs(1,-1);
	printf("%lld",ans);
	return 0;
}