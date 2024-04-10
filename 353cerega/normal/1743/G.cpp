//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>


using namespace std;


using ll = long long;
using ld = long double;

#define X first
#define Y second

//const ll mod = 1000000007;
const ll mod = 998244353;

vector<ll> F;
ll K = 32;

ll calc(ll p)
{
    for (ll j=K-1;j>0;j--)
    {
        if (F[j]<=p) p -= F[j];
    }
    return 1-p;
}



void solve()
{
    F.resize(K);
    F[0] = 1;
    F[1] = 2;
    for (ll i=2;i<K;i++) F[i] = F[i-1]+F[i-2];
    ll n;
    cin >> n;
    vector<ll> prv, dp;
    prv.push_back(0);
    dp.push_back(1);
    ll q = 0;
    ll S = 1;
    ll L = 1;
    for (ll i=0;i<n;i++)
    {
        string s;
        cin >> s;
        for (ll w=0;w<s.length();w++)
        {
            ll x = S;
            ll cur = s[w]-'0';
            if (cur==0) x -= L;
            for (ll j=0;j<prv.size();j++)
            {
                ll c = calc(q-prv[j]);
                if (c!=cur)
                {
                    swap(prv[j],prv.back());
                    swap(dp[j],dp.back());
                    dp.pop_back();
                    prv.pop_back();
                    j--;
                    continue;
                }
                for (ll b=0;b<K;b++)
                {
                    if (q+1==prv[j]+F[b]) x -= dp[j];
                }
            }
            x %= mod;
            if (x<0) x += mod;
            L = x;
            S = (S+x)%mod;
            q++;
            dp.push_back(x);
            prv.push_back(q);
        }
        cout << L << "\n";
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    ll T;
    T = 1;
    //cin >> T;
    while (T--) solve();
}