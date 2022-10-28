#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=505;

int n, m, b, mod;
int a[N];
int dp[2][N][N];

int32_t main()
{
    IOS;
    cin>>n>>m>>b>>mod;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int ans=0;
    for(int lines=0;lines<=m;lines++)
    {
        for(int bugs=0;bugs<=b;bugs++)
        {
            int reqd=m-lines;
            int totbugs=bugs + reqd * a[n];
            if(totbugs<=b)
            {
                dp[n&1][lines][bugs]=1%mod;
            }
        }
    }
    for(int i=n-1;i>=1;i--)
    {
        for(int lines=m;lines>=0;lines--)
        {
            for(int bugs=b;bugs>=0;bugs--)
            {
                int &ans=dp[i&1][lines][bugs];
                ans=dp[!(i&1)][lines][bugs];
                if(bugs+a[i]<=b)
                    ans+=dp[i&1][lines+1][bugs+a[i]];
                ans%=mod;            
            }
        }
    }
    cout<<dp[1][0][0];
    return 0;
}