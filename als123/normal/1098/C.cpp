#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const LL N=100005;
LL n,k;
LL cnt[N],dep[N];
bool check (LL x)
{
	dep[1]=1;LL cnt=1,lim=1,xx=1;
	for (LL u=2;u<=n;u++)
	{
		if (cnt>=lim)	{cnt=0;lim=lim*x;xx++;}
		cnt++;dep[u]=xx;
	}
/*	for (LL u=1;u<=n;u++) printf("%lld ",dep[u]);
	printf("\n");*/
	LL lalal=0;
	for (LL u=1;u<=n;u++) lalal=lalal+dep[u];
	return lalal<=k;
}
LL d[N];
void solve (LL x)
{
	printf("Yes\n");
	LL xx=2,now=(1+n)*n/2;//
	for (LL u=1;u<=n;u++) cnt[u]=1,dep[u]=u;
	for (LL u=n;u>=1;u--)
	{
		if (now<=k)  break;
		LL t=min(now-k,u-xx);
		LL o=u-t;
		dep[u]=o;cnt[u]=0;
		cnt[o]++;now=now-t;
		if (cnt[xx]>=cnt[xx-1]*x) xx++;
	}
	sort(dep+1,dep+1+n);
	now=1;
	for (LL u=2;u<=n;u++)
	{
		while (dep[u]!=dep[now]+1) now++;
		printf("%lld ",now);
		d[now]++;if (d[now]>=x) now++;
	}
	/*for (LL u=1;u<=n;u++) printf("%lld ",dep[u]);
	printf("\n");*/
}
int main()
{
	scanf("%lld%lld",&n,&k);
	if (k<n+n-1) {printf("No\n");return 0;}
	if (k>(1+n)*n/2) {printf("No\n");return 0;}
	LL l=1,r=n-1,lalal;
	while (l<=r)
	{
		LL mid=(l+r)>>1;
		if (check(mid)) {lalal=mid;r=mid-1;}
		else l=mid+1;
	}
	//check(lalal);
	//printf("lalal:%lld\n",lalal);
	solve(lalal);
	return 0;
}