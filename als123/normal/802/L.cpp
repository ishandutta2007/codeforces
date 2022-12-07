#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const LL MOD=1e9+7;
const LL N=100005*2;
struct qq
{
	LL x,y,last;
}e[N];LL num,last[N];
LL pow (LL x,LL y)
{
	if (y==1) return x;
	LL lalal=pow(x,y>>1);
	lalal=lalal*lalal%MOD;
	if (y&1) lalal=lalal*x%MOD;
	return lalal;
}
void init (LL x,LL y)
{
	num++;
	e[num].x=x;e[num].y=y;
	e[num].last=last[x];
	last[x]=num;
}
LL k[N],b[N],d[N];
void dfs (LL x,LL fa)
{
	for (LL u=last[x];u!=-1;u=e[u].last)
	{
		LL y=e[u].y;
		if (y==fa) continue;
		dfs(y,x);
	}
	if (d[x]==1) return ;
	LL tmp=pow(k[x],MOD-2);
	k[fa]=(k[fa]-tmp+MOD)%MOD;
	b[fa]=(b[fa]+b[x]*tmp%MOD)%MOD;
}
int main()
{
	num=0;memset(last,-1,sizeof(last));
	LL n;
	scanf("%I64d",&n);
	for (LL u=1;u<n;u++)
	{
		LL x,y,z;
		scanf("%I64d%I64d%I64d",&x,&y,&z);
		x++;y++;
		init(x,y);init(y,x);
		k[x]++;k[y]++;
		d[x]++;d[y]++;
		b[x]+=z;b[y]+=z;
	}
	dfs(1,0);
	printf("%I64d\n",b[1]*pow(k[1],MOD-2)%MOD);
	return 0;
}