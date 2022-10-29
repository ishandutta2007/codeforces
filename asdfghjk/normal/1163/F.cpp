#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#include<set>
using namespace std;
const int N=200005;
typedef long long ll;
struct node
{
	int h;
	ll d;
}t;
bool operator <(node a,node b)
{
	return a.d>b.d;
}
priority_queue<node> q;
int n,m,Q,i,j,k,head[N],adj[N*2],nxt[N*2],lst[N],lste[N],Head[N],Adj[N*2],Nxt[N*2],size[N],son[N],tp[N],pt[N],dep[N];
ll len[N*2],dis[N],rdis[N],ans[N];
bool v[N],vis[N],b[N];
vector<ll> add[N],del[N];
multiset<ll> st[N];
multiset<ll>::iterator ddq,dzx;
void dfs(int x)
{
	size[x]=1;
	for(int y=Head[x];y;y=Nxt[y])
	{
		dep[Adj[y]]=dep[x]+1;
		dfs(Adj[y]);
		size[x]+=size[Adj[y]];
		if(!son[x]||size[Adj[y]]>size[son[x]])
			son[x]=Adj[y];
	}
}
void Dfs(int x)
{
	if(son[x])
	{
		tp[son[x]]=tp[x];
		Dfs(son[x]);
	}
	for(int y=Head[x];y;y=Nxt[y])
		if(Adj[y]!=son[x])
		{
			tp[Adj[y]]=Adj[y];
			Dfs(Adj[y]);
		}
}
int lca(int a,int b)
{
	while(tp[a]!=tp[b])
	{
		if(dep[tp[a]]<dep[tp[b]])
			swap(a,b);
		a=lst[tp[a]];
	}
	return dep[a]<dep[b]?a:b;
}
void work(int x)
{
	pt[x]=x;
	for(int y=Head[x];y;y=Nxt[y])
	{
		work(Adj[y]);
		if(st[pt[x]].size()<st[pt[Adj[y]]].size())
		{
			for(ddq=st[pt[x]].begin();ddq!=st[pt[x]].end();)
			{
				st[pt[Adj[y]]].insert(*ddq);
				dzx=ddq;
				ddq++;
				st[pt[x]].erase(dzx);
			}
			pt[x]=pt[Adj[y]];
		}
		else
		{
			for(ddq=st[pt[Adj[y]]].begin();ddq!=st[pt[Adj[y]]].end();)
			{
				st[pt[x]].insert(*ddq);
				dzx=ddq;
				ddq++;
				st[pt[Adj[y]]].erase(dzx);
			}
		}
	}
	for(int i=add[x].size()-1;i>=0;--i)
		st[pt[x]].insert(add[x][i]);
	for(int i=del[x].size()-1;i>=0;--i)
		st[pt[x]].erase(st[pt[x]].find(del[x][i]));
	if(lste[x])
	{
		if(st[pt[x]].empty())
			ans[lste[x]]=1ll<<60;
		else
			ans[lste[x]]=*(st[pt[x]].begin());
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&Q);
	for(i=1;i<=m;++i)
	{
		scanf("%d%d%lld",&j,&k,&len[i*2]);
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
	dis[1]=0;
	q.push((node){1,0});
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
				lst[adj[i]]=t.h;
				lste[adj[i]]=(i+1)/2;
				dis[adj[i]]=t.d+len[i];
				q.push((node){adj[i],dis[adj[i]]});
			}
	}
	for(i=1;i<=n;++i)
		rdis[i]=1ll<<60,v[i]=false;
	rdis[n]=0;
	q.push((node){n,0});
	while(!q.empty())
	{
		t=q.top();
		q.pop();
		if(v[t.h])
			continue;
		v[t.h]=true;
		for(i=head[t.h];i;i=nxt[i])
			if(t.d+len[i]<rdis[adj[i]])
			{
				rdis[adj[i]]=t.d+len[i];
				q.push((node){adj[i],rdis[adj[i]]});
			}
	}
	for(i=2;i<=n;++i)
	{
		Adj[i-1]=i;
		Nxt[i-1]=Head[lst[i]];
		Head[lst[i]]=i-1;
		vis[lste[i]]=true;
	}
	dfs(1);
	tp[1]=1;
	Dfs(1);
	for(i=1;i<=m;++i)
		if(!vis[i])
		{
			ll k=min(dis[adj[i*2-1]]+rdis[adj[i*2]]+len[i*2],dis[adj[i*2]]+rdis[adj[i*2-1]]+len[i*2]);
			add[adj[i*2-1]].push_back(k);
			add[adj[i*2]].push_back(k);
			del[j=lca(adj[i*2],adj[i*2-1])].push_back(k);
			del[j].push_back(k);
		}
	for(i=n;lst[i];i=lst[i])
		b[lste[i]]=true;
	work(1);
	for(i=1;i<=m;++i)
		if(!b[i])
			ans[i]=dis[n];
	while(Q--)
	{
		scanf("%d%d",&i,&j);
		printf("%lld\n",min(min(dis[adj[i*2]]+rdis[adj[i*2-1]],dis[adj[i*2-1]]+rdis[adj[i*2]])+j,ans[i]));
	}
	return 0;
}