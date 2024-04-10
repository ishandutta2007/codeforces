#include <bits/stdc++.h>

using namespace std;

int main()
{
    const long long inf=1000000000000;
	long long n,k;
	scanf("%I64d%I64d",&n,&k);
	char s[n+5];
	scanf("%s",s+1);
	long long dp[n+1][n+1];
	long long sum[n+1][n+1];
	for(int o=0;o<=n;o++) for(int i=0;i<=n;i++) dp[o][i]=sum[o][i]=(o==0?1:0);
	for(int o=1;o<=n;o++)
    {
        vector<int> last(26,0);
        dp[o][o]=dp[o-1][o-1];
        sum[o][o]=dp[o-1][o-1];
        last[(s[o]-'a')]=o;
        for(int i=o+1;i<=n;i++)
        {
            dp[o][i]=sum[o-1][i-1];
            if(last[(s[i]-'a')]>0) dp[o][i]-=sum[o-1][last[(s[i]-'a')]-1];
            dp[o][i]=min(dp[o][i],inf);
            sum[o][i]=sum[o][i-1]+dp[o][i];
            sum[o][i]=min(sum[o][i],inf);
            last[(s[i]-'a')]=i;
        }
    }
    long long cnt=0;
    for(int i=0;i<=n;i++) cnt+=sum[i][n];
    if(cnt<k) printf("-1\n");
    else
    {
        long long res=0;
        long long idx=n;
        while(k>0)
        {
            long long m=min(k,sum[idx][n]);
            res+=(n-idx)*m;
            k-=m;
            idx--;
        }
        printf("%I64d\n",res);
    }
	return 0;
}