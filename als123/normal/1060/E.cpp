#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const LL N=200005;
LL n;
struct qq
{
	LL x,y,last;
}e[N*2];LL num,last[N];
void init(LL x,LL y)
{
	num++;
	e[num].x=x;e[num].y=y;
	e[num].last=last[x];
	last[x]=num;
}
LL tot[N];
LL d[2];
LL sum;
void dfs (LL x,LL fa,LL o)
{
	sum=sum+o;d[o&1]++;tot[x]=1;
	for (LL u=last[x];u!=-1;u=e[u].last)
	{
		LL y=e[u].y;
		if (y==fa) continue;
		dfs(y,x,o+1);
		tot[x]=tot[x]+tot[y];
	}
}
LL ans=0;
void dfs1 (LL x,LL fa,LL now,LL o)
{
	//printf("YES:%lld %lld %lld\n",x,now,(d[o^1]+1)/2);
	ans=ans+now/2+(d[o^1]+1)/2;
	for (LL u=last[x];u!=-1;u=e[u].last)
	{
		LL y=e[u].y;
		if (y==fa) continue;
		dfs1(y,x,now+n-2*tot[y],o^1);
	}
}
int main()
{
	num=0;memset(last,-1,sizeof(last));
	scanf("%lld",&n);
	for (LL u=1;u<n;u++)
	{
		LL x,y;
		scanf("%lld%lld",&x,&y);
		init(x,y);init(y,x);
	}
	dfs(1,0,0);
	dfs1(1,0,sum,0);
	printf("%lld\n",ans/2);
	return 0;
}