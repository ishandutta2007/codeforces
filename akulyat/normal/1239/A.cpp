#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair<ll, ll> pll;

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7;


ll n, i, j, m;
vector<ll> f;
bool viv = false;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    if (n > m)
        swap(n, m);
    f.push_back(1);
    f.push_back(1);
    for (int i = 2; i < 200*kk; i++)
        f.push_back(f[i-1] + f[i-2]), f.back() %= mod;

    ll ans = 2 * f[n];
    ans += 2 * (f[m] - 1);
    ans %= mod;
    cout << ans;



    return 0;
}