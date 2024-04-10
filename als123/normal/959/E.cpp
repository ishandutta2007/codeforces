#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
LL n;
int main()
{
	scanf("%I64d",&n);
	LL ans=0;
	for (LL u=0;u<=60;u++)
	{
		//printf("%I64d %I64d\n",(n/2),(1LL<<u));
		ans=ans+(n/2)*(1LL<<u);
		n=n-n/2;
	}
	printf("%I64d\n",ans);
	return 0;
}