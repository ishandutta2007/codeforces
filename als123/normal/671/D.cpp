#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const LL N=300005;
LL n,m;
struct qq{LL x,y,last;}e[N*2];LL num,last[N];
void init (LL x,LL y)
{
	num++;
	e[num].x=x;e[num].y=y;
	e[num].last=last[x];
	last[x]=num;
}
LL top[N];
LL w[N];
LL d[N];
LL r[N],l[N];
LL lazy[N];
LL root[N];
void change (LL x,LL y){lazy[x]+=y;w[x]+=y;}
void push_down (LL x)
{
	if (l[x]!=0) change(l[x],lazy[x]);
	if (r[x]!=0) change(r[x],lazy[x]);
	lazy[x]=0;
}
LL Merge (LL x,LL y)
{
	if (x==0||y==0)	return x^y;
	if (w[x]>w[y]) swap(x,y);// 
	push_down(x);
	r[x]=Merge(r[x],y);
	if (d[r[x]]>d[l[x]]) swap(l[x],r[x]);
	d[x]=d[r[x]]+1;
	return x;
}
LL ans=0;
bool vis[N];
void dfs (LL x,LL fa)
{
	for (LL u=last[x];u!=-1;u=e[u].last)
	{
		LL y=e[u].y;
		if (y==fa) continue;
		dfs(y,x);
		root[x]=Merge(root[x],root[y]);
	}
	if (x==1) return ;
	vis[x]=true;
	while (vis[top[root[x]]])
	{
		push_down(root[x]);
		root[x]=Merge(r[root[x]],l[root[x]]);
	}
	if (root[x]==0)
	{
		printf("-1\n");
		exit(0);
	}
	ans=ans+w[root[x]];
	change(root[x],-w[root[x]]);
}
int main()
{
	memset(vis,false,sizeof(vis));
	num=0;memset(last,-1,sizeof(last));
	scanf("%I64d%I64d",&n,&m);
	for (LL u=1;u<n;u++)
	{
		LL x,y;
		scanf("%I64d%I64d",&x,&y);
		init(x,y);init(y,x);
	}
	for (LL u=1;u<=m;u++)
	{
		LL x;
		scanf("%I64d%I64d%I64d",&x,&top[u],&w[u]);
		root[x]=Merge(root[x],u);
	}
	dfs(1,0);
	printf("%I64d\n",ans);
	return 0;
}