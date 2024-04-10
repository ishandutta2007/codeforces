#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    vector<vector<vector<bool>>> dp(n,vector<vector<bool>>(n,vector<bool>(n,0)));
    vector<vector<bool>> ok(n,vector<bool>(n,0));
    vector<vector<bool>> g(n,vector<bool>(n,0));
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) g[i][j]=(gcd(a[i],a[j])>1);
    for(int i=0;i<n;i++)
    {
        dp[i][i][i]=1;
        if(i>0&&g[i][i-1]==1) ok[i-1][i]=1;
        if(i<n-1&&g[i][i+1]==1) ok[i+1][i]=1;
    }
    for(int o=2;o<=n;o++)
    {
        for(int l=0;l+o-1<n;l++)
        {
            int r=l+o-1;
            dp[l][r][l]=ok[l][r];
            for(int i=l+1;i<r;i++) dp[l][r][i]=(ok[i][l]&&ok[i][r]);
            dp[l][r][r]=ok[r][l];
            for(int i=l;i<=r;i++)
            {
                if(dp[l][r][i]==0) continue;
                if(l>0&&g[i][l-1]==1) ok[l-1][r]=1;
                if(r<n-1&&g[i][r+1]==1) ok[r+1][l]=1;
            }
        }
    }
    bool res=0;
    for(int i=0;i<n;i++) res|=dp[0][n-1][i];
    if(res==1) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}