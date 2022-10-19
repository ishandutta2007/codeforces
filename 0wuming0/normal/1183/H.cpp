#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll dp[105][105];
ll sum[105];
char s[105];
int main()
{
    int n;
    ll k;
    cin>>n>>k;
    cin>>s;
    for(char c='a';c<='z';c++)for(int i=0;s[i];i++)if(s[i]==c){dp[1][i]++;break;}
    for(int len=2;len<=n;len++)for(char c='a';c<='z';c++)
    {
        ll now=dp[len-1][len-2];
        for(int pos=len-1;pos<n;pos++)
        {
            if(s[pos]==c)
            {
                dp[len][pos]+=now;
                if(dp[len][pos]>=k)dp[len][pos]=k;
                now=0;
            }
            now+=dp[len-1][pos];
            if(now>=k)now=k;
        }
    }
    sum[0]++;
    for(int i=0;i<105;i++)for(int j=0;j<105;j++)sum[i]+=dp[i][j];
    ll ans=0;
    int t=100;
    while(1)
    {
        if(t==-1)
        {
            cout<<-1<<endl;
            return 0;
        }
        if(k<=sum[t])break;
        ans+=sum[t]*(n-t);
        k-=sum[t--];
    }
    ans+=k*(n-t);
    cout<<ans<<endl;
    return 0;
}