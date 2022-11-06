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

vector< pair<int, bool> > data;

void compute_base() {
    static int i, j, k, bit;

    i = 0; j = 30;
    while (j >= 0 && i < data.size()) {
        bit = 1 << j;

        for (k = i; k < data.size(); k++)
            if (data[k].first & bit)
                break;

        if (k == data.size()) {
            j--;
            continue;
        }

        swap(data[i], data[k]);
        for (k = i + 1; k < data.size(); k++) {
            if (data[k].first & bit) {
                data[k].first ^= data[i].first;
                data[k].second ^= data[i].second;
            }
        }

        i++; j--;
    }

    bool any = false;
    for (auto e : data)
        if (e == mp(0, true))
            any = true;

    while (data.size() > 0) {
        if (data.back().first != 0) break;
        data.pop_back();
    }

    if (any) data.pb(mp(0, true));
}

struct aint {
    int dim, *from;
    int upd[4 * maxN + 11];
    vector<int> even[4 * maxN + 11], odd[4 * maxN + 11];

    void combine_data(int node) {
        data.clear();
        for (auto e : even[lSon]) data.pb(mp(e, false));
        for (auto e : even[rSon]) data.pb(mp(e, false));
        for (auto e : odd[lSon]) data.pb(mp(e ^ upd[node], true));
        for (auto e : odd[rSon]) data.pb(mp(e ^ upd[node], true));
        compute_base();

        odd[node].clear();
        even[node].clear();
        for (auto e : data) {
            if (e.second == false)
                even[node].pb(e.first);
            else
                odd[node].pb(e.first);
        }
    }

    void build(int node, int l, int r) {
        if (l == r) {
            upd[node] = from[l];
            odd[node] = {from[l]};
            even[node].clear();
            return;
        }

        int mid = (l + r) >> 1;
        build(lSon, l, mid);
        build(rSon, mid + 1, r);

        combine_data(node);
    }

    void init(int _dim, int* _from) {
        from = _from;
        dim = _dim;
        build(1, 1, dim);
    }

    void update(int node, int l, int r, int qL, int qR, int val) {
        if (qL <= l && r <= qR) {
            upd[node] ^= val;
            for (auto& e : odd[node]) e ^= val;
            return;
        }

        int mid = (l + r) >> 1;
        if (qL <= mid) update(lSon, l, mid, qL, qR, val);
        if (qR > mid) update(rSon, mid + 1, r, qL, qR, val);
        combine_data(node);
    }

    void que(int node, int l, int r, int qL, int qR, int dif) {
        if (qL <= l && r <= qR) {
            for (auto e : even[node])
                data.pb(mp(e, false));
            for (auto e : odd[node])
                data.pb(mp(e ^ dif, true));

            compute_base();
            return;
        }

        int mid = (l + r) >> 1;
        if (qL <= mid) que(lSon, l, mid, qL, qR, dif ^ upd[node]);
        if (qR > mid) que(rSon, mid + 1, r, qL, qR, dif ^ upd[node]);
    }
};

int n, q, i, l, r, k, op;
int a[maxN], ans;
aint work;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &q);
    for (i = 1; i <= n; i++) scanf("%d", &a[i]);
    work.init(n, a);

    for (i = 1; i <= q; i++) {
        scanf("%d%d%d", &op, &l, &r);
        if (op == 1) {
            scanf("%d", &k);
            work.update(1, 1, n, l, r, k);
        } else {
            data.clear();
            work.que(1, 1, n, l, r, 0);

            ans = data.size();
            if (data.back().first == 0) ans--;
            printf("%d\n", 1 << ans);
        }
    }



    return 0;
}