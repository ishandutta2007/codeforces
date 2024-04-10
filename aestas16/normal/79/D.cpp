// 392699

#include <bits/stdc++.h>

using namespace std;

template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + (ch - '0');
    a = f ? -a : a;
}
template <class T, class... Y> void fr(T &t, Y &... a) { fr(t), fr(a...); }
int fr() { int a; return fr(a), a; }

const int N = 20, M = 1e4, INF = 0x3f3f3f3f;

int n, k, m, tot, a[M + 10], b[M + 10], id[M + 10], f[(1 << N) + 10], val[N + 10][N + 10], dis[M + 10];

void spfa(int s) {
    queue<int> q;
    memset(dis, 0x3f, sizeof(dis));
    q.push(s), dis[s] = 0;
    while (q.empty() == 0) {
        int u = q.front();
        q.pop();
        for (int i = 1; i <= m; i++) {
            int j1 = u + b[i], j2 = u - b[i];
            if (j1 <= n && dis[j1] >= INF) dis[j1] = dis[u] + 1, q.push(j1);
            if (j2 >= 1 && dis[j2] >= INF) dis[j2] = dis[u] + 1, q.push(j2);
        }
    }
    for (int i = 1; i <= n; i++)
        if (id[i]) val[id[s]][id[i]] = dis[i];
}

struct OI {
    int RP, score;
} CSPS2021, NOIP2021, FJOI2022;

signed main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, FJOI2022.RP++, FJOI2022.score++, 392699;
    fr(n, k, m);
    for (int i = 1; i <= k; i++) a[fr()] = 1;
    for (int i = 0; i <= n; i++) a[i] ^= a[i + 1];
    for (int i = 1; i <= m; i++) fr(b[i]);
    for (int i = 0; i <= n; i++)
        if (a[i]) id[i] = ++tot;
    for (int i = 0; i <= n; i++)
        if (a[i]) spfa(i);
    int all = (1 << tot) - 1;
    memset(f, 0x3f, sizeof(f)), f[0] = 0;
    for (int i = 0; i <= all; i++)
        for (int j = 1; j <= tot; j++) {
            if (i & (1 << (j - 1))) continue;
            for (int k = j + 1; k <= tot; k++) {
                if (i & (1 << (k - 1))) continue;
                f[i | (1 << (j - 1)) | (1 << (k - 1))] = min(f[i | (1 << (j - 1)) | (1 << (k - 1))], f[i] + val[j][k]);
            }
        }
    printf("%d\n", f[all] >= INF ? -1 : f[all]);
    return 0;
}