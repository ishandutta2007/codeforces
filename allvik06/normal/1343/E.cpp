#include <bits/stdc++.h>

using namespace std;
#define int long long
const int INF = 1e18;
int n;
void bfs(int v, vector <int> &a, vector <vector <int>> &g) {
    a.assign(n, n + 1);
    queue <int> q;
    q.push(v);
    a[v] = 0;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int i : g[now]) {
            if (a[i] > a[now] + 1) {
                a[i] = a[now] + 1;
                q.push(i);
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int m, a, b, c;
        cin >> n >> m >> a >> b >> c; --a; --b; --c;
        vector <int> p(m);
        for (int i = 0; i < m; ++i) {
            cin >> p[i];
        }
        sort(p.begin(), p.end());
        vector <int> pref(m + 1);
        for (int i = 1; i <= m; ++i) {
            pref[i] = pref[i - 1] + p[i - 1];
        }
        vector <vector <int>> g(n);
        for (int i = 0; i < m; ++i) {
            int x, y;
            cin >> x >> y; --x; --y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        vector <int> aa, bb, cc;
        bfs(a, aa, g);
        bfs(b, bb, g);
        bfs(c, cc, g);
        int minn = INF;
        for (int i = 0; i < n; ++i) {
            if (aa[i] + bb[i] + cc[i] > m) continue;
            int tmp = pref[bb[i]] * 2;
            tmp += pref[aa[i] + cc[i] + bb[i]] - pref[bb[i]];
            minn = min(minn, tmp);
        }
        cout << minn << "\n";
    }
}