/*
    I will never forget it.
*/

// 392699

#include <bits/stdc++.h>

using namespace std;

void fr(int &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + ch - '0';
    a = f ? -a : a;
}
int fr() {
    int a;
    return fr(a), a;
}

int n, q, sum;

namespace ChthollyTree {
    #define it set<Node>::iterator

    struct Node {
        mutable int l, r, v;
        Node(int l, int r = -1, int v = 0) : l(l), r(r), v(v) {}
        bool operator < (const Node &rhs) const { return l < rhs.l; }
    };
    set<Node> s;

    it split(int pos) {
        it p = s.lower_bound(Node(pos));
        if (p != s.end() && p->l == pos) return p;
        p--;
        int l = p->l, r = p->r, v = p->v;
        return s.erase(p), s.insert(Node(l, pos - 1, v)), s.insert(Node(pos, r, v)).first;
    }
    void assign(int l, int r, int v) {
        it pr = split(r + 1), pl = split(l);
        for (it i = pl; i != pr; i++) sum -= (i->r - i->l + 1) * i->v;
        s.erase(pl, pr), s.insert(Node(l, r, v)), sum += (r - l + 1) * v;
    }
} // namespace ChthollyTree
using namespace ChthollyTree;

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

signed main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    fr(n), fr(q), s.insert(Node(1, n, 1)), sum = n;
    for (int i = 1, opt, l, r; i <= q; i++) {
        fr(l), fr(r), fr(opt);
        assign(l, r, opt - 1), printf("%d\n", sum);
    }
    return 0;
}