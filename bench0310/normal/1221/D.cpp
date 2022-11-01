#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
    {
        int n;
        scanf("%d",&n);
        int a[n];
        long long b[n];
        for(int i=0;i<n;i++) scanf("%d%I64d",&a[i],&b[i]);
        long long dp[n][3];
        for(int o=0;o<n;o++) for(int i=0;i<3;i++) dp[o][i]=1000000000000000001;
        for(int i=0;i<3;i++) dp[0][i]=b[0]*i;
        for(int o=1;o<n;o++)
        {
            for(int i=0;i<3;i++)
            {
                for(int j=0;j<3;j++)
                {
                    if((a[o-1]+j)==(a[o]+i)) continue;
                    dp[o][i]=min(dp[o][i],dp[o-1][j]+b[o]*i);
                }
            }
        }
        printf("%I64d\n",min(min(dp[n-1][0],dp[n-1][1]),dp[n-1][2]));
    }
	return 0;
}