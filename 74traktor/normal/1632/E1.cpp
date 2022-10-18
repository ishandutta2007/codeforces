#include<bits/stdc++.h>

using namespace std;

int const maxn = 3e5 + 5;
vector < int > g[maxn];
int h[maxn], maxh[maxn], best, lst[maxn];
pair < int, int > a[maxn];

void dfs(int v, int p) {
    lst[v] = p;
    if (h[v] > h[best]) best = v;
    maxh[v] = h[v];
    for (auto u : g[v]) {
        if (u != p) {
            h[u] = h[v] + 1;
            dfs(u, v);
            maxh[v] = max(maxh[v], maxh[u]);
        }
    }
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, u, v, n;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) g[i] = {};
        for (int i = 1; i < n; ++i) {
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        best = 1;
        dfs(1, 0);
        int sv = best;
        a[h[best]] = {-h[best], h[best]};
        while (best != 1) {
            int to = lst[best];
            int mx = h[to];
            for (auto key : g[to]) {
                if (key == best || key == lst[to]) continue;
                mx = max(mx, maxh[key]);
            }
            a[h[to]] = {mx - 2 * h[to], mx};
            best = to;
        }
        best = sv;
        for (int w = 1; w <= n; ++w) {
            int lef = 0, righ = h[best];
            while (righ - lef > 1) {
                int mid = (lef + righ) / 2;
                int M = -mid + w + h[best];
                if (M > h[best]) {
                    lef = mid;
                    continue;
                }
                assert(0 <= M && M <= h[best]);
                int flag = 1;
                for (int i = 0; i < M; ++i) {
                    if (min(a[i].second, a[i].first + M + w) > mid) {
                        flag = 0;
                        break;
                    }
                }
                if (flag) righ = mid;
                else lef = mid;
            }
            cout << righ << " ";
        }
        cout << '\n';
    }
    return 0;
}