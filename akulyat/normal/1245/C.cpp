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

void solve(vector<ll> v) {
    ll ans = 1;
    vector<ll> f(2, 1);
    for (ll i = 2; i < ml; i++)
        f.push_back(f[i-1] + f[i-2]), f.back() %= mod;
    for (auto i : v)
        ans *= f[i], ans %= mod;
    cout << ans << endl;
}



int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    n = s.size();

    vector<ll> w(1, 0);
    vector<ll> m(1, 0);
    for (ll i = 0; i < n; i++) {
        w.push_back(0);
        if (s[i] == 'u')
            w.back() = w[i] + 1;
        m.push_back(0);
        if (s[i] == 'n')
            m.back() = m[i] + 1;
        if (s[i] == 'm' || s[i] == 'w') {
            cout << 0;
            exit(0);
        }

    }
    for (ll i = 0; i < n; i++)
        if (m[i + 1] != 0)
            m[i] = 0;
    for (ll i = 0; i < n; i++)
        if (w[i + 1] != 0)
            w[i] = 0;


    vector<ll> v;
    for (auto i : m)
        if (i)
            v.push_back(i);
    for (auto i : w)
        if (i)
            v.push_back(i);

    solve(v);

    return 0;
}