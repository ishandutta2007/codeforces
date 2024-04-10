#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
#define s second
#define f first

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5 + 10;
const ll INF = 2e9 + 1;
const int MOD = 1e9 + 7;
const ld EPS = 1e-9;

vector <int> g[N];
vector <int> ans[N];
vector <int> eul;
bool used[N];

void dfs(int v) {
    eul.pb(v);
    used[v] = true;
    for (auto nxt: g[v])
        if (!used[nxt]) {
            dfs(nxt);
            eul.pb(v);
        }
}

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    fr(i, m) {
        int v, u;
        cin >> v >> u;
        g[--v].pb(--u);
        g[u].pb(v);
    }
    dfs(0);
    int len = (2 * n + k - 1) / k;
    for (int i = 0; i < k; i++) {
        for (int j = i * len; j < (i + 1) * len && j < (int)eul.size(); j++)
            ans[i].pb(eul[j] + 1);
        if (ans[i].size() == 0)
            ans[i].pb(1);
    }
    fr(i, k) {
        cout << ans[i].size() << " ";
        for (auto t: ans[i])
            cout << t << " ";
        cout << endl;
    }
}