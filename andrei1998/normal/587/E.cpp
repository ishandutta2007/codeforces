#include <iostream>
#include <algorithm>
#include <vector>

#define lsb(x) ((x) & (-(x)))
using namespace std;

const int NMAX = 2 * 100005;

int n;
int v[NMAX];

int dv[NMAX];

int aib[NMAX];
inline void add_aib (int where, int val) {
    for (; where <= n; where += lsb(where))
        aib[where] ^= val;
}

inline int query_aib (int where) {
    int ans = 0;
    for (; where; where -= lsb(where))
        ans ^= aib[where];

    return ans;
}

struct node {
    int st, dr;
    vector <int> base;

    inline void compute () {
        int sz = 0, j = 0;
        for (int i = 0; i <= 29; ++ i) {
            for (j = sz; j < base.size(); ++ j)
                if (base[j] & (1 << i))
                    break;

            if (j == base.size())
                continue ;

            swap(base[sz], base[j]);

            for (j = sz + 1; j < base.size(); ++ j)
                if (base[j] & (1 << i))
                    base[j] ^= base[sz];

            ++ sz;
        }

        base.resize(sz);
    }

    node (int _st = 0, int _dr = 0): st(_st), dr(_dr) {}
} arb[4 * NMAX];

inline void unite (node &a, node b, node &c) {
    c.base.clear();
    for (auto it: a.base)
        c.base.push_back(it);
    for (auto it: b.base)
        c.base.push_back(it);
    c.compute();
}

void build (int st, int dr, int pos) {
    arb[pos].st = st, arb[pos].dr = dr;

    if (st == dr) {
        arb[pos].base.push_back(dv[st]);
        return ;
    }

    int mijl = (st + dr) >> 1;
    build(st, mijl, pos << 1);
    build(mijl + 1, dr, (pos << 1) + 1);

    unite(arb[pos << 1], arb[(pos << 1) + 1], arb[pos]);
}

void update (int where, int val, int pos) {
    if (arb[pos].st == arb[pos].dr && arb[pos].st == where) {
        arb[pos].base.front() ^= val;
        return ;
    }

    int mijl = (arb[pos].st + arb[pos].dr) >> 1;
    if (where <= mijl)
        update(where, val, pos << 1);
    else
        update(where, val, (pos << 1) + 1);
    unite(arb[pos << 1], arb[(pos << 1) + 1], arb[pos]);
}

node ans;
void query (int st, int dr, int pos) {
    if (arb[pos].st == st && arb[pos].dr == dr) {
        unite(arb[pos], ans, ans);
        return ;
    }

    int mijl = (arb[pos].st + arb[pos].dr) >> 1;
    if (dr <= mijl)
        query(st, dr, pos << 1);
    else if (st > mijl)
        query(st, dr, (pos << 1) + 1);
    else {
        query(st, mijl, pos << 1);
        query(mijl + 1, dr, (pos << 1) + 1);
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);

    int q = 0;
    cin >> n >> q;

    for (int i = 1; i <= n; ++ i) {
        cin >> v[i];
        add_aib(i, v[i] ^ v[i - 1]);
    }

    for (int i = 1; i < n; ++ i)
        dv[i] = v[i] ^ v[i + 1];

    if (n > 1)
        build(1, n - 1, 1);

    int t, l, r, k;
    while (q --) {
        cin >> t >> l >> r;

        if (t == 1) {
            cin >> k;

            add_aib(l, k);
            add_aib(r + 1, k);

            if (l > 1)
                update(l - 1, k, 1);
            if (r < n)
                update(r, k, 1);
        }
        else {
            ans.base.clear();
            if (l < r)
                query(l, r - 1, 1);

            ans.base.push_back(query_aib(r));
            ans.compute();

            cout << (1 << ans.base.size()) << '\n';
        }
    }

    return 0;
}