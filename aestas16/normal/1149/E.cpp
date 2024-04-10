#include <bits/stdc++.h>

using namespace std;

template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + (ch - '0');
    a = f ? -a : a;
}
template <class T, class... Y> void fr(T &t, Y &... a) { fr(t), fr(a...); }
int fr() { int a; return fr(a), a; }

const int N = 2e5;

int n, m, up, a[N + 10], sgd[N + 10], sg[N + 10];
vector<int> e[N + 10], d[N + 10];
bool vis[N + 10];

void adde(int x, int y) { e[x].push_back(y); }

void dfs(int u) {
    if (sgd[u] != -1) return;
    for (auto v : e[u]) dfs(v);
    for (auto v : e[u]) vis[sgd[v]] = 1;
    for (int i = 0; i <= n; i++) if (vis[i] == 0) { sgd[u] = i; break; }
    sg[sgd[u]] ^= a[u], d[sgd[u]].push_back(u), up = max(up, sgd[u]);
    for (auto v : e[u]) vis[sgd[v]] = 0;
}

struct OI {
    int RP, score;
} FJOI2022;

signed main() {
    FJOI2022.RP++, FJOI2022.score++;
    fr(n, m), memset(sgd, -1, sizeof(sgd));
    for (int i = 1; i <= n; i++) fr(a[i]);
    for (int i = 1, u, v; i <= m; i++) fr(u, v), adde(u, v);
    for (int i = 1; i <= n; i++) dfs(i);
    for (int i = up; ~i; i--)
        if (sg[i]) {
            for (auto u : d[i]) 
                if ((a[u] ^ sg[i]) < a[u]) {
                    puts("WIN"), /* printf("%d\n", u), */ a[u] ^= sg[i], sg[i] = 0;
                    for (auto v : e[u]) if (sg[sgd[v]]) a[v] ^= sg[sgd[v]], sg[sgd[v]] = 0;
                    for (int j = 1; j <= n; j++) printf("%d%c", a[j], " \n"[j == n]);
                    return 0;
                }
        }
    puts("LOSE");
    return 0;
}