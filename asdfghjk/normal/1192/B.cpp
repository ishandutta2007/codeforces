#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>
using namespace std;
typedef long long ll;
const int N=200005;
struct node
{
	ll a[3][3];
}u[N],d,e,s[N*5];
int n,q,i,j,k,head[N],adj[N*2],nxt[N*2],size[N],dep[N],fa[N],son[N],sone[N],fae[N],ed[N],id[N],di[N],tp[N];
ll w,len[N*2],o,f[N],h[N],ans,F[N],H[N],H2[N];
multiset<ll> st[N],St[N];
multiset<ll>::iterator ddq;
node mult(node a,node b)
{
	node c;
	for(int i=0;i<3;++i)
		for(int j=0;j<3;++j)
			c.a[i][j]=-(1ll<<60);
	for(int i=0;i<3;++i)
		for(int j=0;j<3;++j)
			for(int k=0;k<3;++k)
				c.a[i][j]=max(c.a[i][j],a.a[i][k]+b.a[k][j]);
	return c;
}
ll cirno(int x)
{
	ll u=0;
	ddq=st[x].end();
	if(ddq!=st[x].begin())
	{
		--ddq;
		u+=*ddq;
	}
	if(ddq!=st[x].begin())
	{
		--ddq;
		u+=*ddq;
	}
	return u;
}
void dfs(int x,int dad)
{
	size[x]=1;
	for(int y=head[x];y;y=nxt[y])
		if(adj[y]!=dad)
		{
			fa[adj[y]]=x;
			fae[adj[y]]=y;
			dep[adj[y]]=dep[x]+1;
			dfs(adj[y],x);
			if(H[adj[y]]+len[y]>H[x])
			{
				H2[x]=H[x];
				H[x]=H[adj[y]]+len[y];
			}
			else if(H[adj[y]]+len[y]>H2[x])
				H2[x]=H[adj[y]]+len[y];
			F[x]=max(F[x],F[adj[y]]);
			size[x]+=size[adj[y]];
			if(!son[x]||size[adj[y]]>size[son[x]])
			{
				son[x]=adj[y];
				sone[x]=y;
			}
		}
	F[x]=max(F[x],H[x]+H2[x]);
}
void Dfs(int x,int dad)
{
	id[x]=++i;
	di[i]=x;
	if(son[x])
	{
		tp[son[x]]=tp[x];
		Dfs(son[x],x);
		ed[x]=ed[son[x]];
	}
	else
		ed[x]=x;
	for(int y=head[x];y;y=nxt[y])
		if(adj[y]!=dad&&adj[y]!=son[x])
		{
			tp[adj[y]]=adj[y];
			Dfs(adj[y],x);
			st[x].insert(H[adj[y]]+len[y]);
			St[x].insert(F[adj[y]]);
			h[x]=max(h[x],H[adj[y]]+len[y]);
		}
	f[x]=max(St[x].empty()?0:*(--St[x].end()),cirno(x));
}
void built(int o,int l,int r)
{
	if(l==r)
	{
		s[o]=u[di[l]];
		return;
	}
	int mid=l+r>>1;
	built(o<<1,l,mid);
	built(o<<1|1,mid+1,r);
	s[o]=mult(s[o<<1|1],s[o<<1]);
}
void update(int o,int l,int r,int x)
{
	if(l==r)
	{
		s[o]=u[di[l]];
		return;
	}
	int mid=l+r>>1;
	if(x<=mid)
		update(o<<1,l,mid,x);
	else
		update(o<<1|1,mid+1,r,x);
	s[o]=mult(s[o<<1|1],s[o<<1]);
}
void query(int o,int l,int r,int x,int y)
{
	if(l>=x&&r<=y)
	{
		e=mult(e,s[o]);
		return;
	}
	int mid=l+r>>1;
	if(y>mid)
		query(o<<1|1,mid+1,r,x,y);
	if(x<=mid)
		query(o<<1,l,mid,x,y);
}
int main()
{
	scanf("%d%d%lld",&n,&q,&w);
	for(i=1;i<n;++i)
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
	dfs(1,-1);
	tp[1]=1;
	i=0;
	Dfs(1,-1);
	for(i=1;i<=n;++i)
	{
		if(!son[i])
			continue;
		u[i].a[0][0]=len[sone[i]];
		u[i].a[0][1]=len[sone[i]]+h[i];
		u[i].a[2][0]=h[i];
		u[i].a[2][1]=f[i];
		u[i].a[0][2]=u[i].a[1][0]=u[i].a[1][2]=-(1ll<<62);
	}
	built(1,1,n);
	while(q--)
	{
		scanf("%d%lld",&i,&o);
		i=(i+ans)%(n-1)+1;
		o=(o+ans)%w;
		j=(dep[adj[i*2-1]]<dep[adj[i*2]]?adj[i*2-1]:adj[i*2]);
		k=(dep[adj[i*2-1]]<dep[adj[i*2]]?adj[i*2]:adj[i*2-1]);
		if((sone[j]+1)/2==i)
			u[j].a[0][0]+=o-len[i*2],u[j].a[0][1]+=o-len[i*2];
		else
		{
			for(int i=0;i<3;++i)
				for(int j=0;j<3;++j)
					e.a[i][j]=0;
			query(1,1,n,id[k],id[ed[k]]);
			st[j].erase(st[j].find(e.a[0][0]+len[i*2]));
			st[j].insert(e.a[0][0]+o);
			j=k;
		}
		len[i*2-1]=len[i*2]=o;
		while(j)
		{
			for(int i=0;i<3;++i)
				for(int j=0;j<3;++j)
					e.a[i][j]=0;
			query(1,1,n,id[tp[j]],id[ed[tp[j]]]);
			for(int i=0;i<3;++i)
				for(int j=0;j<3;++j)
					d.a[i][j]=e.a[i][j];
			update(1,1,n,id[j]);
			for(int i=0;i<3;++i)
				for(int j=0;j<3;++j)
					e.a[i][j]=0;
			query(1,1,n,id[tp[j]],id[ed[tp[j]]]);
			o=len[fae[tp[j]]];
			j=fa[tp[j]];
			if(!j)
				break;
			st[j].erase(st[j].find(d.a[0][0]+o));
			st[j].insert(e.a[0][0]+o);
			St[j].erase(St[j].find(d.a[0][1]));
			St[j].insert(e.a[0][1]);
			h[j]=*(--st[j].end());
			f[j]=max(St[j].empty()?0:*(--St[j].end()),cirno(j));
			u[j].a[0][0]=len[sone[j]];
			u[j].a[0][1]=len[sone[j]]+h[j];
			u[j].a[2][0]=h[j];
			u[j].a[2][1]=f[j];
			u[j].a[0][2]=u[j].a[1][0]=u[j].a[1][2]=-(1ll<<62);
		}
		for(int i=0;i<3;++i)
			for(int j=0;j<3;++j)
				e.a[i][j]=0;
		query(1,1,n,id[1],id[ed[1]]);
		printf("%lld\n",ans=e.a[0][1]);
	}
	return 0;
}