#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const LL N=200005;
LL gcd (LL x,LL y)	{return x==0?y:gcd(y%x,x);}
LL n,m;
struct qq
{
	LL x,y,l,last;
}e[N*2];LL num,last[N];
void init (LL x,LL y,LL l)
{
	e[++num].x=x;e[num].y=y;e[num].l=l;
	e[num].last=last[x];last[x]=num;
}
LL dfn[N],low[N],dep[N],id;
LL h[N];
LL sta[N],top;
bool in[N];
LL bel[N],cnt,g[N];
void dfs (LL x)
{
	dfn[x]=low[x]=++id;
	sta[++top]=x;in[x]=true;
	for (LL u=last[x];u!=-1;u=e[u].last)
	{
		LL y=e[u].y;
		if (dfn[y]==-1)
		{
			dep[y]=dep[x]+e[u].l;
			dfs(y);
			low[x]=min(low[x],low[y]);
		}
		else if (in[y]==true)
		{
			low[x]=min(low[x],dfn[y]);
			h[x]=gcd(h[x],dep[x]-dep[y]+e[u].l);
		 } 
	}
	if (low[x]==dfn[x])
	{
		cnt++;g[cnt]=0;
		LL now;
		do
		{
			now=sta[top--];
			bel[now]=cnt;
			in[now]=false;
		//	printf("%lld %lld\n",now,h[now]);
			g[cnt]=gcd(g[cnt],h[now]);
		}while (now!=x);
	}
}
int main()
{
	num=0;memset(last,-1,sizeof(last));
	scanf("%lld%lld",&n,&m);
	for (LL u=1;u<=m;u++)
	{
		LL x,y,l;
		scanf("%lld%lld%lld",&x,&y,&l);
		init(x,y,l);
	}
	memset(dfn,-1,sizeof(dfn));
	memset(in,false,sizeof(in));
	for (LL u=1;u<=n;u++)
	if (dfn[u]==-1)
	dfs(u);
	LL q;
	scanf("%lld",&q);
	while (q--)
	{
		LL x,s,t;
		scanf("%lld%lld%lld",&x,&s,&t);
		//printf("%lld %lld\n",g[bel[x]],h[x]);
		LL o=gcd(g[bel[x]],t);
		if ((t-s)%o==0) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}