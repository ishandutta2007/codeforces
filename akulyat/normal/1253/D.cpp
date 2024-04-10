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

ll n, m, i, j;
vector<ll> reb[gs + 10];
vector<ll> col, tc;
bool viv = false;

void DFS(ll v, ll c) {
    col[v] = c;
    ll l = reb[v].size();
    for (ll i = 0; i < l; i++) {
        ll s = reb[v][i];
        if (col[s] == -1) {
            DFS(s, c);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (i = 0; i < m; i++) {
        long a, b;
        cin >> a >> b;
        a--; b--;
        reb[a].push_back(b);
        reb[b].push_back(a);
    }
    ll tc = 0;
    col.resize(n, -1);
    for (ll i = 0; i < n; i++)
        if (col[i] == -1)
            DFS(i, tc), tc++;

    vector<pll> seg(tc, {inf, -1});
    for (ll i = 0; i < n; i++)
        seg[col[i]].F = min(seg[col[i]].F, i),
        seg[col[i]].S = max(seg[col[i]].S, i);

    sort(seg.begin(), seg.end());

    ll r = -1;
    ll ans = 0;
    for (auto p : seg) {
        if (p.F <= r)
            ans++;
        r = max(r, p.S);
    }
    cout << ans << endl;





    return 0;
}