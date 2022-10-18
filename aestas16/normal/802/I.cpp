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
int fr() {
    int a;
    return fr(a), a;
}

const int N = 1e5, ALPHA = 26;

int n;
long long ans;
char str[N + 10];

int h(char c) { return c - 'a'; }

namespace SAM {
    struct Node {
        Node *lnk, *ch[ALPHA];
        int len, cnt;
        vector<Node*> e;
    } mem[(N << 1) + 10], *atot = mem, *rt = ++atot, *lst = rt;

    void Clr() {
        for (Node *i = mem; i <= atot; i++) i->len = i->cnt = 0, i->e.clear(), i->lnk = 0, memset(i->ch, 0, sizeof(i->ch));
        atot = mem, rt = ++atot, lst = rt, ans = 0;
    }
    void Init() {
        (rt->lnk = mem)->len = -1;
        for (int i = 0; i < ALPHA; i++) mem->ch[i] = rt;
    }
    Node *New(Node *p, Node *q, int c) {
        Node *x = ++atot;
        x->lnk = q->lnk, memcpy(x->ch, q->ch, sizeof(q->ch));
        for (x->len = p->len + 1, q->lnk = x; p->ch[c] == q; p = p->lnk) p->ch[c] = x;
        return x;
    }
    void extend(int c) {
        Node *x = ++atot, *y;
        for (x->len = lst->len + 1; lst->ch[c] == 0; lst = lst->lnk) lst->ch[c] = x;
        if ((y = lst->ch[c])->len == lst->len + 1) x->lnk = y, lst = x, x->cnt = 1;
        else x->lnk = New(lst, y, c), lst = x, x->cnt = 1;
    }
} // namespace SAM
using namespace SAM;

void dfs(Node *u) {
    for (auto v : u->e) dfs(v), u->cnt += v->cnt;
    if (u != rt) ans += 1ll * u->cnt * u->cnt * (u->len - u->lnk->len);
}

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

signed main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    for (int T = fr(); T--;) {
        Init(), scanf("%s", str + 1), n = strlen(str + 1);
        for (int i = 1; i <= n; i++) extend(h(str[i]));
        for (Node *i = rt + 1; i <= atot; i++) i->lnk->e.push_back(i);
        dfs(rt), printf("%lld\n", ans), Clr();
    }
    return 0;
}