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
const long long gs = 500 * kk;

ll n, m, i, j, k;
vector<vector<pll>> reb;
vector<ll> col, tc, q, up, nup;
vector<pll> p;
bool viv = false;

void DFS(ll v, ll c) {
    col[v] = c;
    ll l = reb[v].size();
    for (ll i = 0; i < l; i++) {
        ll s = reb[v][i].F;
        if (col[s] == -1) {
            DFS(s, c + 1), p[s] = {v, reb[v][i].S};
        }
    }
    q.push_back(v);
}

void work(ll v) {
    ll sum = 0;
    vector<ll> d;
    for (auto s : reb[v])
        if (col[s.F] > col[v])
            sum += nup[s.F], d.push_back(up[s.F] - nup[s.F]);
    sort(d.rbegin(), d.rend());
    for (ll i = 0 ; i < min(k - 1, (ll)d.size()); i++)
        sum += max(d[i], 0ll);
    nup[v] = sum;
    if (d.size() >= k)
        nup[v] += max(d[k - 1], 0ll);
    up[v] = sum + p[v].S;
    if (viv)
        cout << "__" << v << ' ' << nup[v] << ' ' << up[v] << endl;
}

void solve() {
    cin >> n >> k;
    m = n - 1;
    reb.clear();
    reb.resize(n);
    for (i = 0; i < m; i++) {
        long a, b;
        ll c;
        cin >> a >> b >> c;
        a--; b--;
        reb[a].push_back({b, c});
        reb[b].push_back({a, c});
    }
    col.clear();
    col.assign(n, -1);
    q.clear();
    p.clear();
    p.resize(n, {-1, 0});
    p[0] = {0, -mod};
    DFS(0, 0);
    up.resize(n);
    nup.resize(n);
    for (auto v : q)
        work(v);
    cout << nup[0] << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
        solve();





    return 0;
}