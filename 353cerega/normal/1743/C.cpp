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
    string s;
    cin >> s;
    vector<ll> a(n);
    ll A = 0;
    for (ll i=0;i<n;i++)
    {
        cin >> a[i];
        A += a[i];
    }
    ll p = 0;
    for (ll j=1;j<=n;j++)
    {
        if (j==n or s[j]=='0')
        {
            ll mn = mod*mod;
            for (ll q=p;q<j;q++)
            {
                mn = min(mn,a[q]);
            }
            if (p!=0 or s[p]=='0') A -= mn;
            p = j;
        }
    }
    cout << A << "\n";
}


int main()
{
    ios_base::sync_with_stdio(false);
    ll T;
    T = 1;
    cin >> T;
    while (T--) solve();
}