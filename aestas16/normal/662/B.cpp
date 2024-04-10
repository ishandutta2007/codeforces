#include <bits/stdc++.h>

using namespace std;

template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + (ch - '0');
    a = f ? -a : a;
}
template <class T, class... Y> void fr(T &t, Y &... a) { fr(t), fr(a...); }
int fr() { int a; return fr(a), a; }

const int N = 1e5;

int n, m, c, anscnt = N + 10, tot, val[N + 10];
vector<pair<int, int>> e[N + 10];
vector<int> ans;
char s[5];

void adde(int x, int y, int z) { e[x].push_back({y, z}); }

void clr(int u) {
    val[u] = -1;
    for (auto [v, w] : e[u]) if (val[v] != -1) clr(v);
}
int dfs(int u, int f) {
    int ret = f; val[u] = f;
    for (auto [v, w] : e[u])
        if (val[v] == -1) {
            int tmp = dfs(v, w ^ f ^ c);
            if (tmp == -1) return -1;
            ret += tmp;
        } else if (val[v] != (w ^ f ^ c)) return -1;
    return ret;
}

struct OI {
    int RP, score;
} NOIP2021, FJOI2022;

signed main() {
    NOIP2021.RP++, NOIP2021.score++, FJOI2022.RP++, FJOI2022.score++;
    fr(n, m);
    for (int i = 1, x, y; i <= m; i++) fr(x, y), scanf("%s", s), adde(x, y, s[0] == 'R'), adde(y, x, s[0] == 'R');
    for (; c < 2; c++) {
        memset(val, -1, sizeof(val)), tot = 0;
        for (int i = 1; i <= n; i++)
            if (val[i] == -1) {
                int ans0 = dfs(i, 0); clr(i); int ans1 = dfs(i, 1);
                if (ans0 == ans1 && ans0 == -1) goto cat;
                if (ans1 == -1 || ans0 < ans1) clr(i), dfs(i, 0), tot += ans0;
                else tot += ans1;
            }
        if (tot < anscnt) {
            anscnt = tot, ans.clear();
            for (int i = 1; i <= n; i++) if (val[i]) ans.push_back(i);
        }
        cat:;
    }
    if (anscnt > n) puts("-1"), exit(0);
    printf("%d\n", anscnt);
    for (auto i : ans) printf("%d ", i);
    return puts(""), 0;
}