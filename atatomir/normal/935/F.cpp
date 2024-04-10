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

struct segm {
    ll data[maxN * 4 + 1];

    segm() {
        memset(data, 0, sizeof(data));
    }

    void upd(int node, int l, int r, int pos, ll v) {
        if (l == r) {
            data[node] = v;
            return;
        }

        int mid = (l + r) >> 1;
        if (pos <= mid) upd(lSon, l, mid, pos, v);
        else            upd(rSon, mid + 1, r, pos, v);

        data[node] = min(data[lSon], data[rSon]);
    }

    ll que(int node, int l, int r, int qL, int qR) {
        if (qL <= l && r <= qR) return data[node];

        int mid = (l + r) >> 1;
        ll ans = 1LL << 60;

        if (qL <= mid) ans = min(ans, que(lSon, l, mid, qL, qR));
        if (qR > mid) ans = min(ans, que(rSon, mid + 1, r, qL, qR));
        return ans;
    }
};

ll n, q, i, tp, l, r, x;
ll a[maxN];
ll aib[maxN], act;

ll dif_l[maxN];
ll dif_r[maxN];
segm work;

ll zrs(ll x) {
    return (x ^ (x - 1)) & x;
}

void upd(ll x, ll v) {
    while (x <= n) {
        aib[x] += v;
        x += zrs(x);
    }
}

ll sum(ll x) {
    ll ans = 0;
    while (x > 0) {
        ans += aib[x];
        x -= zrs(x);
    }
    return ans;
}

ll abss(ll x) {
    if (x < 0) return -x;
    return x;
}

void refresh(int pos) {
    int pre = sum(pos);
    int nxt = sum(pos + 1);

    dif_l[pos] = max(0LL, sum(pos) - sum(pos + 1));
    dif_r[pos] = max(0LL, sum(pos + 1) - sum(pos));

    for (int i = max(1, pos - 1); i <= min(n - 2, 1LL * pos); i++) {
        work.upd(1, 1, n, i, dif_l[i] + dif_r[i + 1]);
    }
}

void update() {
    int pre, nxt;

    if (l > 1) act -= abss(sum(l) - sum(l - 1));
    if (r + 1 <= n) act -= abss(sum(r) - sum(r + 1));

    upd(l, +x);
    upd(r + 1, -x);

    if (l > 1) act += abss(sum(l) - sum(l - 1));
    if (r + 1 <= n) act += abss(sum(r) - sum(r + 1));

    refresh(l - 1);
    refresh(r);
}

ll check(ll pos) {
    ll ans = act;

    if (pos > 1) ans -= abss(sum(pos - 1) - sum(pos));
    if (pos + 1 <= n) ans -= abss(sum(pos + 1) - sum(pos));

    upd(pos, +x);
    upd(pos + 1, -x);

    if (pos > 1) ans += abss(sum(pos - 1) - sum(pos));
    if (pos + 1 <= n) ans += abss(sum(pos + 1) - sum(pos));

    upd(pos, -x);
    upd(pos + 1, +x);

    return ans;
}

ll query() {
    ll ans = max(check(l), check(r));

    if (r - l + 1 >= 3)
        ans = max(ans, act + 2LL * x - 2LL * work.que(1, 1, n, l, r - 2));

    return ans;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%lld", &n);
    for (i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        upd(i, a[i] - a[i - 1]);

        if (i > 1) act += abss(a[i] - a[i - 1]);
    }

    for (i = 1; i < n; i++) {
        dif_l[i] = max(0LL, a[i] - a[i + 1]);
        dif_r[i] = max(0LL, a[i + 1] - a[i]);
    }

    for (i = 1; i + 2 <= n; i++)
        work.upd(1, 1, n, i, dif_l[i] + dif_r[i + 1]);

    scanf("%lld", &q);
    for (i = 1; i <= q; i++) {
        scanf("%lld%lld%lld%lld", &tp, &l, &r, &x);

        if (tp == 1)
            printf("%lld\n", query());
        else
            update();
    }


    return 0;
}