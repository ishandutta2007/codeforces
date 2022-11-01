#include <bits/stdc++.h>

using namespace std;

int main()
{
    const long long mod=1000000007;
    char s[100005];
    scanf("%s",s);
    int n=strlen(s);
    long long dp[n+1];
    dp[0]=dp[1]=1;
    for(int i=2;i<=n;i++) dp[i]=(dp[i-2]+dp[i-1])%mod;
    long long res=1;
    int cnt=0;
    char last=s[0];
    for(int i=0;i<n;i++)
    {
        if(s[i]==last) cnt++;
        else
        {
            if(last=='u'||last=='n') res=(res*dp[cnt])%mod;
            if(last=='m'||last=='w') res=0;
            last=s[i];
            cnt=1;
        }
    }
    if(last=='u'||last=='n') res=(res*dp[cnt])%mod;
    if(last=='m'||last=='w') res=0;
    printf("%I64d\n",res);
    return 0;
}