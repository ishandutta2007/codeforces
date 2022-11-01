#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5 + 10;
const ll INF = 2e18 + 1;

ll a[N];
bool bad[N];
ll used[N];

vector <pair <ll, ll> > g[N];

void dfs(ll v, ll dst) {
    used[v] = 1;
//    if (g[v].size() == 1) {
//        if (a[v] < dst)
//            bad = true;
//        return;
//    }
    fr(i, g[v].size())
        if (!used[g[v][i].first])
            dfs(g[v][i].first, max(0ll, dst) + g[v][i].second);
    if (a[v] < dst && v)
        bad[v] = true;
    return;
}

int used2[N];

void dfs2(ll v) {
    if (bad[v])
        return;
    used2[v] = 1;
    fr(i, g[v].size())
        if (!used2[g[v][i].first])
            dfs2(g[v][i].first);
}

int main() {
    //freopen("a.in", "r", stdin);
    ll n;
    cin >> n;
    //fill(d, d + n, -INF);
    fr(i, n)
        cin >> a[i];
    fr(i, n - 1) {
        ll p, c;
        cin >> p >> c;
        g[--p].pb(mp(i + 1, c));
        g[i + 1].pb(mp(p, c));
    }
    dfs(0, 0);
    dfs2(0);
//    fr(i, n)
//        cout << bad[i] << " ";cout << endl;
//    fr(i, n)
//        cout << used2[i] << " ";cout << endl;
    cout << n - accumulate(used2, used2 + n, 0);
}