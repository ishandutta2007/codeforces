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


ll n, m;
vector<pair<pll, ll>> v;
vector<ll> delt;
bool viv = false;

void solve() {
    cin >> n >> m;
    delt.resize(n, 0);
    for (ll i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        v.push_back({{a, b}, c});
        delt[a] -= c;
        delt[b] += c;
    }
    vector<pll> tos;
    for (ll i = 0; i < n; i++)
        tos.push_back({delt[i], i});
    sort(tos.begin(), tos.end());
    vector<pll> mr, ls;
    vector<pair<pll, ll>> ans;
    for (ll i = 0; i < n; i++) {
        if (tos[i].F < 0)
            ls.push_back(tos[i]);
        if (tos[i].F > 0)
            mr.push_back(tos[i]);
    }
    reverse(ls.begin(), ls.end());


    // for (auto p : ls) {
    //     cout << p.F << ' ' << p.S << "; ";
    // }
    // cout << endl;
    // for (auto p : mr) {
    //     cout << p.F << ' ' << p.S << "; ";
    // }
    // cout << endl;
    while (ls.size()) {
        ll d1 = -ls.back().F;
        ll d2 = mr.back().F;
        ll d = min(d1, d2);
        ans.push_back({{ls.back().S, mr.back().S}, d});
        d1 -= d;
        d2 -= d;
        ls.back().F = -d1;
        mr.back().F = d2;
        if (!d1)
            ls.pop_back();
        if (!d2)
            mr.pop_back();
    }
    cout << ans.size() << '\n';
    for (auto p : ans) {
        cout << p.F.F + 1 << ' ';
        cout << p.F.S + 1 << ' ';
        cout << p.S << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t = 1;
    while (t--)
    	solve();

    return 0;
}