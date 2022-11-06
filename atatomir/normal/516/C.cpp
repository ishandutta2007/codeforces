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

#define maxN 200011
#define lSon (node << 1)
#define rSon (lSon | 1)
#define inf 1LL << 60

struct elem {
    ll le, ri, mid;
};

struct aint {
    int dim;
    elem data[maxN * 4 + 11];
    elem *from;

    elem combine(elem A, elem B) {
        return (elem){max(A.le, B.le), max(A.ri, B.ri), max(max(A.mid, B.mid), A.le + B.ri)};
    }

    void build(int node, int l, int r) {
        if (l == r) {
            data[node] = from[l];
            return;
        }

        int mid = (l + r) >> 1;
        build(lSon, l, mid);
        build(rSon, mid + 1, r);
        data[node] = combine(data[lSon], data[rSon]);
    }

    void init(int _dim, elem *_from) {
        dim = _dim;
        from = _from;
        build(1, 1, dim);
    }

    elem que(int node, int l, int r, int qL, int qR) {
        if (qL <= l && r <= qR)
            return data[node];

        int mid = (l + r) >> 1;
        elem ans = {-inf, -inf, -inf};

        if (qL <= mid) ans = combine(ans, que(lSon, l, mid, qL, qR));
        if (qR > mid) ans = combine(ans, que(rSon, mid + 1, r, qL, qR));
        return ans;
    }
};

int n, m, i, l, r;
ll d[maxN], h[maxN];
elem from[maxN];
aint work;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++) scanf("%lld", &d[i + 1]), d[i + n + 1] = d[i + 1];
    for (i = 1; i <= n; i++) scanf("%lld", &h[i]), h[i + n] = h[i];
    for (i = 1; i <= 2 * n; i++) {
        d[i] += d[i - 1];
        from[i] = {2 * h[i] - d[i], 2 * h[i] + d[i], -inf};
    }

    work.init(2 * n, from);
    for (i = 1; i <= m; i++) {
        scanf("%d%d", &l, &r);
        if (l > r) {
            cout << work.que(1, 1, 2 * n, r + 1, l - 1).mid;
        } else {
            cout << work.que(1, 1, 2 * n, r + 1, l + n - 1).mid;
        }

        cout << '\n';
    }


    return 0;
}