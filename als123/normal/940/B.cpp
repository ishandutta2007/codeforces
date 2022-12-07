#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long LL;
LL n,k,a,b;
int main()
{
	scanf("%I64d%I64d%I64d%I64d",&n,&k,&a,&b);
	if (k==1)
	{
		printf("%I64d ",(n-1)*a);
		return 0;
	}
	LL ans=0;
	while (n!=1)
	{
		if (n%k==0)
		{
			LL tt=n/k;
			ans=ans+min((n-tt)*a,b);
			n=tt;
		}
		else
		{
			if (n<k)
			{
				ans=ans+(n-1)*a;
				n=1;
			}
			else
			{
				LL lalal=n%k;
				ans=ans+lalal*a;
				n=n-lalal;
			}
		}
	}
	printf("%I64d\n",ans);
	return 0;
}