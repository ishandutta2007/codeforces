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

void ans(ll a, ll b, ll c) {
    cout << a << ' ' << b << ' ' << c << '\n';
}

void solve() {
    cin >> n;
    unordered_set<ll> s;
    m.clear();
    for (i = 0; i < n; i++) {
        ll a;
        cin >> a;
        m.push_back(a);
    }
    vector<ll> z;
    while (m.size() * 2 > n)
        z.push_back(m.back()), m.pop_back();
    while (m.size() && m.back() == z.back())
        m.pop_back();
    for (auto i : m)
        s.insert(i);
    if (s.size() < 3) {
        ans(0, 0, 0);
        return;
    }
    reverse(m.begin(), m.end());
    ll gv = m.back();
    m.pop_back();
    ll g = 1;
    while (m.back() == gv)
        m.pop_back(), g++;
    reverse(m.begin(), m.end());
    m.push_back(-1);
    ll now = 1;
    vector<pll> vals;
    for (ll i = 1; i < m.size(); i++) {
        if (m[i] != m[i-1])
            vals.push_back({i, m.size() - i - 1});
    }
    if (viv)
        cout << "Gold " << g << " with " << gv << '\n';
    for (auto p : vals) {
        if (viv)
            cout << "See " << p.F << ' ' << p.S << '\n';
        if (p.F > g && p.S > g) {
            ans(g, p.F, p.S);
            return;
        }
    }
    ans(0, 0, 0);
}

int main() {
//    viv = true;
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}