#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=100005;
int n,k;
struct qq
{
	int x,y,last;
}e[N<<1];int num,last[N];
void init (int x,int y)
{
	num++;
	e[num].x=x;e[num].y=y;
	e[num].last=last[x];
	last[x]=num;
}
int son[N],top[N],fa[N],tot[N],ys[N],dep[N];
void dfs (int x,int f)
{
	tot[x]=1;
	for (int u=last[x];u!=-1;u=e[u].last)
	{
		int y=e[u].y;
		if (y==f) continue;
		dep[y]=dep[x]+1;fa[y]=x;dfs(y,x);
		tot[x]+=tot[y];
		if (tot[y]>tot[son[x]]) son[x]=y;
	}
}
void dfs1 (int x,int tp)
{
	ys[x]=++num;top[x]=tp;
	if (son[x]!=0) dfs1(son[x],tp);
	for (int u=last[x];u!=-1;u=e[u].last)
	{
		int y=e[u].y;
		if (y==fa[x]||y==son[x]) continue;
		dfs1(y,y);
	}
}
struct qr
{
	int l,r;
	int c;
	int val;
	int s1,s2;
	int lazy;
}tr[N<<1];int num1;
void bt (int l,int r)
{
	int a=++num1;
	tr[a].l=l;tr[a].r=r;
	tr[a].c=0;tr[a].val=0;
	tr[a].lazy=0;
	if (l==r) return ;
	int mid=(l+r)>>1;
	tr[a].s1=num1+1;bt(l,mid);
	tr[a].s2=num1+1;bt(mid+1,r);
}
void change (int now,int l,int r,int c)
{
	int s1=tr[now].s1,s2=tr[now].s2;
	int mid=(tr[now].l+tr[now].r)>>1;
	if (tr[now].l==l&&tr[now].r==r)
	{
		tr[now].lazy+=c;
		if (tr[now].lazy==0) tr[now].val=tr[s1].val+tr[s2].val;
		else tr[now].val=(r-l+1);
		return ;
	}
	if (r<=mid) change(s1,l,r,c);
	else if (l>mid) change(s2,l,r,c);
	else change(s1,l,mid,c),change(s2,mid+1,r,c);
	if (tr[now].lazy==0) tr[now].val=tr[s1].val+tr[s2].val;
}
void change1 (int x,int y,int c)// 
{
//	if (c==-1) printf("%d %d\n",x,y);
	int tx=top[x],ty=top[y];
	if (dep[ty]<dep[tx]) {swap(x,y);swap(tx,ty);}
	while (tx!=ty)
	{
		change(1,ys[ty],ys[y],c);
		y=fa[ty];ty=top[y];
		if (dep[ty]<dep[tx]) {swap(x,y);swap(tx,ty);}
	}
	if (dep[x]>dep[y]) swap(x,y);
	change(1,ys[x],ys[y],c);
	return ;
}
int main()
{
	num=0;memset(last,-1,sizeof(last));
	scanf("%d%d",&n,&k);
	for (int u=1;u<n;u++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		init(x,y);init(y,x);
	}
	dfs(1,0);
	num=0;dfs1(1,1);
	bt(1,num);
	int ans=1;
	int l=1;
	for (int u=2;u<=n;u++)// 
	{
		change1(u,u-1,1);
		while (tr[1].val>k)
		{
			change1(l,l+1,-1);
			l++;
		}
		ans=max(ans,u-l+1);
	}
	printf("%d\n",ans);
	return 0;
}