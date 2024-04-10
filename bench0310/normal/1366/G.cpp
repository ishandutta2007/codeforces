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
    const short inf=(1<<14);
    vector dp(n+1,vector(m+1,short(inf)));
    dp[0][0]=0;
    vector<short> to(n,-1);
    stack<int> st;
    for(int i=n-1;i>=0;i--)
    {
        if(isalpha(s[i]))
        {
            if(!st.empty())
            {
                to[i]=(st.top()-i+1);
                st.pop();
            }
        }
        else st.push(i);
    }
    auto chmin=[&](short &a,short b){a=min(a,b);};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            chmin(dp[i+1][j],dp[i][j]+1);
            if(j<m&&s[i]==t[j]) chmin(dp[i+1][j+1],dp[i][j]);
            if(to[i]!=-1) chmin(dp[i+to[i]][j],dp[i][j]);
        }
    }
    cout << dp[n][m] << "\n";
    return 0;
}