#include <bits/stdc++.h>

using namespace std;

template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + (ch - '0');
    a = f ? -a : a;
}
template <class T, class... Y> void fr(T &t, Y &... a) { fr(t), fr(a...); }
int fr() { int a; return fr(a), a; }

const int N = 2e5, INF = 0x7f7f7f7f;

int n, a[N + 10], p[N + 10], c[N + 10];
bool vis[N + 10], qwq[N + 10];

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

bool chk(int x, int tot) {
    for (int i = 1; i <= x; i++) {
        for (int j = i; j <= tot; j += x)
            if (c[a[i]] != c[a[j]]) goto cat;
            else if (j + x > tot) return 1;
        cat:;
    }
    return 0;
}

int work(int x) {
    int tot = 0;
    for (int i = x; vis[i] == 0; i = p[i]) vis[i] = 1, a[++tot] = i;
    for (int i = 1; i <= tot; i++)
        if (tot % i == 0) qwq[i] = chk(i, tot);
    for (int i = 1; i <= tot; i++)
        if (qwq[gcd(tot, i)]) return i;
    return INF;
}

struct OI {
    int RP, score;
} CSPS2021, NOIP2021, FJOI2022;

signed main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, FJOI2022.RP++, FJOI2022.score++;
    for (int _ = fr(); _--;) {
        int ans = INF;
        fr(n);
        for (int i = 1; i <= n; i++) fr(p[i]);
        for (int i = 1; i <= n; i++) fr(c[i]);
        for (int i = 1; i <= n; i++)
            if (vis[i] == 0) ans = min(ans, work(i));
        for (int i = 1; i <= n; i++) vis[i] = qwq[i] = 0;
        printf("%d\n", ans);
    }
    return 0;
}