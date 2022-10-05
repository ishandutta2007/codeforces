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

ll n, m, i, j, v1, v2;
vector<vector<ll>> reb;
vector<ll> col1, col2;
vector<bool> was1, was2;
bool viv = false;

void DFS1(ll v, ll c, bool can) {
    col1[v] = c;
    was1[v] = can;
    if (viv)
        cout << "DFS1 in " << v << " with " << can << ' ' << c << endl;
    ll l = reb[v].size();
    for (ll i = 0; i < l; i++) {
        ll s = reb[v][i];
        if (col1[s] == -1 && (can || s != v2)) {
            DFS1(s, c + 1, can);
        }
    }
}

void DFS2(ll v, ll c, bool can) {
    col2[v] = c;
    was2[v] = can;
    if (viv)
        cout << "DFS2 in " << v << " with " << can << ' ' << c << endl;
    ll l = reb[v].size();
    for (ll i = 0; i < l; i++) {
        ll s = reb[v][i];
        if (col2[s] == -1 && (can || s != v1)) {
            DFS2(s, c + 1, can);
        }
    }
}


void solve() {
    cin >> n >> m >> v1 >> v2;
    v1--;
    v2--;
    reb.clear();
    reb.resize(n);
    for (i = 0; i < m; i++) {
        long a, b;
        cin >> a >> b;
        a--; b--;
        reb[a].push_back(b);
        reb[b].push_back(a);
    }
    col1.clear();
    col1.assign(n, -1);
    was1.clear();
    was1.assign(n, false);
    col2.clear();
    col2.assign(n, -1);
    was2.clear();
    was2.assign(n, false);
    DFS1(v1, 0, false);
    DFS2(v2, 0, false);
    DFS1(v2, 0, true);
    DFS2(v1, 0, true);

    ll s1 = 0;
    ll s2 = 0;
    for (auto i : was1)
        s1 += i;
    for (auto i : was2)
        s2 += i;
    s1--, s2--;
    ll ans = s1 * s2;
    cout << ans << '\n';
    if (viv) {
        for (auto i : was1)
            cout << i << ' ';
        cout << '\n';
        for (auto i : was2)
            cout << i << ' ';
        cout << '\n';
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
        solve();





    return 0;
}