#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const LL N=300005;
LL a[N];
LL n;
int main()
{
	scanf("%lld",&n);
	for (LL u=1;u<=n;u++) scanf("%lld",&a[u]);
	LL sum=0,ans=0; 
	for (LL u=1;u<=n;u++)
	{
		while (sum>=1&&a[u]>=2)	{a[u]-=2;sum--;ans++;}
		ans=ans+a[u]/3;
		a[u]%=3;
		sum=sum+a[u];
	}
	printf("%lld\n",ans);
	return 0;
}