#include<cstdio>
#include<cmath>
#include<cstring>
#include<set>
#include<algorithm>
using namespace std;
const int N=200005;
multiset<int> st[N];
int n,m,q,i,j,k,w[N],head[N],adj[N*2],nxt[N*2],id[N],len,pre[N],s[N],top,num,col[N],Head[N],Adj[N*2],Nxt[N*2],l,c[N],dep[N],son[N],size[N],fa[N],tp[N],h[N],ans,mn[N*5];
char ch[10];
void addedge(int u,int v)
{
	Adj[++l]=v;
	Nxt[l]=Head[u];
	Head[u]=l;
	Adj[++l]=u;
	Nxt[l]=Head[v];
	Head[v]=l;
}
void dfs(int x,int dad)
{
	id[x]=pre[x]=++len;
	for(int y=head[x];y;y=nxt[y])
		if(!id[adj[y]])
		{
			s[++top]=(y+1)/2;
			dfs(adj[y],x);
			pre[x]=min(pre[x],pre[adj[y]]);
			if(pre[adj[y]]>=id[x])
			{
				++num;
				while(1)
				{
					if(col[adj[s[top]*2-1]]!=num)
					{
						addedge(adj[s[top]*2-1],n+num);
						col[adj[s[top]*2-1]]=num;
					}
					if(col[adj[s[top]*2]]!=num)
					{
						addedge(adj[s[top]*2],n+num);
						col[adj[s[top]*2]]=num;
					}
					--top;
					if(s[top+1]==(y+1)/2)
						break;
				}
			}
		}
		else if(adj[y]!=dad&&id[adj[y]]<pre[x])
		{
			s[++top]=(y+1)/2;
			pre[x]=id[adj[y]];
		}
}
void Dfs(int x,int dad)
{
	size[x]=1;
	for(int y=Head[x];y;y=Nxt[y])
		if(Adj[y]!=dad)
		{
			dep[Adj[y]]=dep[x]+1;
			fa[Adj[y]]=x;
			Dfs(Adj[y],x);
			size[x]+=size[Adj[y]];
			if(!son[x]||size[Adj[y]]>size[son[x]])
				son[x]=Adj[y];
		}
}
void work(int x,int dad)
{
	c[x]=++i;
	h[i]=x;
	if(son[x])
	{
		tp[son[x]]=tp[x];
		work(son[x],x);
	}
	for(int y=Head[x];y;y=Nxt[y])
		if(Adj[y]!=dad&&Adj[y]!=son[x])
		{
			tp[Adj[y]]=Adj[y];
			work(Adj[y],x);
		}
}
void built(int o,int l,int r)
{
	if(l==r)
	{
		mn[o]=(h[l]<=n?w[h[l]]:*(st[h[l]].begin()));
		return;
	}
	int mid=l+r>>1;
	built(o<<1,l,mid);
	built(o<<1|1,mid+1,r);
	mn[o]=min(mn[o<<1],mn[o<<1|1]);
}
void update(int o,int l,int r,int x,int y)
{
	if(l==r)
	{
		mn[o]=y;
		return;
	}
	int mid=l+r>>1;
	if(x<=mid)
		update(o<<1,l,mid,x,y);
	else
		update(o<<1|1,mid+1,r,x,y);
	mn[o]=min(mn[o<<1],mn[o<<1|1]);
}
int query(int o,int l,int r,int x,int y)
{
	if(l>=x&&r<=y)
		return mn[o];
	int mid=l+r>>1,rtn=1<<30;
	if(x<=mid)
		rtn=query(o<<1,l,mid,x,y);
	if(y>mid)
		rtn=min(rtn,query(o<<1|1,mid+1,r,x,y));
	return rtn;
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(i=1;i<=n;++i)
		scanf("%d",w+i);
	for(i=1;i<=m;++i)
	{
		scanf("%d%d",&j,&k);
		adj[i*2-1]=k;
		nxt[i*2-1]=head[j];
		head[j]=i*2-1;
		adj[i*2]=j;
		nxt[i*2]=head[k];
		head[k]=i*2;
	}
	for(i=1;i<=n;++i)
		if(!id[i])
			dfs(i,-1);
	Dfs(1,-1);
	tp[1]=1;
	i=0;
	work(1,-1);
	for(i=1;i<=n;++i)
		if(fa[i])
			st[fa[i]].insert(w[i]);
	built(1,1,n+num);
	while(q--)
	{
		scanf("%s%d%d",ch,&i,&j);
		if(ch[0]=='C')
		{
			update(1,1,n+num,c[i],j);
			if(fa[i])
			{
				st[fa[i]].erase(st[fa[i]].find(w[i]));
				st[fa[i]].insert(j);
				update(1,1,n+num,c[fa[i]],*(st[fa[i]].begin()));
			}
			w[i]=j;
		}
		else
		{
			ans=1<<30;
			while(tp[i]!=tp[j])
			{
				if(dep[tp[i]]<dep[tp[j]])
					swap(i,j);
				ans=min(ans,query(1,1,n+num,c[tp[i]],c[i]));
				i=fa[tp[i]];
			}
			if(dep[i]>dep[j])
				swap(i,j);
			ans=min(ans,query(1,1,n+num,c[i],c[j]));
			if(i>n&&fa[i])
				ans=min(ans,w[fa[i]]);
			printf("%d\n",ans);
		}
	}
	return 0;
}