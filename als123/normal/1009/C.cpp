#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
LL n,m;
LL sum=0;
int main()
{
	scanf("%I64d%I64d",&n,&m);
	LL a=0,b=0;
	for (LL u=1;u<=n;u++) a=a+u-1;
	LL mid=(n+1)/2;
	for (LL u=1;u<=n;u++) b=b+abs(u-mid);
	for (LL u=1;u<=m;u++)
	{
		LL x,d;
		scanf("%I64d%I64d",&x,&d);
		sum=sum+x*n;
		if (d>0)//??????
		{
			sum=sum+d*a;
		}
		else sum=sum+d*b;
	}
	printf("%.8lf",(double)sum/n);
	return 0;
}