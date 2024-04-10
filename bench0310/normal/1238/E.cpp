#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    char s[n+1];
    scanf("%s",s);
    int cnt[m][m];
    for(int o=0;o<m;o++) for(int i=0;i<m;i++) cnt[o][i]=0;
    for(int i=0;i<n-1;i++)
    {
        if(s[i]!=s[i+1])
        {
            cnt[s[i]-'a'][s[i+1]-'a']++;
            cnt[s[i+1]-'a'][s[i]-'a']++;
        }
    }
    vector<long long> dp(1<<m,m*n);
    dp[0]=0;
    for(int o=0;o<(1<<m)-1;o++)
    {
        long long pos=__builtin_popcount(o);
        for(int i=0;i<m;i++)
        {
            if(o&(1<<i)) continue;
            long long sum=0;
            for(int j=0;j<m;j++)
            {
                if(o&(1<<j)) sum+=(pos*cnt[i][j]);
                else sum-=(pos*cnt[i][j]);
            }
            dp[o^(1<<i)]=min(dp[o^(1<<i)],dp[o]+sum);
        }
    }
    printf("%I64d\n",dp[(1<<m)-1]);
    return 0;
}