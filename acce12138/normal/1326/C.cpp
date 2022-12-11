#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,k,a[200111];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	int last=0,ans=1;
	long long sum=0;
	for(int i=1;i<=n;i++)if(a[i]+k>n)
	{
		sum+=a[i];
		if(last)ans=1ll*ans*(i-last)%mod;
		last=i;
	}
	printf("%lld %d\n", sum, ans);
	return 0;
}