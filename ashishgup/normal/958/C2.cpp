#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=20005;
const int M=51;

int n, storek, p;
int a[N], dp[2][M][101];

int32_t main()
{
    IOS;
    cin>>n>>storek>>p;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int j=0;j<=storek;j++)
    {
        for(int k=0;k<p;k++)
        {
            dp[(n+1)&1][j][k]=k;
        }
    }
    for(int i=n;i>=1;i--)
    {
        for(int j=1;j<=storek;j++)
        {
            for(int k=0;k<p;k++)
            {
                int &ans=dp[i&1][j][k];
                ans=dp[(i+1)&1][j][(k+a[i])%p];
                if(j<storek)
                {
                    ans=max(ans, k + dp[(i+1)&1][j+1][a[i]%p]);
                }
            }
        }
    }
    int ans=dp[1][1][0];
    cout<<ans;
    return 0;
}