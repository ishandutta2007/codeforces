#pragma GCC optimize("Ofast")
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
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (ll i=0;i<n;i++)
    {
        cin >> a[i];
    }
    ll x = 0;
    vector<ll> ans(n);
    for (ll i=n-1;i>=0;i--)
    {
        if (x>=a[i])
        {
            ans[i] = 1;
            continue;
        }
        if (x<a[i])
        {
            if (x+1>q) continue;
            ans[i] = 1;
            x++;
        }
    }
    for (ll i=0;i<n;i++) cout << ans[i];
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    ll T;
    T = 1;
    cin >> T;
    while (T--) solve();
}