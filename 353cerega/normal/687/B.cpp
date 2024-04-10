//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>


using namespace std;


using ll = long long;
using ld = long double;

#define X first
#define Y second

const ll mod = 1000000007;
//const ll mod = 998244353;




void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> pr;
    for (ll i=2;i*i<=k;i++)
    {
        if (k%i!=0) continue;

        ll a = 1;
        while (k%i==0) k /= i, a *= i;
        pr.push_back(a);
    }
    if (k!=1) pr.push_back(k);
    ll sz = pr.size();
    vector<ll> was(sz);
    for (ll i=0;i<n;i++)
    {
        ll x;
        cin >> x;
        for (ll w=0;w<sz;w++)
        {
            if (was[w]==1 or x%pr[w]!=0) continue;
            was[w] = 1;
        }
    }
    for (ll i=0;i<sz;i++)
    {
        if (was[i]==0)
        {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";

}


int main()
{
    ios_base::sync_with_stdio(false);
    ll T;
    T = 1;
    //cin >> T;
    while (T--) solve();
}