#include<bits/stdc++.h>

using namespace std;

int const maxn = 3e5 + 5, logg = 19;
vector < int > g[maxn];
int h[maxn], maxh[maxn], best, lst[maxn];
int a[maxn], inf = 1e9 + 7;
int dp[logg][maxn], st[maxn], pref[maxn];

int get(int l, int r) {
    if (l > r) return -inf;
    int x = st[r - l + 1];
    return max(dp[x][l], dp[x][r - (1 << x) + 1]);
}

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
        a[h[best]] = h[best];
        while (best != 1) {
            int to = lst[best];
            int mx = h[to];
            for (auto key : g[to]) {
                if (key == best || key == lst[to]) continue;
                mx = max(mx, maxh[key]);
            }
            a[h[to]] = mx;
            best = to;
        }
        best = sv;
        int x = 2;
        for (int i = 2; i <= n; ++i) {
            st[i] = st[i - 1] + (i == x);
            if (i == x) x *= 2;
        }
        for (int i = 0; i <= n; ++i) dp[0][i] = a[i] - 2 * i;
        for (int j = 1; j < logg; ++j) {
            for (int i = 0; i + (1 << j) - 1 <= n; ++i) {
                dp[j][i] = max(dp[j - 1][i], dp[j - 1][i + (1 << (j - 1))]);
            }
        }
        pref[0] = a[0];
        for (int i = 1; i <= n; ++i) pref[i] = max(pref[i - 1], a[i]);
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
                /*int flag = 1;
                for (int i = 0; i < M; ++i) {
                    if (min(a[i], a[i] - 2 * i + M + w) > mid) {
                        flag = 0;
                        break;
                    }
                }*/
                int i = (M + w) / 2;
                if ((min(i, M - 1) < 0 || pref[min(i, M - 1)] <= mid) && get(i + 1, M - 1) <= mid - M - w) righ = mid;
                else lef = mid;
            }
            cout << righ << " ";
        }
        cout << '\n';
    }
    return 0;
}