#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<vector<int>> l(n+1,vector<int>(m+1,0));
    vector<vector<int>> r(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++)
    {
        int k;
        cin >> k;
        while(k--)
        {
            int a,b;
            cin >> a >> b;
            for(int j=a;j<=b;j++)
            {
                l[i][j]=a;
                r[i][j]=b;
            }
        }
    }
    vector<vector<int>> dp(m+2,vector<int>(m+1,0));
    for(int sz=1;sz<=m;sz++)
    {
        for(int i=1;i+sz-1<=m;i++)
        {
            int j=i+sz-1;
            for(int k=i;k<=j;k++)
            {
                int c=0;
                for(int t=1;t<=n;t++) c+=(i<=l[t][k]&&r[t][k]<=j);
                dp[i][j]=max(dp[i][j],dp[i][k-1]+c*c+dp[k+1][j]);
            }
        }
    }
    cout << dp[1][m] << "\n";
    return 0;
}