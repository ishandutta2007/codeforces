//zhouakngyang txdy!
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
#define mid ((l+r)>>1)	
const int N=2e5+9,M=1<<20+1;
int n,m,x,y,mod,cnt,rt,val_pre[N],a[N];
int id[N],top[N];
int fa[N],dep[N],siz[N],son[N];
vector<int> G[N];
struct Tree
{
	int val,lazy;
}tree[N<<2];
inline void dfs1(int u,int f)
{
	dep[u]=dep[f]+1;fa[u]=f;
	int maxson=-1;
	for(int i=0;i<G[u].size();i++)
		if(G[u][i]!=f)
		{
			dfs1(G[u][i],u);
			siz[u]+=siz[G[u][i]];
			if(siz[G[u][i]]>maxson)maxson=siz[G[u][i]],son[u]=G[u][i];
		}
	return ;
}
inline void dfs2(int u,int topf)
{
	id[u]=++cnt;
	a[id[u]]=val_pre[u];
	top[u]=topf;
//	cout<<u<<" "<<top[u]<<"---------"<<endl;
	if(!son[u])return ;
	dfs2(son[u],topf);
	for(int i=0;i<G[u].size();i++)
	{
		if(G[u][i]==fa[u]||G[u][i]==son[u])continue;
		dfs2(G[u][i],G[u][i]);
	}
	return ;
}
inline int lc(int p){return p<<1;}
inline int rc(int p){return p<<1|1;}
inline void push_up(int p)
{
	tree[p].val=tree[lc(p)].val+tree[rc(p)].val;
	return ;
}
inline void get(int l,int r,int p,int k)
{
	tree[p].val+=k*(r-l+1);tree[p].lazy+=k;
	return ;
}
inline void push_down(int l,int r,int p)
{
	if(tree[p].lazy)
	{
		get(l,mid,lc(p),tree[p].lazy);
		get(mid+1,r,rc(p),tree[p].lazy);
		tree[p].lazy=0;return ;
	}
}
inline void build(int l,int r,int p)
{
	tree[p].lazy=0;
	if(l==r)
	{
		tree[p].val=0;return ;
	}
	build(l,mid,lc(p));
	build(mid+1,r,rc(p));
	push_up(p);
}
inline void update(int l,int r,int p,int L,int R,int k)
{
	if(L<=l&&r<=R)
	{
		tree[p].val+=(r-l+1)*k;tree[p].lazy+=k;return ;
	}
	push_down(l,r,p);
	if(mid>=L)update(l,mid,lc(p),L,R,k);
	if(mid<R)update(mid+1,r,rc(p),L,R,k);
	push_up(p);
	return ;
}
inline int query(int l,int r,int p,int L,int R)
{
	if(L<=l&&r<=R)return tree[p].val;
	int res=0;
	push_down(l,r,p);
	if(mid>=L)res=(res+query(l,mid,lc(p),L,R));
	if(mid<R)res=(res+query(mid+1,r,rc(p),L,R));
	return res;
}
inline int query_sub(int x)
{
//	cout<<id[x]<<" "<<id[x]+siz[x]-1<<endl;
	return query(1,n,1,id[x],id[x]+siz[x]-1);
}
inline void update_sub(int x,int z)
{
//	cout<<id[x]<<" "<<id[x]+siz[x]-1<<" "<<z<<"zhouakngyang txdy!"<<endl;
	update(1,n,1,id[x],id[x]+siz[x]-1,z);return ;
}
inline int query_chain(int x,int y)
{
	int res=0;
	while(top[x]!=top[y])
	{	
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		res+=query(1,n,1,id[top[x]],id[x]);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	res+=query(1,n,1,id[x],id[y]);
	return res;
} 
inline void update_chain(int x,int y,int z)
{
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		update(1,n,1,id[top[x]],id[x],z);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	update(1,n,1,id[x],id[y],z);
	return ;
} 
signed main()
{
	n=read();m=read();rt=1;
	for(int i=1;i<=n;i++)siz[i]=1,val_pre[i]=read();
	for(int i=1;i<n;i++)
	{
		x=read(),y=read();
		G[x].push_back(y),G[y].push_back(x);
	}
	dfs1(rt,0);
	dfs2(rt,rt);
	build(1,n,1);
	for(int i=1;i<=m;i++)
	{
		int opt=read();
		if(opt==1)
		{
			int x=read(),z=read();if(dep[x]%2==1)z=-z;
			update(1,n,1,id[x],id[x],z);
		}
		else
		{
			int x=read(),y=1,flag=1;
			if(dep[x]%2==1)flag=-1;
			printf("%lld\n",query_chain(x,y)*flag+val_pre[x]);
		}
	}
	return 0;
}
/*
5 5 2 24
7 3 7 8 0 
1 2
1 5
3 1
4 1
3 4 2
3 2 2
4 5
3 2 5
4 2
*/