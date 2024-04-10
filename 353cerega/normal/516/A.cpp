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
    string s;
    cin >> s;
    vector<ll> C(10);
    for (ll i=0;i<n;i++)
    {
        C[s[i]-'0']++;
    }
    C[2] += 3*C[8];
    C[7] += C[8];
    C[8] = 0;
    C[2] += 2*C[4];
    C[3] += C[4];
    C[4] = 0;
    C[5] += C[6];
    C[3] += C[6];
    C[6] = 0;
    C[7] += C[9];
    C[2] += C[9];
    C[3] += C[9]*2;
    C[9] = 0;
    for (ll w=9;w>1;w--)
    {
        for (ll j=0;j<C[w];j++) cout << w;
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