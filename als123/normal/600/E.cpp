#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const LL N=100005;
LL n;
LL c[N];
struct qq
{
	LL x,y,last;
}e[N<<1];LL num,last[N];
void init (LL x,LL y)
{
	num++;
	e[num].x=x;e[num].y=y;
	e[num].last=last[x];
	last[x]=num;
}
LL son[N],tot[N];
void dfs1 (LL x,LL ff)
{
	tot[x]=1;
	for (LL u=last[x];u!=-1;u=e[u].last)
	{
		LL y=e[u].y;
		if (y==ff) continue;
		dfs1(y,x);
		tot[x]+=tot[y];
		if (tot[son[x]]<tot[y]) son[x]=y;
	}
}
bool vis[N];// 
LL shen[N],sum,maxx;
void change (LL x,LL ff,LL k)
{
	shen[c[x]]+=k;
	if (k>0&&shen[c[x]]>=maxx)
	{
		if (shen[c[x]]>maxx) sum=0,maxx=shen[c[x]];
		sum=sum+c[x];
	}
	for (LL u=last[x];u!=-1;u=e[u].last)
	{
		LL y=e[u].y;
		if (y==ff||vis[y]) continue;
		change(y,x,k);
	}
}
LL ans[N];
void dfs2 (LL x,LL ff,bool lalal)//       
{
	for (LL u=last[x];u!=-1;u=e[u].last)
	{
		LL y=e[u].y;
		if (y==ff||y==son[x]) continue;
		dfs2(y,x,false);
	}
	if (son[x]!=0)	dfs2(son[x],x,true),vis[son[x]]=true;
	change(x,ff,1);ans[x]=sum;
	if (son[x]!=0) vis[son[x]]=false;
	if (lalal==false)//
		change(x,ff,-1),maxx=sum=0;
}
int main()
{
	num=0;memset(last,-1,sizeof(last));
	scanf("%lld",&n);
	for (LL u=1;u<=n;u++) scanf("%lld",&c[u]);
	for (LL u=1;u<n;u++)
	{
		LL x,y;
		scanf("%lld%lld",&x,&y);
		init(x,y);init(y,x);
	}
	dfs1(1,0);
	dfs2(1,0,false);
	for (LL u=1;u<=n;u++)
		printf("%lld ",ans[u]);
	return 0;
}