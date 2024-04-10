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

int n;
struct Edge { int u, v, w; } E[N + 10];
vector<int> tmp, leaf, e[N + 10];
vector<Edge> opt;

void adde(int x, int y) { e[x].push_back(y); }

void dfs(int u, int p, bool f = 1) {
    for (auto v : e[u])
        if (v != p) {
            tmp.clear(), dfs(v, u, 0);
            if (f) leaf.push_back(tmp[0]);
        }
    if (e[u].size() == 1) tmp.push_back(u);
    if (f && e[u].size() == 1) leaf.push_back(u);
}

struct OI {
    int RP, score;
} CSPS2021, NOIP2021, FJOI2022;

signed main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, FJOI2022.RP++, FJOI2022.score++;
    fr(n);
    for (int i = 1; i < n; i++) fr(E[i].u, E[i].v), adde(E[i].u, E[i].v), adde(E[i].v, E[i].u);
    for (int i = 1; i <= n; i++)
        if (e[i].size() == 2) return puts("NO"), 0;
    puts("YES");
    return 0;
}