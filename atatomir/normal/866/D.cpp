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

#define maxN 300011
#define lSon (node << 1)
#define rSon (lSon | 1)


struct aint {
    int dim;
    ll add[4 * maxN + 11], data[4 * maxN + 11];

    void init(int _dim) {
        dim = _dim;
    }

    void upd(int node, int l, int r, int qL, int qR, ll val) {
        if (qL <= l && r <= qR) {
            add[node] += val;
            data[node] += val;
            return;
        }

        int mid = (l + r) >> 1;
        if (qL <= mid)
            upd(lSon, l, mid, qL, qR, val);
        if (qR > mid)
            upd(rSon, mid + 1, r, qL, qR, val);

        data[node] = min(data[lSon], data[rSon]);
        data[node] += add[node];
    }
};


int n, i, act;
pair<int, int> p[maxN];
aint work;
ll ans, aux;


int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &p[i].first);
        p[i].second = i;
    }

    sort(p + 1, p + n + 1);
    work.init(n);

    work.upd(1, 1, n, p[1].second, n, +1);
    for (i = 2; i <= n; i++)
        work.upd(1, 1, n, p[i].second, n, -1);

    for (i = 1; i < n; i++) {
        aux = n - (i - (n - i) - 2LL * min(work.data[1], 0LL));
        aux /= 2;

        ans += aux * (p[i + 1].first - p[i].first);

        work.upd(1, 1, n, p[i + 1].second, n, +2);
    }


    printf("%lld", ans);


    return 0;
}