#include <bits/stdc++.h>

#define int long long

using namespace std;

template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + (ch - '0');
    a = f ? -a : a;
}
template <class T, class... Y> void fr(T &t, Y &... a) { fr(t), fr(a...); }
int fr() { int a; return fr(a), a; }

const int N = 2e5, S = 5e2;

int n, m, btot, a[N + 10], sum[N + 10], atag[N + 10], p[N + 10], bid[N + 10], lst[N + 10];
struct Query { int op, x, y; } Q[N + 10];
bool vis[N + 10];
vector<int> vec[N + 10], B;

void dfs(int u) {
    bid[u] = btot;
    if (vis[u] == 0 && bid[p[u]] == 0) dfs(p[u]);
    else lst[btot] = u;
}

struct OI {
    int RP, score;
} FJOI2022;

signed main() {
    FJOI2022.RP++, FJOI2022.score++;
    fr(n);
    for (int i = 1; i <= n; i++) fr(a[i]), sum[i] = sum[i - 1] + a[i];
    for (int i = 1; i <= n; i++) fr(p[i]);
    fr(m);
    for (int i = 1; i <= m; i++) fr(Q[i].op, Q[i].x, Q[i].y);
    for (int l = 1, r; l <= m; l = r + 1) {
        r = min(l + S - 1, m);
        for (int i = 1; i <= btot; i++) vec[i].clear();
        btot = 0, B.clear(), memset(bid, 0, sizeof(bid)), memset(vis, 0, sizeof(vis)), memset(atag, 0, sizeof(atag));
        for (int i = l; i <= r; i++)
            if (Q[i].op == 3) vis[Q[i].x] = vis[Q[i].y] = 1;
        for (int i = 1; i <= n; i++)
            if (vis[i]) btot++, dfs(p[i]);
        for (int i = 1; i <= n; i++)
            if (bid[i] == 0) btot++, dfs(i);
        for (int i = 1; i <= n; i++) vec[bid[i]].push_back(i);
        memset(vis, 0, sizeof(vis));
        for (int i = l; i <= r; i++) {
            if (Q[i].op == 1) {
                int L = Q[i].x, R = Q[i].y, ans = sum[R] - sum[L - 1];
                for (auto j : B) ans += atag[j] * (upper_bound(vec[j].begin(), vec[j].end(), R) - lower_bound(vec[j].begin(), vec[j].end(), L));
                printf("%lld\n", ans);
            } else if (Q[i].op == 2) {
                int u = bid[Q[i].x], v = u, val = Q[i].y;
                do {
                    if (vis[u] == 0) B.push_back(u), vis[u] = 1;
                    atag[u] += val, u = bid[p[lst[u]]];
                } while (u != v);
            } else swap(p[Q[i].x], p[Q[i].y]);
        }
        for (int i = 1; i <= n; i++) a[i] = a[i - 1] + atag[bid[i]];
        for (int i = 1; i <= n; i++) sum[i] += a[i];
    }
    return 0;
}