#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 100011
#define lSon (node << 1)
#define rSon (lSon | 1)

struct aint {
    int dim;
    ll data[4 * maxN][10];
    char lazy[4 * maxN][10];
    ll sol[10], aux[10];
    ll *from;

    void build(int node, int l, int r) {
        for (int i = 0; i < 10; i++) lazy[node][i] = i;

        if (l == r) {
            for (int i = 0; i < 10; i++) data[node][i] = 0;

            ll aux = from[l];
            ll bit = 1;
            for (; aux != 0; aux /= 10, bit *= 10) {
                int cf = aux % 10;
                data[node][cf] += bit;
            }

            return;
        }

        int mid = (l + r) >> 1;
        build(lSon, l, mid);
        build(rSon, mid + 1, r);

        for (int i = 0; i < 10; i++) data[node][i] = data[lSon][i] + data[rSon][i];
    }

    void init(int _dim, ll *_from) {
        dim = _dim;
        from = _from;

        build(1, 1, dim);
    }

    void propagate(int node) {
        static int i;

        for (auto son : {lSon, rSon}) {
            memcpy(aux, data[son], sizeof(aux));
            memset(data[son], 0, sizeof(data[son]));

            for (i = 0; i < 10; i++) {
                lazy[son][i] = lazy[node][ lazy[son][i] ];
                data[son][lazy[node][i]] += aux[i];
            }
        }

        for (i = 0; i < 10; i++) lazy[node][i] = i;
    }

    void upd(int node, int l, int r, int qL, int qR, int x, int y) {
        if (l != r) propagate(node);

        if (qL <= l && r <= qR) {
            for (int i = 0; i < 10; i++) {
                if (lazy[node][i] == x)
                    lazy[node][i] = y;
            }
            data[node][y] += data[node][x];
            data[node][x] = 0;
            return;
        }

        int mid = (l + r) >> 1;
        if (qL <= mid)
            upd(lSon, l, mid, qL, qR, x, y);
        if (qR > mid)
            upd(rSon, mid + 1, r, qL, qR, x, y);

        for (int i = 0; i < 10; i++)
            data[node][i] = data[lSon][i] + data[rSon][i];
    }

    //! set sol to 0 if you want to use this function
    void que(int node, int l, int r, int qL, int qR) {
        if (l != r) propagate(node);

        if (qL <= l && r <= qR) {
            for (int i = 0; i < 10; i++)
                sol[i] += data[node][i];
            return;
        }

        int mid = (l + r) >> 1;
        if (qL <= mid)
            que(lSon, l, mid, qL, qR);
        if (qR > mid)
            que(rSon, mid + 1, r, qL, qR);
    }
};

int n, q, i, cf, op, l, r, x, y;
ll vals[maxN];
aint work;

int main()
{
    //freopen("test.in","r",stdin);

    cin >> n >> q;
    for (i = 1; i <= n; i++) cin >> vals[i];
    work.init(n, vals);

    for (i = 1; i <= q; i++) {
        cin >> op >> l >> r;

        if (op == 1) {
            cin >> x >> y;
            if (x != y) work.upd(1, 1, n, l, r, x, y);
        } else {
            memset(work.sol, 0, sizeof(work.sol));
            work.que(1, 1, n, l, r);

            ll ans = 0;
            for (cf = 1; cf < 10; cf++)
                ans += work.sol[cf] * cf;

            cout << ans << '\n';
        }
    }

    return 0;
}