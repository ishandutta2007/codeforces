#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long

vector<vector<int>> g, d;
vector<int> q;

int mx = 0;

void dfs(int v, int p, int depth) {
    d[depth].pb(v);
    mx = max(mx, depth);
    for (auto &to : g[v]) {
        if (to == p) continue;
        dfs(to, v, depth + 1);
    }
}

void dfs1(int v, int p, int depth, int need) {
    if (depth == need) q.pb(v);
    for (auto &to : g[v]) {
        if (to == p) continue;
        dfs1(to, v, depth + 1, need);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        g.clear();
        d.clear();
        g.resize(n);
        d.resize(n);
        mx = 0;
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b; a--; b--;
            g[a].pb(b); g[b].pb(a);
        }
        cout << '?' << " " << n << " ";
        for (int i = 0; i < n; i++) cout << i + 1 << " ";
        cout << endl;
        int root, x;
        cin >> root >> x;
        root--;
        dfs(root, -1, 0);
        int left = x / 2 - 1, right = mx + 1;
        int v1 = -1;
        while (right - left > 1) {
            int mid = (left + right) / 2;
            if (mid < 0) {
                left = mid;
                continue;
            }
            cout << '?' << " " << d[mid].size() << " ";
            for (auto &v : d[mid]) cout << v + 1 << " ";
            cout << endl;
            int v, l;
            cin >> v >> l;
            if (l > x) right = mid;
            else left = mid, v1 = v - 1;
        }
        q.clear();
        dfs1(v1, -1, 0, x);
        cout << '?' << " " << q.size() << " ";
        for (auto &v : q) cout << v + 1 << " ";
        cout << endl;
        int v2, k;
        cin >> v2 >> k;
        cout << '!' << " " << v1 + 1 << " " << v2 << endl;
        string ans;
        cin >> ans;
    }
    return 0;
}