#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> dp(n+1,0);
    dp[0]=1;
    const ll mod=1000000007;
    for(int i=0;i<n;i++)
    {
        int a;
        cin >> a;
        vector<int> d;
        for(int j=1;j*j<=a;j++)
        {
            if((a%j)>0) continue;
            d.push_back(j);
            if(j*j!=a) d.push_back(a/j);
        }
        sort(d.begin(),d.end(),greater<int>());
        for(int x:d) if(x<=n) dp[x]=(dp[x]+dp[x-1])%mod;
    }
    ll res=0;
    for(int i=1;i<=n;i++) res=(res+dp[i])%mod;
    cout << res << "\n";
    return 0;
}