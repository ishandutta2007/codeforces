#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const LL N=100005;
LL n;
struct qq
{
	LL x,y;
}a[N];LL nn;
bool cmp (qq x,qq y)
{
	if (x.x==y.x) return x.y>y.y;
	return x.x<y.x;
}
LL ed,q[N];
bool check (qq x,qq y,qq z)
{
	//if ()
	return  (y.y-x.y)*(z.x-y.x)<=(z.y-y.y)*(y.x-x.x);
}
int main()
{
	scanf("%lld",&n);
	for (LL u=1;u<=n;u++)		{scanf("%lld%lld",&a[u].x,&a[u].y);a[u].y=a[u].y-a[u].x*a[u].x;}
	sort(a+1,a+1+n,cmp);
	nn=1;
	for (LL u=2;u<=n;u++)
	{
		if (a[u].x==a[nn].x) continue;
		a[++nn]=a[u];
	}
	if (nn==1)	{printf("0\n");return 0;}
	/*printf("\n");
	for (LL u=1;u<=nn;u++) printf("%lld %lld\n",a[u].x,a[u].y);*/
	ed=2;q[1]=1;q[2]=2;
	for (LL u=3;u<=nn;u++)
	{
		while (ed>=2&&check(a[q[ed-1]],a[q[ed]],a[u])) ed--;
		q[++ed]=u;
	}
	printf("%lld\n",ed-1);
	return 0;
}