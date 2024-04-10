#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s,t;
    cin >> s >> t;
    int n=s.size();
    int m=t.size();
    s="$"+s;
    t="$"+t;
    for(int i=0;i<n-m;i++) t+="*";
    auto eq=[&](char a,char b)->bool{return (a==b||a=='*'||b=='*');};
    vector<vector<int>> dp(n+2,vector<int>(n+2,0));
    for(int i=0;i<=n;i++) dp[i+1][i]=1;
    const int mod=998244353;
    for(int sz=1;sz<=n;sz++)
    {
        for(int l=1;l+sz-1<=n;l++)
        {
            int r=l+sz-1;
            dp[l][r]=(eq(s[sz],t[l])*dp[l+1][r]+eq(s[sz],t[r])*dp[l][r-1])%mod;
        }
    }
    int res=0;
    for(int i=m;i<=n;i++) res=(res+dp[1][i])%mod;
    cout << res << "\n";
    return 0;
}