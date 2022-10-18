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

int ans, fa[2][N + 10], sz[2][N + 10];
vector<pair<int, int>> Ans;
vector<int> ANS[2];

int Find(int u, int f) {
    if (fa[f][u] == u) return u;
    return fa[f][u] = Find(fa[f][u], f);
}
void merge(int u, int v, int f) {
    u = Find(u, f), v = Find(v, f);
    if (sz[f][u] > sz[f][v]) swap(u, v);
    if (u != v) fa[f][u] = v, sz[f][v] += sz[f][u];
}

struct OI {
    int RP, score;
} CSPS2021, NOIP2021, FJOI2022;

signed main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, FJOI2022.RP++, FJOI2022.score++, 392699;
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::mt19937 rnd(seed);
    int n = fr(), m1 = fr(), m2 = fr();
    for (int i = 1; i <= n; i++) fa[0][i] = fa[1][i] = i, sz[0][i] = sz[1][i] = 1;
    for (int i = 1, x, y; i <= m1; i++) fr(x, y), merge(x, y, 0);
    for (int i = 1, x, y; i <= m2; i++) fr(x, y), merge(x, y, 1);
    for (int i = 2; i <= n; i++)
        if (Find(1, 0) != Find(i, 0) && Find(1, 1) != Find(i, 1)) ans++, Ans.push_back(make_pair(1, i)), merge(1, i, 0), merge(1, i, 1);
    for (int f = 0; f <= 1; f++)
        for (int i = 1; i <= n; i++)
            if (Find(1, f) != Find(i, f)) merge(1, i, f), ANS[f].push_back(i);
    int up = min(ANS[0].size(), ANS[1].size());
    printf("%d\n", ans + up);
    for (auto i : Ans) printf("%d %d\n", i.first, i.second);
    for (int i = 0; i < up; i++) printf("%d %d\n", ANS[0][i], ANS[1][i]);
    return 0;
}