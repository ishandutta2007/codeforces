#include <bits/stdc++.h>

using namespace std;

template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) (ch == '-') && (f = 1);
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + (ch - '0');
    f && (a = -a);
}
template <class T, class ...Y> void fr(T &a, Y &...b) { fr(a), fr(b...); }
int fr() { int a; return fr(a), a; }

const int N = 1e6;

int n, to[N + 10], ans[N + 10];
bool vis[N + 10];

struct OI {
    int RP, score;
} FJOI2022;

signed main() {
    FJOI2022.RP++, FJOI2022.score++;
    for (int _ = fr(); _--;) {
        fr(n), ans[0] = 0;
        for (int i = 1; i <= n; i++) to[i] = i - fr(), vis[i] = 0;
        int u = 1, p = 0;
        while (vis[u] == 0) vis[u] = 1, u = to[u];
        p = u;
        do { ans[++ans[0]] = u, u = to[u]; } while (u != p);
        printf("%d\n", ans[0]);
        for (int i = 1; i <= ans[0]; i++) printf("%d%c", ans[i], " \n"[i == ans[0]]);
    }
    return 0;
}