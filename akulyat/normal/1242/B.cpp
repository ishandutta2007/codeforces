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
set<ll> reb[gs + 10];
set<ll> stay;
vector<ll> col, tc;
bool viv = false;

void DFS(ll v, ll c) {
    col[v] = 1;
    vector<ll> add;
    stay.erase(v);
    for (auto s : stay) {
        if (!reb[v].count(s) && col[s] == -1)
            add.push_back(s), col[s] == 0;
    }
    for (auto s : add)
        stay.erase(s);
    for (auto s : add)
        if (col[s] != 1)
            DFS(s, c);
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (ll i = 0; i < n; i++)
        stay.insert(i);
    for (i = 0; i < m; i++) {
        long a, b;
        cin >> a >> b;
        a--; b--;
        reb[a].insert(b);
        reb[b].insert(a);
    }
    col.assign(n, -1);

    ll ans = 0;
    for (ll i = 0; i < n; i++)
        if (col[i] == -1)
            DFS(i, 0), ans++;

    cout << ans - 1 << endl;





    return 0;
}