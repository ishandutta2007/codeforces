/*
    I will never forget it.
*/

// 392699

#include <bits/stdc++.h>

using namespace std;

void fr(int &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + ch - '0';
    a = f ? -a : a;
}
int fr() {
    int a;
    return fr(a), a;
}

const int N = 5e5;

int n, dep[N + 10];
double ans;

namespace Edges {
    struct Edge {
        int to, nxt;
    } e[(N << 1) + 10];
    int etot = 1, hd[N + 10];
    void adde(int x, int y) { e[++etot] = {y, hd[x]}, hd[x] = etot; }
} // namespace Edges
using namespace Edges;

void dfs(int u, int p) {
    dep[u] = dep[p] + 1, ans += 1.0 / dep[u];
    for (int i = hd[u]; i; i = e[i].nxt) {
        int v = e[i].to;
        if (v == p) continue;
        dfs(v, u);
    }
}

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

int main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    fr(n);
    for (int i = 1, u, v; i < n; i++) fr(u), fr(v), adde(u, v), adde(v, u);
    dfs(1, 0);
    return printf("%.9lf\n", ans), 0;
}