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


ll n, i, j;
vector<ll> m;
bool viv = false;

void solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> v;
    for (ll i = 0; i < n; i++)
        if (s[i] == '1')
            v.push_back(i);
    if (v.empty()) {
        cout << n << '\n';
        return;
    }

    ll a = min(v[0], n - 1 - v.back());
    ll ans = 2 * n - 2 * a;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}