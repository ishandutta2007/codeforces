#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=6e5+5;
const int offset=3e5;
const int MOD=1e9+7;

int a, b, k, t;
int dp[2][2][N];

int32_t main()
{
    IOS;
    cin>>a>>b>>k>>t;
    for(int player=0;player<=1;player++)
    {
        for(int diff=-offset;diff<=offset;diff++)
        {
            dp[player][t+1&1][diff+offset]=(diff>0);
            dp[player][t+1&1][diff+offset]+=dp[player][t+1&1][diff+offset-1];
            dp[player][t+1&1][diff+offset]%=MOD;
        }
    } 
    for(int turn=t;turn>=1;turn--)
    {
        for(int diff=-offset;diff<=offset;diff++)
        {
            int player=1;
            int &ans=dp[player][turn&1][diff+offset];
            ans=dp[player^1][turn+1&1][diff+k+offset] - dp[player^1][turn+1&1][diff-k-1+offset];
            ans+=MOD;
            ans%=MOD;
            ans+=dp[player][turn&1][diff-1+offset];
            ans%=MOD;
        }
        for(int diff=-offset;diff<=offset;diff++)
        {
            int player=0;
            int &ans=dp[player][turn&1][diff+offset];
            ans=dp[player^1][turn&1][diff+k+offset] - dp[player^1][turn&1][diff-k-1+offset];
            ans+=MOD;
            ans%=MOD;
            ans+=dp[player][turn&1][diff-1+offset];
            ans%=MOD;
        }
    }
    int ans=dp[0][1][a-b+offset]-dp[0][1][a-b-1+offset];
    ans+=MOD;
    ans%=MOD;
    cout<<ans;
    return 0;
}