#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    vector<int> c(n,0);
    vector<int> dp(26,0);
    int x=1;
    for(int i=0;i<n;i++)
    {
        int m=0;
        for(int j=s[i]-'a'+1;j<26;j++) m=max(m,dp[j]);
        c[i]=m+1;
        x=max(x,c[i]);
        dp[s[i]-'a']=max(dp[s[i]-'a'],m+1);
    }
    cout << x << "\n";
    for(int i=0;i<n;i++) cout << c[i] << " \n"[i==n-1];
    return 0;
}