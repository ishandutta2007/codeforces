#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const LL N=100005;
LL n,m;
struct qq
{
	LL x,y,last;
}e[N*2];LL num,last[N];
void init (LL x,LL y)
{
	num++;
	e[num].x=x;e[num].y=y;
	e[num].last=last[x];
	last[x]=num;
}
LL f[N];
LL g[N];
LL id[N];
LL a[N];
bool cmp (LL x,LL y)	{return a[x]>a[y];}
LL find (LL x){return f[x]==x?f[x]:f[x]=find(f[x]);}
LL vis[N],tim;
int main()
{
	num=0;memset(last,-1,sizeof(last));
	scanf("%lld%lld",&n,&m);
	for (LL u=1;u<=n;u++) f[u]=u,g[u]=0,id[u]=u;
	for (LL u=1;u<=n;u++)	scanf("%lld",&a[u]);
	for (LL u=1;u<=m;u++)
	{
		LL x,y;
		scanf("%lld%lld",&x,&y);
		init(x,y);init(y,x);
	}
	sort(id+1,id+1+n,cmp);
	LL ans=0;
	memset(vis,0,sizeof(vis));
	tim=0;
	for (LL i=1;i<=n;i++)
	{
		LL x=id[i];
		LL sum=1;
		tim++;
		for (LL u=last[x];u!=-1;u=e[u].last)
		{
			LL y=e[u].y;
			LL xx=find(y);
			if (g[xx]==0) continue;
			if (vis[xx]==tim) continue;
			vis[xx]=tim;
			sum=sum+g[xx];
		}
		tim++;
		for (LL u=last[x];u!=-1;u=e[u].last)
		{
			LL y=e[u].y;
			LL xx=find(y);
			if (g[xx]==0) continue;
			if (vis[xx]==tim) continue;
			vis[xx]=tim;
			sum=sum-g[xx];
			//printf("YES:%lld %lld %lld g[xx]:%lld sum:%lld\n",x,xx,a[x],g[xx],sum);
			ans=ans+a[x]*g[xx]*sum;
		}
		g[x]=1;
		tim++;
		for (LL u=last[x];u!=-1;u=e[u].last)
		{
			LL y=e[u].y;
			LL xx=find(y);
			if (g[xx]==0) continue;
			if (xx==x) continue;
			g[x]=g[x]+g[xx];
			f[xx]=x;
		}
		/*for (LL u=1;u<=n;u++) printf("%lld ",g[u]);
		printf("\n");*/
	}
	LL lalal=n*(n-1)/2;
	printf("%lf",(double)(ans)/lalal);
	return 0;
}