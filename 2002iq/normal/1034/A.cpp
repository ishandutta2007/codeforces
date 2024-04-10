#include <iostream>
#include <algorithm>
using namespace std;
int arr[300005],cnt[15000005],dp[15000005];
bool pr[15000005];
int main()
{
	int n,g=0;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		g=__gcd(g,arr[i]);
	}
	for (int i=0;i<n;i++)
	cnt[arr[i]/g]++;
	for (int i=2;i<=15000000;i++)
	{
		if (!pr[i])
		{
			for (int x=i;x<=15000000;x+=i)
			dp[i]+=cnt[x],pr[x]=1;
		}
	}
	int ans=n;
	for (int i=2;i<=15000000;i++)
	ans=min(ans,n-dp[i]);
	if (ans==n)
	ans=-1;
	printf("%d",ans);
}