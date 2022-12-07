#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const LL N=200005*2;
LL n,k;
bool ok[N];
struct qq
{
	LL x,y,last;
}e[N];LL num,last[N];
void init (LL x,LL y)
{
	num++;
	e[num].x=x;e[num].y=y;
	e[num].last=last[x];
	last[x]=num;
}
LL tot[N];//
LL ans=0;
void dfs (LL x,LL fa)
{
	tot[x]=ok[x];
	for (LL u=last[x];u!=-1;u=e[u].last)
	{
		LL y=e[u].y;
		if (y==fa) continue;
		dfs(y,x);
		tot[x]=tot[x]+tot[y];
	}
}
void solve (LL x,LL fa)
{
	for (LL u=last[x];u!=-1;u=e[u].last)
	{
		LL y=e[u].y;
		if (y==fa) continue;
		ans=ans+min(tot[y],k-tot[y]);
		solve(y,x);
	}
}
int main()
{
	num=0;memset(last,-1,sizeof(last));
	memset(ok,false,sizeof(ok));
	scanf("%lld%lld",&n,&k);k<<=1;
	for (LL u=1;u<=k;u++)
	{
		LL x;
		scanf("%lld",&x);
		ok[x]=true;
	}
	for (LL u=1;u<n;u++)
	{
		LL x,y;
		scanf("%lld%lld",&x,&y);
		init(x,y);init(y,x);
	}
	dfs(1,0);
	solve(1,0);
	printf("%lld\n",ans);
	return 0;
}