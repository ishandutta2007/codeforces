#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	long long a[n][2];
	for(int o=0;o<2;o++) for(int i=0;i<n;i++) scanf("%I64d",&a[i][o]);
	long long dp[n][2];
	dp[0][0]=a[0][0];
	dp[0][1]=a[0][1];
	for(int i=1;i<n;i++)
    {
        dp[i][0]=max(dp[i-1][0],dp[i-1][1]+a[i][0]);
        dp[i][1]=max(dp[i-1][1],dp[i-1][0]+a[i][1]);
    }
    printf("%I64d\n",max(dp[n-1][0],dp[n-1][1]));
	return 0;
}