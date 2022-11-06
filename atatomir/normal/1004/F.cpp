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

const int maxN = 100011;

int least;

struct zone {
    int bg, en;
    ll here;
    vector< pair<int, int> > le, ri;

    zone() {}

    zone(int pos, int v) {
        bg = en = pos;
        here = (v >= least ? 1 : 0);
        le = ri = {mp(v, pos)};
    }

    void err_check() {
        cerr << bg << ' ' << en << '\n';
        cerr << here << '\n';
        for (auto e : le) cerr << e.first << ' ' << e.second << ", ";
        cerr << '\n';
        for (auto e : ri) cerr << e.first << ' ' << e.second << ", ";
        cerr << '\n';
        cerr << '\n';
    }
};

zone combine(zone A, zone B) {
    zone ans;
    int act, i, j;

    ans.bg = A.bg;
    ans.en = B.en;
    ans.here = A.here + B.here;

    ans.le = A.le;
    act = ans.le.back().first;
    for (auto e : B.le) {
        if ((act | e.first) != act) {
            act |= e.first;
            ans.le.pb(mp(act, e.second));
        }
    }

    ans.ri = B.ri;
    act = ans.ri.back().first;
    for (auto e : A.ri) {
        if ((act | e.first) != act) {
            act |= e.first;
            ans.ri.pb(mp(act, e.second));
        }
    }

    j = B.le.size() - 1;
    for (i = 0; i < A.ri.size(); i++) {
        auto p1 = A.ri[i];
        auto p2 = B.le[j];

        if ((p1.first | p2.first) < least) continue;
        while (j > 0) {
            j--;
            p2 = B.le[j];
            if ((p1.first | p2.first) < least) {
                j++;
                p2 = B.le[j];
                break;
            }
        }

        ll s1 = p1.second - (i == A.ri.size() - 1 ? A.bg - 1 : A.ri[i + 1].second);
        ll s2 = B.en - p2.second + 1;
        ans.here += s1 * s2;
    }

    return ans;
}

struct aint {
    zone data[maxN * 4 + 11];

    void build(int node, int l, int r, int *from) {
        if (l == r) {
            data[node] = zone(l, from[l]);
            return;
        }

        int mid = (l + r) >> 1;
        build(lSon, l, mid, from);
        build(rSon, mid + 1, r, from);
        data[node] = combine(data[lSon], data[rSon]);
    }

    void upd(int node, int l, int r, int pos, int v) {
        if (l == r) {
            data[node] = zone(l, v);
            return;
        }

        int mid = (l + r) >> 1;
        if (pos <= mid) upd(lSon, l, mid, pos, v);
        else            upd(rSon, mid + 1, r, pos, v);
        data[node] = combine(data[lSon], data[rSon]);
    }

    zone que(int node, int l, int r, int qL, int qR) {
        if (qL <= l && r <= qR) 
            return data[node]; 

        int mid = (l + r) >> 1;
        if (qR <= mid) return que(lSon, l, mid, qL, qR);
        if (qL > mid) return que(rSon, mid + 1, r, qL, qR);
        return combine(que(lSon, l, mid, qL, qR), 
                       que(rSon, mid + 1, r, qL, qR));
    }
};

int n, m, i, tp, x, y;
int v[maxN];
aint work;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d%d", &n, &m, &least);
    for (i = 1; i <= n; i++) scanf("%d", &v[i]);
    work.build(1, 1, n, v);

    //work.data[1].err_check();

    for (i = 1; i <= m; i++) {
        scanf("%d%d%d", &tp, &x, &y);
        if (tp == 1) {
            work.upd(1, 1, n, x, y);
        } else {
            printf("%lld\n", work.que(1, 1, n, x, y).here);
        }
    }

    return 0;
}