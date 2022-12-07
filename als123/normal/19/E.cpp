#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=1000005*2;
int n,m;
int X[N],Y[N];
bool ok[N];// 
int f[N];
int find (int x){return f[x]==x?f[x]:f[x]=find(f[x]);}
struct qr
{
	int x,y,last;
}e[N*2];int num,last[N];
void init (int x,int y)
{
	num++;
	e[num].x=x;e[num].y=y;
	e[num].last=last[x];
	last[x]=num;
}
int ys[N],tot[N],son[N],fa[N],dep[N],top[N],num2;
int col[N];// 
void dfs (int x,int ff)
{
    tot[x]=1;
    for (int u=last[x];u!=-1;u=e[u].last)
    {
        int y=e[u].y;
        if (y==ff) continue;
        col[y]=(col[x]^1);
        dep[y]=dep[x]+1;
        fa[y]=x;
        dfs(y,x);
        tot[x]+=tot[y];
        if (tot[son[x]]<tot[y]) son[x]=y;
    }
}
void dfs1 (int x,int tp)
{
    ys[x]=++num2;top[x]=tp;
    if (son[x]!=0) dfs1(son[x],tp);
    for (int u=last[x];u!=-1;u=e[u].last)
    {
        int y=e[u].y;
        if (y==son[x]||y==fa[x]) continue;
        dfs1(y,y);
    }
}
struct qy
{
    int l,r;
    int s1,s2;
    int c;
}tr[N*2];
void bt (int l,int r)
{
    int a=++num;
    tr[a].l=l;tr[a].r=r;
    tr[a].c=0;
    if (l==r) return ;
    int mid=(l+r)>>1;
    tr[a].s1=num+1;bt(l,mid);
    tr[a].s2=num+1;bt(mid+1,r);
}
int id[N];
void Bt()
{
	for (int u=1;u<=n;u++)
	{
		if (fa[u]==0)
		{
			dep[u]=1;fa[u]=0;col[u]=0;
			dfs(u,0);
		}
	}
	num2=0;
	for (int u=1;u<=n;u++)
		if (fa[u]==0)
			dfs1(u,u);
    num=0;
    for (int u=1;u<=m;u++)
    	if (ok[u]==false)
			id[u]=++num2;
	bt(1,num2);
}
void Ins ()
{
	num=0;memset(last,-1,sizeof(last));
	scanf("%d%d",&n,&m);
	for (int u=1;u<=m;u++)	scanf("%d%d",&X[u],&Y[u]);
	for (int u=1;u<=n;u++) f[u]=u;
	for (int u=1;u<=m;u++)
	{
		int x=X[u],y=Y[u];
		int fx=find(x),fy=find(y);
		if (fx==fy) {ok[u]=false;continue;}
	//	printf("NO:%d %d\n",x,y);
		ok[u]=true;
		f[fx]=fy;
		init(x,y);init(y,x);
	}
}
void change (int now,int l,int r,int c)
{
	if (tr[now].l==tr[now].r)
	{
		tr[now].c+=c;
		return ;
	}
	int s1=tr[now].s1,s2=tr[now].s2;
	int mid=(tr[now].l+tr[now].r)>>1;
	if (r<=mid) change(s1,l,r,c);
	else if (l>mid) change(s2,l,r,c);
	else change(s1,l,mid,c),change(s2,mid+1,r,c);
}
void Change (int x,int y,int z)// 
{

    int tx=top[x],ty=top[y];
    if (dep[tx]>dep[ty]) {swap(x,y);swap(tx,ty);}//y
    while (tx!=ty)
    {
        change(1,ys[ty],ys[y],z);
        y=fa[ty];ty=top[y];
        if (dep[tx]>dep[ty]) {swap(x,y);swap(tx,ty);}//y
    }
    if (x==y) return ;
    if (dep[x]>dep[y]) swap(x,y);
    change(1,ys[son[x]],ys[y],z);
}
int get (int now,int x)
{
	if (tr[now].l==tr[now].r)
		return tr[now].c;
	int s1=tr[now].s1,s2=tr[now].s2;
	int mid=(tr[now].l+tr[now].r)>>1;
	if (x<=mid) return get(s1,x);
	else return get(s2,x);
}
int ans[N];
void solve ()
{
/*	for (int u=1;u<=n;u++)
		printf("%d %d %d\n",fa[u],ys[u],top[u]);
	printf("\n");*/
	int s=0;// 
	for (int u=1;u<=m;u++)
	{
		if (ok[u]==false)
		{
			if (col[X[u]]==col[Y[u]])//
			{
			//	printf("HAHA:%d %d %d\n",X[u],Y[u],id[u]);
				Change(X[u],Y[u],1);
				change(1,id[u],id[u],1);
				s++;
			}
			else
			{
				//printf("NO:%d %d %d\n",X[u],Y[u],id[u]);
				Change(X[u],Y[u],-1);
				change(1,id[u],id[u],-1);
			}
		/*	for (int u=1;u<=num;u++)
			printf("%d %d %d\n",tr[u].l,tr[u].r,tr[u].c);
			system("pause");*/
		}
	}

	//printf("%d\n",s);
	for (int u=1;u<=m;u++)
	{
		int lalal;
		if (ok[u]==false)//
			lalal=get(1,id[u]);
		else
		{
			int x=X[u],y=Y[u];
			if (dep[x]>dep[y]) swap(x,y);
			//x
			lalal=get(1,ys[y]); //printf("YES:%d %d %d %d\n",u,y,lalal,ys[y]);
		}
	
		if (s==0) ans[++ans[0]]=u;
		else if(lalal==s) ans[++ans[0]]=u;
	}
//	printf("YES:%d\n",s);
	printf("%d\n",ans[0]);
	for (int u=1;u<=ans[0];u++)
		printf("%d ",ans[u]);
}
int main() 
{
	Ins();
	Bt();
	solve();
	return 0;
}