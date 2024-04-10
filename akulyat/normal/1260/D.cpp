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


ll n, i, j, len, k, t;
vector<ll> m, l, r, p;
vector<pair<pll, ll>> all;
bool viv = false;

bool can(ll kol) {
    ll mi = m[kol - 1];
    ll go_to = 0;
    vector<pll> seg;
    for (ll i = 0; i < k; i++) {
        if (all[i].S > mi) {
            seg.push_back(all[i].F);
        }
    }
    ll sl = 0, sr = 0;
    ll res = len + 1;
    for (auto p : seg) {
        if (sr < p.F) {
            res += 2 * (sr - sl);
            sl = p.F;
            sr = p.S;
        } else
            sr = max(sr, p.S);
    }
    res += 2 * (sr - sl);
    if (viv)
        cout << "with " << kol << "(" << mi << ")" << " can " << res << endl;
    if (res <= t)
        return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> len >> k >> t;
    for (i = 0; i < n; i++) {
        ll a;
        cin >> a;
        m.push_back(a);
    }
    sort(m.rbegin(), m.rend());
    for (ll i = 0; i < k; i++) {
        ll locl, locr, locp;
        cin >> locl >> locr >> locp;
        locl--;
        all.push_back({{locl, locr}, locp});
    }
    sort(all.begin(), all.end());
    ll lv = 0;
    ll rv = n + 1;
    while (lv + 1 < rv) {
        ll mv = lv + rv >> 1;
        if (can(mv))
            lv = mv;
        else
            rv = mv;
    }

    cout << lv;


    return 0;
}