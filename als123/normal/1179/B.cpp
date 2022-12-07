#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<set>
using namespace std;
typedef long long LL;
const LL N=5e5+5;
const LL MAX=1e15;
LL n,m;
int main()
{
	scanf("%lld%lld",&n,&m);
	LL x1=1,y1=1;
	LL x2=n,y2=m;
	for (LL u=1;u<=n*m/2;u++)
	{
		printf("%lld %lld\n",x1,y1);
		y1++;
		if (y1>m)	{y1=1;x1++;}
		LL X=x2,Y=y2;
		printf("%lld %lld\n",x2,y2);
		y2--;
		if (y2<1)	{y2=m;x2--;}
	}
	if ((n*m)&1) printf("%lld %lld\n",x1,y1);
	return 0;
}