#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
LL n;
int main()
{
	LL T;
	scanf("%lld",&T);
	while (T--)
	{
	scanf("%lld",&n);
	LL ans=0;
	for (LL a=2;a<=n;a++)
	{
		LL b=a*a-1,c;
		if (b&1) continue;
		b/=2;c=b+1;
		if (c>n) break;
		ans++;
		//printf("%lld %lld %lld\n",a,b,c);
	}
	printf("%lld\n",ans);
	}
	return 0;
}