#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

const int N = 100005;

vector<int> g[N];
int s[N], n, a[N];
bool ok = 1;

void dfs(int u, int h, int cur) {
    if (s[u] != -1 && h % 2 == 0) ok = 0;
    if (s[u] == -1 && h % 2) ok = 0;
    bool check = (s[u] == -1);
    if (s[u] == -1 && g[u].size() == 0) {
        s[u] = cur;
        return;
    }
    if (s[u] == -1) s[u] = 1e9;
    for (int e : g[u]) {
        dfs(e, h + 1, s[u]);
        if (check) s[u] = min(s[u], s[e]);
    }
    // cout << u << ' ' << s[u] << endl;
}

void dfs2(int u, int cur) {
    a[u] = s[u] - cur;
    if (a[u] < 0) ok = 0;
    cur = s[u];
    for (int e : g[u]) {
        dfs2(e, s[u]);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u;
        cin >> u;
        g[u].pb(i + 1);
    }
    for (int i = 1; i <= n; i++) cin >> s[i];
    dfs(1, 1, 0);
    dfs2(1, 0);
    if (!ok) return cout << -1, 0;
    long long sum = 0;
    for (int i = 1; i <= n; i++) sum += a[i];
    cout << sum;
    return 0;
}