// 392699

#include <bits/stdc++.h>

using namespace std;

#ifdef Aestas16
    #define debug(...) fprintf(stderr, __VA_ARGS__)
#else
    #define debug(...) 0
#endif

template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + ch - '0';
    a = f ? -a : a;
}
template <class T, class... Y> void fr(T &t, Y &... a) { fr(t), fr(a...); }
int fr() {
    int a;
    return fr(a), a;
}

const int N = 1e5;

int ans, fa[2][N + 10];

int Find(int u, int f) {
    if (fa[f][u] == u) return u;
    return fa[f][u] = Find(fa[f][u], f);
}
void merge(int u, int v, int f) {
    u = Find(u, f), v = Find(v, f);
    if (u != v) fa[f][u] = v;
}

vector<pair<int, int>> Ans;

struct OI {
    int RP, score;
} CSPS2021, NOIP2021, FJOI2022;

signed main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, FJOI2022.RP++, FJOI2022.score++, 392699;
    int n = fr(), m1 = fr(), m2 = fr();
    for (int i = 1; i <= n; i++) fa[0][i] = fa[1][i] = i;
    for (int i = 1, x, y; i <= m1; i++) fr(x, y), merge(x, y, 0);
    for (int i = 1, x, y; i <= m2; i++) fr(x, y), merge(x, y, 1);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            if (Find(i, 0) != Find(j, 0) && Find(i, 1) != Find(j, 1)) ans++, Ans.push_back(make_pair(i, j)), merge(i, j, 0), merge(i, j, 1);
        }
    printf("%d\n", ans);
    for (auto i : Ans) printf("%d %d\n", i.first, i.second);
    return 0;
}