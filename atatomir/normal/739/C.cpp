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

#define lSon (node << 1)
#define rSon (lSon | 1)

#define maxN 300011

struct aint {
    int n;
    vector<int> le0, le1, ri0, ri1, best;
    ll *from;

    void upd(int node, int l, int r) {
        int mid, d1, d2;
        int aux = 0;

        if (l == r) {
            best[node] = 0;
            le0[node] = le1[node] = ri0[node] = ri1[node] = 0;
            if (from[l] > 0)
                le1[node] = ri0[node] = 1;
            if (from[l] < 0)
                le0[node] = ri1[node] = 1;
        } else {
            mid = (l + r) >> 1;
            d1 = mid - l + 1;
            d2 = r - mid;

            //! le0
            le0[node] = le0[lSon];
            if (le0[lSon] == d1) le0[node] += le0[rSon];

            //! le1
            le1[node] = le1[lSon];
            if (le1[lSon] == d1) le1[node] += le0[rSon];
            if (le1[lSon] == d1 && from[mid] > 0) le1[node] = max(le1[node], d1 + le1[rSon]);

            //! ri0
            ri0[node] = ri0[rSon];
            if (ri0[rSon] == d2) ri0[node] += ri0[lSon];

            //! ri1
            ri1[node] = ri1[rSon];
            if (ri1[rSon] == d2) ri1[node] += ri0[lSon];
            if (ri1[rSon] == d2 && from[mid + 1] < 0) ri1[node] = max(ri1[node], d2 + ri1[lSon]);
        }

        le1[node] = max(le0[node], le1[node]);
        ri1[node] = max(ri0[node], ri1[node]);

        if (l != r) {
            aux = max(ri1[lSon] + le0[rSon], ri0[lSon] + le1[rSon]);
        }

        //! best
        best[node] = max(le0[node], le1[node]);
        best[node] = max(best[node], max(ri0[node], ri1[node]));
        best[node] = max(best[node], aux);
        if (l != r)
            best[node] = max(best[node], max(best[lSon], best[rSon]));
    }

    void build(int node, int l, int r) {
        if (l == r) {
            upd(node, l, r);
            return;
        }

        int mid = (l + r) >> 1;
        build(lSon, l, mid);
        build(rSon, mid + 1, r);
        upd(node, l, r);
    }

    void init(int _n, ll *_from) {
        n = _n; from = _from;
        le0.resize(n << 2);
        le1.resize(n << 2);
        ri0.resize(n << 2);
        ri1.resize(n << 2);
        best.resize(n << 2);
        build(1, 1, n);
    }

    void update(int node, int l, int r, int pos, ll val) {
        if (l == r) {
            from[l] += val;
            upd(node, l, r);
            return;
        }

        int mid = (l + r) >> 1;
        if (pos <= mid)
            update(lSon, l, mid, pos, val);
        if (pos > mid)
            update(rSon, mid + 1, r, pos, val);

        upd(node, l, r);
    }
};

int n, m, i, l, r, d;
ll data[maxN];
aint work;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%lld", &data[i]);
    for (i = n - 1; i > 0; i--) data[i] -= data[i - 1];

    scanf("%d", &m);
    if (n == 1) {
        for (i = 1; i <= m; i++) printf("1\n");
        return 0;
    }

    work.init(n - 1, data);

    for (i = 1; i <= m; i++) {
        scanf("%d%d%d", &l, &r, &d);

        if (l > 1) work.update(1, 1, n - 1, l - 1, +d);
        if (r < n) work.update(1, 1, n - 1, r, -d);
        printf("%d\n", work.best[1] + 1);
    }


    return 0;
}