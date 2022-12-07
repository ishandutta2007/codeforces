#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=400005;
const int MAX=1e9+7;
struct qq
{
	int x,y,c,id,used;
}e[N];
int num;
bool cmp (qq x,qq y)	{return x.c<y.c;}
int fa[N];
int find_fa (int x)	{return fa[x]==x?x:fa[x]=find_fa(fa[x]);}
int n,m;
int ans[N];
vector<int> vec[N];
int tot[N],dep[N];
int ys[N],son[N],top[N];
void dfs (int x)
{
    tot[x]=1;
    int siz=vec[x].size();
    for (int u=0;u<siz;u++)
    {
        int y=vec[x][u];
        if (y==fa[x]) continue;
        fa[y]=x;dep[y]=dep[x]+1;dfs(y);
        tot[x]=tot[x]+tot[y];
        if (tot[son[x]]<tot[y]) son[x]=y;
    }
}
void dfs1 (int x,int tp)
{
    top[x]=tp;ys[x]=++num;
    if (son[x]!=0) dfs1(son[x],tp);
    int siz=vec[x].size();
    for (int u=0;u<siz;u++)
    {
        int y=vec[x][u];
        if (y==fa[x]||y==son[x]) continue;
        dfs1(y,y);
    }
}
struct qt
{
	int l,r;
	int s1,s2;
	int c,c1;
	int lzy,lzy1;
}tr[N*2];
void upd (int now)
{
	int s1=tr[now].s1,s2=tr[now].s2;
	tr[now].c=min(tr[s1].c,tr[s2].c);
	tr[now].c1=max(tr[s1].c1,tr[s2].c1);
}
void bt (int l,int r)
{
	int now=++num;
	tr[now].l=l;tr[now].r=r;
	tr[now].c=MAX;tr[now].c1=-MAX;
	tr[now].lzy=MAX;tr[now].lzy1=-MAX;
	if (l==r) return ;
	int mid=(l+r)>>1;
	tr[now].s1=num+1;bt(l,mid);
	tr[now].s2=num+1;bt(mid+1,r);
}
//1   0 
void modify (int op,int now,int l,int r,int c)
{
	if (tr[now].l==l&&tr[now].r==r)
	{
		if (op==1) 
		{
			tr[now].c1=max(tr[now].c1,c);
			tr[now].lzy1=max(tr[now].lzy1,c);
		}
		else 
		{
			tr[now].c=min(tr[now].c,c);
			tr[now].lzy=min(tr[now].lzy,c);
		}
		return ;
	}
	int mid=(tr[now].l+tr[now].r)>>1;
	int s1=tr[now].s1,s2=tr[now].s2;
	if (r<=mid) modify(op,s1,l,r,c);
	else if (l>mid) modify(op,s2,l,r,c);
	else modify(op,s1,l,mid,c),modify(op,s2,mid+1,r,c);
	upd(now);
}
int query (int op,int now,int l,int r)
{
	if (tr[now].l==l&&tr[now].r==r)
	{
		if (op==0) return tr[now].c;
		else return tr[now].c1;
	}
	int mid=(tr[now].l+tr[now].r)>>1;
	int s1=tr[now].s1,s2=tr[now].s2;
	int t;
	if (r<=mid) t=query(op,s1,l,r);
	else if (l>mid) t=query(op,s2,l,r);
	else
	{
		if (op==0) t=min(query(op,s1,l,mid),query(op,s2,mid+1,r));
		else t=max(query(op,s1,l,mid),query(op,s2,mid+1,r));
	}
	if (op==0) t=min(t,tr[now].lzy);
	if (op==1) t=max(t,tr[now].lzy1);
	return t;
}
void change (int x,int y,int c)
{
	//printf("change:%d %d %d\n",x,y,c);
	int tx=top[x],ty=top[y];
	if (dep[tx]>dep[ty]) {swap(tx,ty);swap(x,y);};//y
    int ans=0;
    while (tx!=ty)
    {
    	modify(0,1,ys[ty],ys[y],c);
        y=fa[ty];ty=top[y];
        if (dep[tx]>dep[ty]) {swap(tx,ty);swap(x,y);}
    }
    if (x==y) return ;
    if (dep[x]>dep[y]) swap(x,y);
    modify(0,1,ys[son[x]],ys[y],c);
    //printf("OK!\n");
}
int get (int x,int y)
{
	int t=-MAX;
	int tx=top[x],ty=top[y];
	if (dep[tx]>dep[ty]) {swap(tx,ty);swap(x,y);};//y
    int ans=0;
    while (tx!=ty)
    {
    	t=max(t,query(1,1,ys[ty],ys[y]));
        y=fa[ty];ty=top[y];
        if (dep[tx]>dep[ty]) {swap(tx,ty);swap(x,y);}
    }
    if (dep[x]>dep[y]) swap(x,y);
    if (x==y) return t;
    t=max(t,query(1,1,ys[son[x]],ys[y]));
    return t;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int u=1;u<=m;u++)
	{
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);
		e[u].x=x;e[u].y=y;e[u].c=c;e[u].id=u;
	}
	sort(e+1,e+1+m,cmp);
	for (int u=1;u<=n;u++) fa[u]=u;
	for (int u=1;u<=m;u++)
	{
		int x=e[u].x,y=e[u].y;
		if (find_fa(x)==find_fa(y)) 	{e[u].used=false;continue;}
		e[u].used=true;
		fa[find_fa(x)]=y;
		//printf("%d %d\n",x,y);
		vec[x].push_back(y);vec[y].push_back(x);
	}
	memset(fa,0,sizeof(fa));
	dfs(1);
	num=0;dfs1(1,1);
	num=0;bt(1,n);
	//for (int u=1;u<=n;u++) printf("%d ",fa[u]);
	for (int u=1;u<=m;u++)
	if (dep[e[u].x]<dep[e[u].y])
	swap(e[u].x,e[u].y);
	for (int u=1;u<=m;u++)
	{
		//printf("%d %d\n",u,e[u].used);
		if (e[u].used==false)	change(e[u].x,e[u].y,e[u].c);
		else	modify(1,1,ys[e[u].x],ys[e[u].x],e[u].c);
	}
	for (int u=1;u<=m;u++)
	{
		if (e[u].used==false)	ans[e[u].id]=get(e[u].x,e[u].y)-1;
		if (e[u].used==true)
		{
			int t=query(0,1,ys[e[u].x],ys[e[u].x]);
			if (t==MAX) ans[e[u].id]=-1;
			else ans[e[u].id]=t-1;
		}
	}
	for (int u=1;u<=m;u++) printf("%d ",ans[u]);
	return 0;
}