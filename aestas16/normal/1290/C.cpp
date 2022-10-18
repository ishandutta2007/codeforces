#include <bits/stdc++.h>

using namespace std;

template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + (ch - '0');
    a = f ? -a : a;
}
template <class T, class... Y> void fr(T &t, Y &... a) { fr(t), fr(a...); }
int fr() { int a; return fr(a), a; }

const int N = 1e6, INF = 0x7f7f7f7f;

int n, m, ans, fa[N + 10], val[N + 10];
vector<int> vec[N + 10]; 
char str[N + 10];

int find(int u) { return fa[u] == u ? u : fa[u] = find(fa[u]); }
void merge(int u, int v) {
    u = find(u), v = find(v);
    if (u != v) fa[u] = v, val[v] += val[u];
}
int V(int u) { return min(val[find(u)], val[find(u + n)]); }

struct OI {
    int RP, score;
} NOIP2021, FJOI2022;

signed main() {
    NOIP2021.RP++, NOIP2021.score++, FJOI2022.RP++, FJOI2022.score++;
    fr(m, n), scanf("%s", str + 1);
    for (int i = 1; i <= n; i++) {
        int k = fr(), x;
        while (k--) fr(x), vec[x].push_back(i);
    }
    for (int i = 1; i <= n * 2 + 1; i++) fa[i] = i, val[i] = (i > n); 
    val[n * 2 + 1] = INF;
    for (int i = 1; i <= m; i++) {
        if (vec[i].size() == 1) ans -= V(vec[i][0]), merge(vec[i][0] + n * (str[i] == '1'), n * 2 + 1), ans += V(vec[i][0]);
        else if (vec[i].size() == 2) {
            if (str[i] == '0' && find(vec[i][0]) != find(vec[i][1] + n))
                ans -= V(vec[i][0]) + V(vec[i][1]), merge(vec[i][0], vec[i][1] + n), merge(vec[i][0] + n, vec[i][1]), ans += V(vec[i][0]);
            else if (str[i] == '1' && find(vec[i][0]) != find(vec[i][1]))
                ans -= V(vec[i][0]) + V(vec[i][1]), merge(vec[i][0], vec[i][1]), merge(vec[i][0] + n, vec[i][1] + n), ans += V(vec[i][0]);
        }
        printf("%d ", ans);
    }
    return puts(""), 0;
}