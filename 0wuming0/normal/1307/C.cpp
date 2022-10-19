#include"bits/stdc++.h"
using namespace std;
long long num[1005];
long long dp[1005][1005];
char s[100005];
int main()
{
    cin>>s;
    long long ans=0;
    for(int i=0;s[i];i++)
    {
        for(int c='a';c<='z';c++)
        {
            dp[c][s[i]]+=num[c];
            ans=max(ans,dp[c][s[i]]);
        }
        num[s[i]]++;
        ans=max(ans,num[s[i]]);
    }
    cout<<ans<<endl;
    return 0;
}