#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k,m;
    cin >> n >> k >> m;
    vector<array<int,3>> v(m);
    for(int i=0;i<m;i++) for(int j=0;j<3;j++) cin >> v[i][j];
    ll res=1;
    const ll mod=998244353;
    for(int o=0;o<k;o++)
    {
        vector<int> bad(n+2,0);
        vector<int> mx(n+2,0);
        for(auto [l,r,x]:v)
        {
            if(x&(1<<o))
            {
                bad[l]++;
                bad[r+1]--;
            }
            else mx[r]=max(mx[r],l);
        }
        vector<ll> dp(n+2,0);
        vector<ll> sum(n+2,0);
        dp[0]=sum[0]=1;
        for(int i=1;i<=n+1;i++)
        {
            bad[i]+=bad[i-1];
            mx[i]=max(mx[i-1],mx[i]);
            if(bad[i]==0)
            {
                dp[i]=sum[i-1];
                if(mx[i-1]>0) dp[i]-=sum[mx[i-1]-1];
                dp[i]%=mod;
                if(dp[i]<0) dp[i]+=mod;
            }
            sum[i]=(sum[i-1]+dp[i])%mod;
        }
        res=(res*dp[n+1])%mod;
    }
    cout << res << "\n";
    return 0;
}