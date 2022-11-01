#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const ll inf=(1ll<<60);
    int n;
    cin >> n;
    vector<ll> dp(61,-inf);
    ll res=-inf;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin >> a;
        vector<ll> m(61,0);
        m[0]=max(0ll,dp[0]);
        for(int j=1;j<=60;j++) m[j]=max(m[j-1],dp[j]);
        for(int j=0;j<=60;j++)
        {
            if(j<a+30) dp[j]=-inf;
            else dp[j]=m[j]+a;
            res=max(res,dp[j]-(j-30));
        }
    }
    cout << res << "\n";
    return 0;
}