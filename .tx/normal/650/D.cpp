#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#include <memory.h>
#include <fstream>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rea(a, n) for (int i = 0; i < n; i++) sci(a[i])

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;
typedef long double ldouble;

using namespace std;

int a[888888];

struct SegmentTree {
    int* t;

    SegmentTree(int n) {
        t = new int[4 * n];
        memset(t, 0, sizeof(int) * 4 * n);
    }

    void upd_max(int i, int l, int r, int q, int x) {
        if (l + 1 == r) {
            t[i] = max(t[i], x);
            return;
        }
        int m = (l + r) >> 1;
        if (q < m) {
            upd_max(i * 2 + 1, l, m, q, x);
        } else {
            upd_max(i * 2 + 2, m, r, q, x);
        }
        t[i] = max(t[i * 2 + 1], t[i * 2 + 2]);
    }

    int get(int i, int l, int r, int ql, int qr) {
        if (l >= qr || r <= ql) {
            return 0;
        }
        if (ql <= l && r <= qr) {
            return t[i];
        }
        int m = (l + r) >> 1;
        return max(get(i * 2 + 1, l, m, ql, qr), get(i * 2 + 2, m, r, ql, qr));
    }
};

struct query {
    int a, b, id;

    query() {}

    query(int a, int b, int id) : a(a), b(b), id(id) { }

    bool operator<(const query& r) const {
        return a < r.a;
    }
};

query q[888888];

//int qa[444444];
//int qb[444444];


int all[888888];
int dl[888888];

int cc[888888];
int mm[888888];

int mxl[888888];
int mxr[888888];

int ans[888888];
bool counts[888888];

void gen() {
//    srand(31);
//    srand(time(0));
    ofstream out("input.txt");
    int n = rand() % 100;
    int m = 1;
    out << n << " " << m << "\n";
    for (int i = 0; i < n; i++) {
        out << rand() % 10 + 1 << " ";
    }
    out << "\n";
    for (int i = 0; i < m; i++) {
        out << rand() % n + 1 << " " << rand() % 10 + 1 << "\n";
    }
    out.close();
}

void stupid() {
    ifstream in("input.txt");
    int n, m;
    in >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        in >> a[i];
    }
    vector<int> d(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        in >> x >> y;
        --x;
        int oa = a[x];
        a[x] = y;
        d.assign(n, 1);
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < j; k++) {
                if (a[j] > a[k]) {
                    d[j] = max(d[j], d[k] + 1);
                }
            }
        }
        cerr << *max_element(d.begin(), d.end()) << "\n";
        a[x] = oa;
    }
    cerr << endl;
    in.close();
}

int main() {
//    gen();
//    stupid();
//    freopen("input.txt", "r", stdin);
    sciid(n, m);
    int ax = 0;
    for (int i = 0; i < n; i++) {
        sci(a[i]);
        all[ax++] = a[i];
    }
    for (int i = 0; i < m; i++) {
        sciid(x, y);
        --x;
        q[i] = query(x, y, i);
//        qa[i] = x;
//        qb[i] = y;
        all[ax++] = y;
    }
    sort(q, q + m);
    sort(all, all + ax);
    ax = unique(all, all + ax) - all;
    for (int i = 0; i < n; i++) {
        a[i] = lower_bound(all, all + ax, a[i]) - all;
    }
    for (int i = 0; i < m; i++) {
        q[i].b = lower_bound(all, all + ax, q[i].b) - all;
//        qb[i] = *lower_bound(all, all + ax, qb[i]);
    }

    SegmentTree stl(ax), str(ax);

    int qp = 0;

    for (int i = 0; i < n; i++) {
        while (qp < m && q[qp].a == i) {
            mxl[qp] = stl.get(0, 0, ax, 0, q[qp].b);
            qp++;
        }

        int cmx = stl.get(0, 0, ax, 0, a[i]);
        dl[i] = cmx + 1;
        stl.upd_max(0, 0, ax, a[i], cmx + 1);
    }

    qp = m - 1;

    for (int i = n - 1; i >= 0; i--) {
        while (qp >= 0 && q[qp].a == i) {
            mxr[qp] = str.get(0, 0, ax, q[qp].b + 1, ax);
            qp--;
        }

        int cmx = str.get(0, 0, ax, a[i] + 1, ax);
        str.upd_max(0, 0, ax, a[i], cmx + 1);
    }

    int rmx = 0;
    for (int i = 1; i < n; i++) {
        if (dl[i] >= dl[rmx]) {
            rmx = i;
        }
    }

    int lans = dl[rmx];

    for (int i = rmx; i >= 0; i--) {
        if (dl[i] == lans) {
            cc[dl[i]]++;
            mm[dl[i]] = max(mm[dl[i]], a[i]);
            counts[i] = true;
            continue;
        }
        if (mm[dl[i] + 1] > a[i]) {
            cc[dl[i]]++;
            mm[dl[i]] = max(mm[dl[i]], a[i]);
            counts[i] = true;
        }
    }

    for (int i = 0; i < m; i++) {
        int x = q[i].a;
        int y = q[i].b;

        int without = lans;
        if (cc[dl[x]] == 1 && counts[x]) {
            without--;
        }

        int with = mxl[i] + mxr[i] + 1;
        ans[q[i].id] = max(without, with);
    }

    for (int i = 0; i < m; i++) {
        printf("%d\n", ans[i]);
    }


    return 0;
}