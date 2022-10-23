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
const int N = 2e5 + 10;
const ll mod = 1e9 + 7;
ll ifact[N],fact[N],inv[N];

void build(int h)
{
    inv[1]=ifact[0]=ifact[1]=fact[0]=fact[1]=1;
    for (int i=2;i<=h;i++)
    {
        inv[i]=mod-mod/i*inv[mod%i]%mod;
        ifact[i]=ifact[i-1]*inv[i]%mod;
        fact[i]=fact[i-1]*i%mod;
    }
}

ll C(int t,ll h) {
    if (t > h) return 0;
    return fact[h]*ifact[t]%mod*ifact[h-t]%mod;
}

ll p[N];

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    build(2e5);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        p[0] = 1;
        for (int i = 1; i <= n; ++i) p[i] = C(i, n - (ll)(i - 1) * (k - 1)) * ifact[n] % mod * fact[i] % mod * fact[n - i] % mod;
        ll res = 0;
        for (int i = 1; i <= n; ++i) res = (res + (p[i - 1] - p[i]) % mod * i + mod * mod) % mod;
        cout << res << "\n";
    }
    return 0;
}