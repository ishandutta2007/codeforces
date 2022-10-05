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


ll n, i, j, h;
vector<int> m;
vector<pll> p;
set<pll> s;
bool viv = false;

bool can(ll k) {
    int mx = 0;
    for (int i = 0; i < k; i++)
        mx = max(mx, m[m.size() - 1 - i]);
    auto z = s.lower_bound({mx, -1});
    if (z != s.end() && (*z).S >= k)
        return true;
    return false;
}

void solve() {
    cin >> n;
    m.clear();
    m.resize(n);
    for (auto &i : m)
        cin >> i;
    cin >> h;
    p.clear();
    p.resize(h);
    for (auto &i : p)
        cin >> i.F >> i.S;
    sort(p.begin(), p.end());
    ll mx = 0;
    for (ll i = h - 1; i >= 0; i--) {
        mx = max(mx, p[i].S);
        p[i].S = mx;
    }
    s.clear();
    for (auto i : p)
        s.insert(i);

    int gm = 0;
    for (auto i : m)
        gm = max(gm, i);
    if (gm > p.back().F) {
        cout << -1 << '\n';
        return;
    }

    reverse(m.begin(), m.end());
    ll ans = 0;
    while (m.size()) {
        if (viv)
            cout << "MMMMMMMMMMM" << endl;
        ll r = 1;
        while (r <= m.size() && can(r))
            r <<= 1;

        r = min(r, (ll)m.size() + 1);
        ll l = (r - 1) / 2;
        l = max(l, 1ll);
        if (viv) {
            cout << "Find btw: " << l << ' ' << r << endl;
        }
        while (l + 1 < r) {
            ll mi = l + r >> 1;
            if (can(mi))
                l = mi;
            else
                r = mi;
        }

        for (ll j = 0; j < l; j++)
            m.pop_back();
        ans++;
    }
    if (viv)
        cout << "________ ";
    cout << ans << '\n';
    if (viv)
        cout << endl;
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