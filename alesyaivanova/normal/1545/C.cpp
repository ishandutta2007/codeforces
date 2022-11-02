#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())

const int maxn = 1009;
int a[maxn][maxn];
int n;
set<int> p[maxn][maxn];
vector<int> g[maxn];
int t[maxn];
int mod = 998244353;
int ans;

void dfs(int v) {
    for (int to : g[v]) {
        if (t[to] == 0) {
            t[to] = -t[v];
            dfs(to);
        }
        if (t[v] == 1 && t[to] == 1) {
            ans = 0;
        }
    }
}

void solve() {
    ans = 1;
    cin >> n;
    for (int i = 0; i < 2 * n; i++) {
        for (int e = 0; e < n; e++) {
            cin >> a[i][e];
            a[i][e]--;
            p[e][a[i][e]].insert(i);
        }
    }
     for (int i = 0; i < 2 * n; i++) {
        for (int e = i + 1; e < 2 * n; e++) {
            bool fl = 0;
            for (int j = 0; j < n; j++) {
                if (a[i][j] == a[e][j])
                    fl = 1;
            }
            if (fl) {
                g[i].pb(e);
                g[e].pb(i);
            }
        }
    }
    queue<int> q;
    for (int i = 0; i < n; i++) {
        for (int e = 0; e < n; e++) {
            if (p[i][e].empty()) {
                ans = 0;
            }
            if (p[i][e].size() == 1) {
                int x = *p[i][e].begin();
                if (t[x] == -1) {
                    ans = 0;
                }
                if (t[x] == 0) {
                    t[x] = 1;
                    q.push(x);
                }
            }
        }
    }
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i : g[x]) {
            if (t[i] == 1) {
                ans = 0;
            }
            if (t[i] == 0) {
                t[i] = -1;
                for (int e = 0; e < n; e++) {
                    p[e][a[i][e]].erase(i);
                    if (p[e][a[i][e]].empty()) {
                        ans = 0;
                    }
                    if (p[e][a[i][e]].size() == 1) {
                        int y = *p[e][a[i][e]].begin();
                        if (t[y] == -1) {
                            ans = 0;
                        }
                        if (t[y] == 0) {
                            t[y] = 1;
                            q.push(y);
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < 2 * n; i++) {
        if (t[i] == 0) {
            t[i] = 1;
            dfs(i);
            ans = (ans * 2) % mod;
        }
    }
    cout << ans << "\n";
    for (int i = 0; i < 2 * n; i++) {
        if (t[i] == 1) {
            cout << i + 1 << " ";
        }
    }
    cout << "\n";
    for (int i = 0; i < 2 * n; i++) {
        g[i].resize(0);
        g[i].shrink_to_fit();
        t[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        for (int e = 0; e < n; e++) {
            p[i][e].clear();
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}