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

const int N = 5e5, ALPHA = 26, INF = 0x7f7f7f7f;

int n, m, id, ans = INF;
char str[N + 10];

int h(char c) { return c - 'a'; }

namespace SAM {
    struct Node {
        int lnk, ch[ALPHA], len, cnt[2], col;
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
        int x, y = a[lst].ch[c];
        if (y) return lst = (a[y].len == a[lst].len + 1) ? y : New(lst, y, c), void();
        for (a[x = ++atot].len = a[lst].len + 1; a[lst].ch[c] == 0; lst = a[lst].lnk) a[lst].ch[c] = x;
        if (a[y = a[lst].ch[c]].len == a[lst].len + 1) a[x].lnk = y, lst = x;
        else a[x].lnk = New(lst, y, c), lst = x;
    }
    void insert() {
        lst = rt;
        for (int i = 0; str[i]; i++) extend(h(str[i])), a[lst].cnt[id]++;
    }
} // namespace SAM
using namespace SAM;

void dfs(int u) {
    for (auto v : e[u]) dfs(v), a[u].cnt[0] += a[v].cnt[0], a[u].cnt[1] += a[v].cnt[1];
}

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

signed main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    Init(), scanf("%s", str), insert(), id++, scanf("%s", str), insert();
    for (int i = 2; i <= atot; i++) e[a[i].lnk].push_back(i);
    dfs(1);
    for (int i = 2; i <= atot; i++)
        if (a[i].cnt[0] == 1 && a[i].cnt[1] == 1) ans = min(ans, a[a[i].lnk].len + 1);
    return printf("%d\n", ans == INF ? -1 : ans), 0;
}