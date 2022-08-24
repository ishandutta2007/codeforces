
#include <bits/stdc++.h>

using namespace std;

#define y1 some_variable
#define pb push_back
#define mp make_pair
#define fc first
#define sc second
#define ll long long
#define forn(i, n) for (int i = 0; i < (int) (n); i++)
#define fort(i, j, n) for (int i = j; i < (int) (n); i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define bit(x) __builtin_popcount(x)

const int MAXN = (int) 2e5 + 7;
int t[4 * MAXN];
int good[MAXN];

struct e {
    int type;
    int x;
    int start;
    int ind;
    int l, r;
    e() {}
    e(int a, int b, int c, int d, int e, int f) {
        type = a;
        x = b;
        start = c;
        ind = d;
        l = e;
        r = f;
    }
};

bool operator < (e a, e b) {
    return (a.type < b.type);
}

void build(int v, int l, int r) {
    if (r - l == 1) {
        t[v] = INT_MIN;
    } else {
        int m = (l + r) / 2;
        build(v * 2 + 1, l, m);
        build(v * 2 + 2, m, r);
        t[v] = min(t[v * 2 + 1], t[v * 2 + 2]);
    }
}

void upd(int v, int l, int r, int i, int x) {
    if (r - l == 1) {
        t[v] = x;
    } else {
        int m = (l + r) / 2;
        if (i < m) {
            upd(v * 2 + 1, l, m, i, x);
        } else {
            upd(v * 2 + 2, m, r, i, x);
        }
        t[v] = min(t[v * 2 + 1], t[v * 2 + 2]);
    }
}

int get(int v, int l, int r, int tl, int tr) {
    if (tl >= r || tr <= l) {
        return INT_MAX;
    } else if (tl >= l && tr <= r) {
        return t[v];
    } else {
        int tm = (tl + tr) / 2;
        return min(get(v * 2 + 1, l, r, tl, tm), get(v * 2 + 2, l, r, tm, tr));
    }
}

vector <e> pd[MAXN];//type, x, start, ind, l, r;
vector <e> sn[MAXN];

int main() {
    //freopen("rooks.in", "r", stdin);
   //freopen("rooks.out", "w", stdout);
    int n, m, k, q, x1, y1, x2, y2, x, y;
    scanf("%d%d%d%d", &n, &m, &k, &q);
    for (int i = 0; i < k; i++) {
        scanf("%d%d", &x, &y);
        pd[x].pb({-1, x, -1, -1, y, y});
        sn[y].pb({-1, y, -1, -1, x, x});
    }
    for (int i = 0; i < q; i++) {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        pd[x1].pb({1, x1, x1, i, y1, y2});
        pd[x2].pb({2, x2, x1, i, y1, y2});
        sn[y1].pb({1, y1, y1, i, x1, x2});
        sn[y2].pb({2, y2, y1, i, x1, x2});
    }
    build(0, 0, m + 1);
    for (int i = 0; i <= n; i++) {
        sort(all(pd[i]));
        for (auto q : pd[i]) {
            if (q.type == -1) {
                upd(0, 0, m + 1, q.l, i); 
            } else if (q.type == 1) {
                continue;
            } else if (q.type == 2) {
                good[q.ind] += (get(0, q.l, q.r + 1, 0, m + 1) >= q.start);
            } else {
                assert(0);
            }
        }
    }
    build(0, 0, n + 1);
    for (int i = 0; i <= m; i++) {
        sort(all(sn[i]));
        for (auto q : sn[i]) {
            if (q.type == -1) {
                upd(0, 0, n + 1, q.l, i); 
            } else if (q.type == 1) {
                continue;
            } else if (q.type == 2) {
                good[q.ind] += (get(0, q.l, q.r + 1, 0, n + 1) >= q.start);
            } else {
                assert(0);
            }
        }
    }
    for (int i = 0; i < q; i++) {
        if (good[i] > 0) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
}