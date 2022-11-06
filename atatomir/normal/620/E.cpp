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

#define maxN 400011
#define lSon (node << 1)
#define rSon (lSon | 1)

struct aint {
    int n;
    ll *data, *full;
    int *from, *who;

    void build(int node, int l, int r) {
        data[node] = full[node] = 0;

        if (l == r) {
            data[node] = full[node] = (1LL << from[ who[l] ]);
            return;
        }

        int mid = (l + r) >> 1;
        build(lSon, l, mid);
        build(rSon, mid + 1, r);

        data[node] = data[lSon] | data[rSon];
    }

    void init(int _n, ll *_data, ll *_full, int *_from, int *_who) {
        n = _n;
        data = _data;
        full = _full;
        from = _from;
        who = _who;

        build(1, 1, n);
    }

    void update(int node, int l, int r, int qL, int qR, int val) {
        if (qL <= l && r <= qR) {
            data[node] = full[node] = (1LL << val);
            return;
        }

        if (full[node]) {
            full[lSon] = data[lSon] = full[node];
            full[rSon] = data[rSon] = full[node];
            full[node] = 0;
        }

        int mid = (l + r) >> 1;
        if (qL <= mid)
            update(lSon, l, mid, qL, qR, val);
        if (qR > mid)
            update(rSon, mid + 1, r, qL, qR, val);

        data[node] = data[lSon] | data[rSon];
    }

    ll query(int node, int l, int r, int qL, int qR) {
        if (qL <= l && r <= qR)
            return data[node];

        if (full[node]) {
            full[lSon] = data[lSon] = full[node];
            full[rSon] = data[rSon] = full[node];
            full[node] = 0;
        }

        int mid = (l + r) >> 1;
        ll ans = 0;

        if (qL <= mid)
            ans |= query(lSon, l, mid, qL, qR);
        if (qR > mid)
            ans |= query(rSon, mid + 1, r, qL, qR);

        return ans;
    }

};


int n, q, i, x, y, tp;
int col[maxN];
vector<int> list[maxN];

int cnt;
int l[maxN], r[maxN], who[maxN];

ll data[maxN << 2], full[maxN << 2];
aint work;


void dfs(int node) {
    l[node] = ++cnt;
    who[cnt] = node;

    for (int to : list[node]) {
        if (!l[to])
            dfs(to);
    }

    r[node] = cnt;
}

int pop_count(ll x) {
    int ans = 0;

    while (x) {
        ans++;
        x &= x - 1;
    }

    return ans;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &q);
    for (i = 1; i <= n; i++) scanf("%d", &col[i]);
    for (i = 1; i < n; i++) {
        scanf("%d%d", &x, &y);
        list[x].pb(y);
        list[y].pb(x);
    }

    dfs(1);
    work.init(n, data, full, col, who);

    for (i = 1; i <= q; i++) {
        scanf("%d%d", &tp, &x);

        if (tp == 1) {
            scanf("%d", &y);
            work.update(1, 1, n, l[x], r[x], y);
        } else {
            ll aux = work.query(1, 1, n, l[x], r[x]);
            printf("%d\n", pop_count(aux));
        }
    }

    return 0;
}