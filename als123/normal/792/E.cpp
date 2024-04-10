#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
typedef long long LL;
const LL N=505;
const LL MAX=1e9+7;
struct qq
{
	LL l,r;
	qq () {}
	qq (LL _l,LL _r)	{l=_l;r=_r;}
};
bool operator < (qq x,qq y)	{return x.l<y.l;}
vector<qq> vec[N];
LL calc (LL x,LL l,LL r)
{
	LL lalal=r+1;
	while (l<=r)
	{
		LL mid=(l+r)>>1;
		if (x/mid>=x%mid) {r=mid-1;lalal=mid;}
		else l=mid+1;	
	}
	return lalal;
}
LL a[N];
LL mn=-1;
LL n;
void check (LL x)
{
	//printf("check:%lld",x);
	for (LL u=1;u<=n;u++)
	if (a[u]/x<a[u]%x) return ;
	mn=x;
}
int main()
{

	scanf("%lld",&n);
	for (LL u=1;u<=n;u++)
		scanf("%lld",&a[u]);
	LL j,x=a[1];
	for (LL i=1;i<=x;i=j+1)
	{
	j=x/(x/i);
		LL t=calc(x,i,j);
		while (t<=j) {check(t);t++;}
	}
	//printf("%lld",mn);
	LL ans=0;
	for (LL u=1;u<=n;u++) 
	{
		LL t=a[u]%mn;
		LL cnt=a[u]/mn;
		t=cnt-t;
		cnt=cnt-t/(mn+1);
		ans=ans+cnt;
	}
	printf("%lld\n",ans);
	return 0;
}