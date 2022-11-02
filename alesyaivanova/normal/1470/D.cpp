#include <bits/stdc++.h>

using namespace std;

//#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())

const int maxn = 3e5 + 9;
vector<int> g[maxn];
int col[maxn];
int n, m;

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    for (int i = 0; i < n; i++)
        col[i] = 0;
    unordered_set<int> cand;
    cand.insert(0);
    while (!cand.empty()) {
        int v = *(cand.begin());
        cand.erase(cand.begin());
        col[v] = 2;
        for (int to : g[v]) {
            if (col[to])
                continue;
            col[to] = 1;
            cand.erase(to);
            for (int u : g[to]) {
                if (!col[u])
                    cand.insert(u);
            }
        }
    }
    bool check = 1;
    for (int i = 0; i < n; i++) {
        if (!col[i]) {
            check = 0;
            break;
        }
    }
    if (check) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (col[i] == 2)
                cnt++;
        }
        cout << "YES\n" << cnt << "\n";
        for (int i = 0; i < n; i++) {
            if (col[i] == 2)
                cout << i + 1 << " ";
        }
        cout << "\n";

    } else {
        cout << "NO\n";
    }

    for (int i = 0; i < n; i++) {
        g[i].resize(0);
        g[i].shrink_to_fit();
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}