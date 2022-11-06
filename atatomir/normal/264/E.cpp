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

#define sz 200100
#define maxN (sz + 11)
#define lSon (node << 1)
#define rSon (lSon | 1)

struct aib {
    int dim;
    vector<int> data;

    void init(int _dim) {
        dim = _dim;
        data = vector<int>(dim + 11, 0);
    }

    int zrs(int x) {
        return (x ^ (x - 1)) & x;
    }

    void add(int pos, int v) {
        while (pos <= dim) {
            data[pos] += v;
            pos += zrs(pos);
        }
    }

    int bs(int x) {
        int ans = 0;

        for (int step = 1 << 20; step > 0; step >>= 1)
            if (ans + step <= dim)
                if (data[ans + step] <= x)
                    ans += step, x -= data[ans];

        return ans;
    }
};

struct aint {
    int dim;
    vector<int> data;

    void init(int _dim) {
        dim = _dim;
        data = vector<int>(4 * dim + 11, 0);
    }

    void upd(int node, int l, int r, int pos, int v) {
        if (l == r) {
            data[node] = v;
            return;
        }

        int mid = (l + r) >> 1;
        if (pos <= mid)
            upd(lSon, l, mid, pos, v);
        else
            upd(rSon, mid + 1, r, pos, v);

        data[node] = max(data[lSon], data[rSon]);
    }

    int que(int node, int l, int r, int qL, int qR) {
        if (qL <= l && r <= qR)
            return data[node];

        int mid = (l + r) >> 1;
        int ans = 0;

        if (qL <= mid) ans = max(ans, que(lSon, l, mid, qL, qR));
        if (qR > mid) ans = max(ans, que(rSon, mid + 1, r, qL, qR));
        return ans;
    }
};

int n, m, i, op, x, h;
int act_h[maxN], who[maxN];
aib exist_x, exist_y;
aint work_x, work_y;

void add_point() {
    vector<int> to_add;
    int pos, aux, val;

    act_h[x] = h;
    who[h] = x;
    to_add.clear();

    while (true) {
        pos = exist_y.bs(0) + 1;
        if (pos > h) break;

        aux = who[pos];
        to_add.pb(aux);
        exist_x.add(aux, -1);
        exist_y.add(pos, -1);
        work_x.upd(1, 1, sz, aux, 0);
        work_y.upd(1, 1, sz, pos, 0);
    }

    to_add.pb(x);
    reverse(to_add.begin(), to_add.end());

    for (auto e : to_add) {
        val = work_x.que(1, 1, sz, e, sz) + 1;

        exist_x.add(e, +1);
        exist_y.add(act_h[e], +1);
        work_x.upd(1, 1, sz, e, val);
        work_y.upd(1, 1, sz, act_h[e], val);
    }
}

void rm_point() {
    vector<int> to_rm;
    int pos, aux, val;

    x = exist_x.bs(x - 1) + 1;

    to_rm.clear();

    while (true) {
        pos = exist_x.bs(0) + 1;
        if (pos > x) break;

        aux = act_h[pos];
        to_rm.pb(pos);
        exist_x.add(pos, -1);
        exist_y.add(aux, -1);
        work_x.upd(1, 1, sz, pos, 0);
        work_y.upd(1, 1, sz, aux, 0);
    }

    to_rm.pop_back();
    reverse(to_rm.begin(), to_rm.end());

    for (auto e : to_rm) {
        val = work_y.que(1, 1, sz, act_h[e], sz) + 1;

        exist_x.add(e, +1);
        exist_y.add(act_h[e], +1);
        work_x.upd(1, 1, sz, e, val);
        work_y.upd(1, 1, sz, act_h[e], val);
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    exist_x.init(sz);
    exist_y.init(sz);
    work_x.init(sz);
    work_y.init(sz);

    scanf("%d%d", &n, &m);

    for (i = 1; i <= m; i++) {
        scanf("%d%d", &op, &x);
        if (op == 1) {
            scanf("%d", &h);
            h += m - i;

            add_point();
        } else {
            rm_point();
        }

        printf("%d\n", work_x.data[1]);
    }


    return 0;
}