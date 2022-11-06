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

struct intr {
    int l, r, node;
};

int k;
vector<int> list[maxN];
vector<intr> pos;

struct dsu {
    int n;
    vector<int> dad;
    vector<int> ch;

    void init(int _n) {
        n = _n;
        dad = vector<int>(n + 11, 0);
        ch.clear();

        for (int i = 1; i <= n; i++) dad[i] = i;
    }

    int Find(int x) {
        if (dad[x] == x) return x;
        dad[x] = Find(dad[x]);
        return dad[x];
    }

    bool Merge(int x, int y) {
        x = Find(x);
        y = Find(y);

        if (x == y) return false;
        dad[x] = y;
        return true;
    }

    int _Find(int x) {
        if (dad[x] == x) return x;
        ch.pb(x);
        dad[x] = _Find(dad[x]);
        return dad[x];
    }

    bool _Merge(int x, int y) {
        x = Find(x);
        y = Find(y);

        if (x == y) return false;
        ch.pb(x);
        dad[x] = y;
        return true;
    }

};

struct aint {
    int n;
    vector<int> cnt;
    vector<dsu> data;

    void combine(int delta, int l1, int r1, int l2, int r2, int &cnt_dest, dsu &data_dest) {
        for (int node = l1; node <= r1; node++) {
            for (auto to : list[node]) {
                if (to < l2) continue;
                if (to > r2) continue;

                if (data_dest.Merge(node - delta, to - delta))
                    cnt_dest--;
            }
        }
    }

    void build(int node, int l, int r) {
        int sz = r - l + 1;
        static int i;

        if (sz == 1) {
            cnt[node] = 1;
            data[node].init(1);
            return;
        }

        int mid = (l + r) >> 1;
        build(lSon, l, mid);
        build(rSon, mid + 1, r);

        cnt[node] = cnt[lSon] + cnt[rSon];
        data[node].init(sz);

        for (i = l; i <= mid; i++) data[node].dad[i - l + 1] = data[lSon].dad[i - l + 1];
        for (i = mid + 1; i <= r; i++) data[node].dad[i - l + 1] = data[rSon].dad[i - mid] + (mid - l + 1);

        combine(l - 1, max(l, mid - k + 1), mid, mid + 1, min(r, mid + k), cnt[node], data[node]);
    }

    void init(int _n) {
        n = _n;
        cnt.resize(n * 4 + 11);
        data.resize(n * 4 + 11);

        build(1, 1, n);
    }

    void get_nodes(int node, int l, int r, int qL, int qR) {
        if (qL <= l && r <= qR) {
            pos.pb({l, r, node});
            return;
        }

        int mid = (l + r) >> 1;
        if (qL <= mid) get_nodes(lSon, l, mid, qL, qR);
        if (qR > mid) get_nodes(rSon, mid + 1, r, qL, qR);
    }

};

int n, m, q, i, x, y, l, r;
aint work;
dsu global;

int query(int l, int r) {
    int i, j;
    int ans = 0;
    intr fr, se;
    int node, R1, R2;

    pos.clear();
    work.get_nodes(1, 1, n, l, r);

    for (auto e : pos)
        ans += work.cnt[e.node];

    for (i = 0; i < pos.size(); i++) {
        fr = pos[i];

        for (j = i + 1; j < pos.size(); j++) {
            se = pos[j];

            if (fr.r + k < se.l) break;

            for (node = max(fr.l, se.l - k); node <= fr.r; node++) {
                for (int to : list[node]) {
                    if (to < se.l) continue;
                    if (to > se.r) continue;

                    R1 = work.data[fr.node].Find(node - fr.l + 1);
                    R2 = work.data[se.node].Find(to - se.l + 1);

                    if (global._Merge(fr.l + R1 - 1, se.l + R2 - 1))
                        ans--;
                }
            }
        }
    }

    for (auto e : global.ch)
        global.dad[e] = e;
    global.ch.clear();

    return ans;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d%d", &n, &k, &m);
    for (i = 1; i <= m; i++) {
        scanf("%d%d", &x, &y);
        if (x > y) swap(x, y);
        list[x].pb(y);
    }

    work.init(n);
    global.init(n);

    scanf("%d", &q);

    for (i = 1; i <= q; i++) {
        scanf("%d%d", &l, &r);
        printf("%d\n", query(l, r));
    }




    return 0;
}