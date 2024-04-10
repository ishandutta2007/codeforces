 #include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e9 + 10;
const ll MOD = 1e9 + 7;
const ll P = 29;
const ld EPS = 1e-9;

const int N = 3e5 + 10;
const int M = 1e3 + 10;

vector <int> col[N], g[N];

int color[N];

bool used[N];

void dfs(int v) {
    used[v] = true;
    set <int> usd;
    fr(i, col[v].size())
        usd.insert(color[col[v][i]]);
    for (auto t: g[v]) {
        if (used[t]) continue;
        int cur = 1;
        set <int> us1;
        fr(i, col[t].size())
            if (usd.count(color[col[t][i]]))
                us1.insert(color[col[t][i]]);
        fr(i, col[t].size()) {
            if (color[col[t][i]])
                continue;
            while (us1.count(cur))
                cur++;
            color[col[t][i]] = cur++;
        }
        dfs(t);
    }
}

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    fr(i, n) {
        int cnt;
        cin >> cnt;
        fr(j, cnt) {
            int x;
            cin >> x;
            col[i].pb(x);
        }
        sort(col[i].begin(), col[i].end());
    }

    fr(i, n - 1) {
        int v, u;
        cin >> v >> u;
        g[--v].pb(--u);
        g[u].pb(v);
    }

    fr(i, col[0].size())
        color[col[0][i]] = i + 1;
    dfs(0);
    cout << max(1, *max_element(color, color + m + 1)) << endl;
    frab(i, 1, m + 1)
        cout << max(1, color[i]) << " ";
}