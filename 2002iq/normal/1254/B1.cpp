#include <bits/stdc++.h>
using namespace std;
int n,arr[1000005];
long long b[1000005];
long long get(long long x)
{
	for (int i=0;i<n;i++)
	b[i]=arr[i]%x;
	long long ret=0;
	for (int i=0;i<n-1;i++)
	{
		ret+=min(b[i],x-b[i]);
		b[i+1]=(b[i+1]+b[i])%x;
	}
	return ret;
}
int main()
{
	scanf("%d",&n);
	long long sum=0,ans=1e18;
	for (int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		sum+=arr[i];
	}
	if (sum==1)
	{
		printf("-1");
		return 0;
	}
	for (int i=2;1LL*i*i<=sum;i++)
	{
		if (sum%i==0)
		{
			ans=min(ans,get(i));
			while (sum%i==0)
			sum/=i;
		}
	}
	if (sum!=1)
	ans=min(ans,get(sum));
	printf("%I64d",ans);
}