#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(),vr.end()
#define vi vector<int>
#define vll vector<ll>
const int N = 1e3 + 10;
ll ifact[N],fact[N],inv[N],mod;

void precal(int h)
{
    inv[1]=ifact[0]=ifact[1]=fact[0]=fact[1]=1;
    for (int i=2;i<=h;i++)
    {
        inv[i]=mod-mod/i*inv[mod%i]%mod;
        ifact[i]=ifact[i-1]*inv[i]%mod;
        fact[i]=fact[i-1]*i%mod;
    }
}

ll C(int t,int h) { return fact[h]*ifact[t]%mod*ifact[h-t]%mod; }

ll cost[N],dp[N][N];

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n>>mod;
    precal(n);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=i;j++) cost[i]=(cost[i]+C(j-1,i-1))%mod;
    dp[1][1]=1;
    for (int i=2;i<=n;i++)
    {
        dp[i][i]=cost[i]*ifact[i]%mod;
        for (int j=1;j<i;j++)
            for (int t=1;t<=j;t++) dp[i][j]=(dp[i][j]+dp[i-t-1][j-t]*cost[t]%mod*ifact[t])%mod;
    }
    ll res=0;
    for (int i=1;i<=n;i++) res=(res+dp[n][i]*fact[i])%mod;
    cout<<res;
    return 0;
}