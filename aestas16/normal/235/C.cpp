/*
     []
*/

// 392699

#include <bits/stdc++.h>

using namespace std;

template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + ch - '0';
    a = f ? -a : a;
}
template <class T, class... Y> void fr(T &t, Y &...a) { fr(t), fr(a...); }
int fr() {
    int a;
    return fr(a), a;
}

const int N = 1e6, ALPHA = 26;

int n, q, ans;
char s[N + 10], t[(N << 1) + 10];

int h(char c) { return c - 'a'; }

namespace SAM {
    struct Node {
        int lnk, ch[ALPHA], len, cnt, vis;
    } a[(N << 1) + 10];
    int atot = 0, rt = ++atot, lst = rt;

    vector<int> e[(N << 1) + 10];

    void Init() {
        a[a[rt].lnk = 0].len = -1;
        for (int i = 0; i < ALPHA; i++) a[0].ch[i] = rt;
    }
    int New(int p, int q, int c) {
        int x = ++atot;
        a[x].lnk = a[q].lnk, memcpy(a[x].ch, a[q].ch, sizeof(a[q].ch));
        for (a[x].len = a[p].len + 1, a[q].lnk = x; a[p].ch[c] == q; p = a[p].lnk) a[p].ch[c] = x;
        return x;
    }
    void extend(int c) {
        int x = ++atot, y;
        for (a[x].cnt = 1, a[x].len = a[lst].len + 1; a[lst].ch[c] == 0; lst = a[lst].lnk) a[lst].ch[c] = x;
        if (a[y = a[lst].ch[c]].len == a[lst].len + 1) a[x].lnk = y, lst = x;
        else a[x].lnk = New(lst, y, c), lst = x;
    }
} // namespace SAM
using namespace SAM;

void dfs(int u) {
    for (auto v : e[u]) dfs(v), a[u].cnt += a[v].cnt;
}

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

signed main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    Init(), scanf("%s", s + 1), n = strlen(s + 1);
    for (int i = 1; i <= n; i++) extend(h(s[i]));
    for (int i = 2; i <= atot; i++) e[a[i].lnk].push_back(i);
    dfs(1);
    int q = fr();
    for (int i = 1; i <= atot; i++) a[i].vis = q;
    while (q--) {
        scanf("%s", t + 1), n = strlen(t + 1), ans = 0;
        for (int i = n + 1; i < (n << 1); i++) t[i] = t[i - n];
        int p = 1, len = 0;
        for (int i = 1; i < (n << 1); i++) {
            int v = h(t[i]);
            while (a[p].ch[v] == 0 && p) p = a[p].lnk, len = a[p].len;
            if (a[p].ch[v]) len++, p = a[p].ch[v];
            if (len == n) {
                if (a[p].vis != q) ans += a[p].cnt, a[p].vis = q;
                if (a[a[p].lnk].len + 1 == n) p = a[p].lnk;
                len--;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}