#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; ++i)
#define pb push_back
#define mp make_pair
#define frab(i, a, b) for (ll i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const int INF = 2e9 + 10;
const ld EPS = 1e-9;
const int M = 1e2 + 12;
const int N = 4e5 + 10;

vector <pair <ll, ll> > g[N];

ll d[N], d2[N];

void dfs(int v, int par, int k) {
    for (auto t: g[v])
        if (t.first != par)
            dfs(t.first, v, k);

    vector <pair <ll, ll> > vs;
    for (auto t: g[v])
        if (t.first != par)
            vs.pb(mp(d[t.first] + t.second, t.first));

    ll ans = 0;
    sort(vs.begin(), vs.end());
    reverse(vs.begin(), vs.end());
    fr(i, min((int)vs.size(), k - 1))
        ans += vs[i].first;
    d[v] = ans;
    if (vs.size() == 0) {
        return;
    }
    ll ans2 = ans;

    ll tmp1 = 0;
    fr(i, min((int)vs.size() - 1, k - 1))
        tmp1 += vs[i].first;
    ll mxd2 = 0;
    frab(i, min((int)vs.size(), k) - 1, (int)vs.size())
        mxd2 = max(mxd2, d2[vs[i].second] + vs[i].first - d[vs[i].second]);

    ans2 = max(ans2, mxd2 + tmp1);

    ll tmp2 = 0, mxd3 = 0;
    fr(i, min((int)vs.size(), k)) {
        tmp2 += vs[i].first;
        mxd3 = max(mxd3, d2[vs[i].second] - d[vs[i].second]);
    }

    ans2 = max(ans2, tmp2 + mxd3);
    d2[v] = ans2;
}

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    fr(i, n - 1) {
        ll v, u, c;
        cin >> v >> u >> c;
        g[v].pb(mp(u, c));
        g[u].pb(mp(v, c));
    }

    dfs(0, -1, k);
    cout << d2[0];

}