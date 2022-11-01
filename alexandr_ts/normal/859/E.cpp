#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < (int)n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 1e9 + 10;
const ld PI = acos(-1);
const ld EPS = 1e-9;
const ll MOD = 1e9 + 7;
const int M = 1e3 + 3;
const int N = 2e5 + 10;

int a[N], b[N];
vector <pair <int, int> > g[N];
bool used[N];
int sz[N];
bool bad[N];
int bads[N];
bool cycle;

void dfs(int v, int ed, int v1) {
    used[v] = true;
    sz[v1]++;
    if (bad[v])
        bads[v1]++;
    for (auto t: g[v])
        if (t.second != ed) {
            if (!used[t.first])
                dfs(t.first, t.second, v1);
            else
                cycle = true;
        }
}

ll solve(int v) {
    cycle = false;
    dfs(v, -1, v);
    if (cycle)
        return 2;
    else if (!bads[v])
        return sz[v];
    else
        return 1;
}

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    fr(i, n) {
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
        if (a[i] != b[i]) {
            g[a[i]].pb(mp(b[i], i));
            g[b[i]].pb(mp(a[i], i));
        }
        else
            bad[a[i]] = true;
    }

    ll ans = 1;
    fr(i, 2 * n)
        if (g[i].size() && !used[i])
            ans = (ans * solve(i)) % MOD;

    cout << ans;
}