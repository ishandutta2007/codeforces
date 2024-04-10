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
    ll n;
    cin >> n;
    vector<ll> was(n+1);
    vector<ll> ans;
    for (ll i=2;i<=n;i++)
    {
        if (was[i]==1) continue;
        for (ll j=i;j<=n;j+=i) was[j] = 1;
        ll Q = 1;
        while (Q*i<=n)
        {
            Q *= i;
            ans.push_back(Q);
        }
    }
    cout << ans.size() << "\n";
    for (ll x: ans) cout << x << " ";
}


int main()
{
    ios_base::sync_with_stdio(false);
    ll T;
    T = 1;
    //cin >> T;
    while (T--) solve();
}