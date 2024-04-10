/*
    I will never forget it.
*/

// 392699

#include <bits/stdc++.h>

#define int long long

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

const int N = 1e5, RNDMAX = 1e9 + 7;

int n, q, seed, vmax, a[N + 10];

int qpow(int a, int b, int P) {
    int ret = 1;
    for (; b; b >>= 1, a = a * a % P) b & 1 ? ret = ret * a % P : 0;
    return ret;
}

int rnd() {
    int ret = seed;
    return seed = (seed * 7 + 13) % RNDMAX, ret;
}

namespace ChthollyTree {
    #define it set<Node>::iterator

    struct Node {
        mutable int l, r, v;
        Node(int l, int r = -1, int v = 0) : l(l), r(r), v(v) {}
        bool operator < (const Node &rhs) const { return l < rhs.l; }
    };
    set<Node> s;
    vector<pair<int, int> > arr;

    it split(int pos) {
        it p = s.lower_bound(Node(pos));
        if (p != s.end() && p->l == pos) return p;
        p--;
        int l = p->l, r = p->r, v = p->v;
        return s.erase(p), s.insert(Node(l, pos - 1, v)), s.insert(Node(pos, r, v)).first;
    }
    void assign(int l, int r, int v) {
        it pr = split(r + 1), pl = split(l);
        s.erase(pl, pr), s.insert(Node(l, r, v));
    }
    void add(int l, int r, int v) {
        it pr = split(r + 1), pl = split(l);
        for (it i = pl; i != pr; i++) i->v += v;
    }
    int qkth(int l, int r, int k) {
        it pr = split(r + 1), pl = split(l);
        arr.clear();
        for (it i = pl; i != pr; i++) arr.push_back(make_pair(i->v, i->r - i->l + 1));
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size(); i++) {
            k -= arr[i].second;
            if (k <= 0) return arr[i].first;
        }
        return -1;
    }
    int qpsum(int l, int r, int b, int P) {
        int ret = 0;
        it pr = split(r + 1), pl = split(l);
        for (it i = pl; i != pr; i++) ret = (ret + ((i->r - i->l + 1) * qpow(i->v % P, b, P) % P)) % P;
        return ret;
    }
} // namespace ChthollyTree
using namespace ChthollyTree;

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

signed main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    fr(n), fr(q), fr(seed), fr(vmax);
    for (int i = 1; i <= n; i++) a[i] = rnd() % vmax + 1, s.insert(Node(i, i, a[i]));
    for (int i = 1, opt, l, r, x, y; i <= q; i++) {
        opt = rnd() % 4 + 1, l = rnd() % n + 1, r = rnd() % n + 1;
        if (l > r) swap(l, r);
        if (opt == 3) x = rnd() % (r - l + 1) + 1, printf("%lld\n", qkth(l, r, x));
        else x = rnd() % vmax + 1;
        if (opt == 4) y = rnd() % vmax + 1, printf("%lld\n", qpsum(l, r, x, y));
        if (opt == 1) add(l, r, x);
        else if (opt == 2) assign(l, r, x);
    }
    return 0;
}