#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 998244353;
const ll INF = 2e9 + 10;
const ll MAX = 1e14 + 10;
const ld EPS = 1e-9;
const int N = 1e6 + 10;

ll a[N];
int sum[N];
vector<int> g[N];
bool ok = true;

void dfs(int v, ll val, int h) {
    //cout << v << " " << val << " " << h << endl;
    if (h % 2 == 0) {
        a[v] = sum[v] - val;
        for (auto u: g[v])
            dfs(u, a[v] + val, h + 1);
        return;
    }
    ll dif = INF;
    for (auto u: g[v]) {
        if (sum[u] < val) {
            //cout << v << " " << u << " " << a[u] << " " << val << endl;
            ok = false;
            return;
        }
        dif = min(dif, sum[u] - val);
    }
    a[v] = dif;
    if (a[v] == INF)
        a[v] = 0;
    for (auto u: g[v])
        dfs(u, a[v] + val, h + 1);
}

void solve() {
    int n;
    scanf("%d", &n);
    fr(i, n - 1) {
        int par;
        scanf("%d", &par);
        par--;
        g[par].pb(i + 1);
    }

    fr(i, n)
        scanf("%d", &sum[i]);
    dfs(0, 0, 0);
    if (!ok)
        cout << -1;
    else {
        ll sum = accumulate(a, a + n, 0ll);
        cout << sum;
    }
}



int main() {
    //freopen("a.in", "r", stdin);
    //ios_base::sync_with_stdio(false);
    solve();

}