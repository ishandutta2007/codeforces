#include"bits/stdc++.h"
using namespace std;
char s[200005];
int dp[200005];
int main()
{
    cin>>s;
    int n=strlen(s);
    for(int i=n;i<2*n;i++)s[i]=s[i-n];
    dp[2*n-1]=1;
    int ans=0;
    for(int i=2*n-2;i>=0;i--)
    {
        if(s[i]!=s[i+1])
        {
            dp[i]=dp[i+1]+1;
        }
        else dp[i]=1;
        if(i<n)ans=max(ans,min(dp[i],n));
    }
    cout<<ans<<endl;
    return 0;
}