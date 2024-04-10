//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>


using namespace std;


using ll = long long;
using ld = long double;

#define X first
#define Y second

//const ll mod = 1000000007;
const ll mod = 998244353;



void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i=0;i<n;i++) cin >> a[i];
    cout << 3*(10-n)*(9-n) << "\n";
}


int main()
{
    ios_base::sync_with_stdio(false);
    ll T;
    T = 1;
    cin >> T;
    while (T--) solve();
}