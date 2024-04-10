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
 
ll n, m, i, j;
vector<vector<pll>> reb;
vector<ll> col, sz, ans, fre;
vector<bool> used;
vector<ll> q;
bool viv = false;
 
void DFS(ll v, ll c) {
    col[v] = c;
    sz[v] = 1;
    ll l = reb[v].size();
    for (ll i = 0; i < l; i++) {
        ll s = reb[v][i].F;
        if (col[s] == -1) {
            DFS(s, c  +1);
            sz[v] += sz[s];
        }
    }
    q.push_back(v);
}
 
void work(ll v) {
    ll sum = 0;
    ll lfree = 1;
    for (auto s : reb[v])
        if (col[s.F] > col[v]) {
                lfree += fre[s.F];
                ans[v] += ans[s.F];
                sum += s.S * (fre[s.F] & 1);
            }
    if (lfree != 1)
        lfree -= 2;
    ans[v] += sum;
    fre[v] = lfree;
}
 
void solve() {
    cin >> n;
    n *= 2;
    m = n - 1;
    reb.clear();
    reb.resize(n);
    for (i = 0; i < m; i++) {
        long a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        reb[a].push_back({b, c});
        reb[b].push_back({a, c});
    }
    col.clear();
    col.assign(n, -1);
    sz.clear();
    sz.resize(n, 0);
    ans.clear();
    ans.resize(n, 0);
    fre.clear();
    fre.resize(n, 0);
    q.clear();
 
 
    DFS(0, 0);
    used.clear();
    used.resize(n, false);
    for (auto v : q)
        work(v);
 
    ll mi = ans[0];
    ll ma = 0;
    for (ll i = 0; i < n; i++) {
        for (auto s : reb[i])
            if (col[s.F] > col[i]) {
                ll lsz = sz[s.F];
                lsz = min(lsz, n - lsz);
                ma += lsz * s.S;
            }
    }
    cout << mi << ' ' << ma << endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
        solve();
 
 
 
 
 
    return 0;
}