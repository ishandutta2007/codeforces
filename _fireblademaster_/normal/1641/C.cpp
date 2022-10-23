#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>
#define setIO(x) freopen(x".in", "r", stdin), freopen(x".out", "w", stdout)
#define closefile fclose(stdin), fclose(stdout)
#define m_p make_pair
#define sz(x) (int)x.size()
#define see(x) cerr << x << " "
#define seeln(x) cerr << x << endl
#define out(x) cerr << #x << " = " << x << " "
#define outln(x) cerr << #x << " = " << x << endl
#define outarr(x, l, r) {cerr << #x"[" << l << " ~ " << r << "] = "; for (int _i = l; _i <= r; ++_i) cerr << x[_i] << " "; cerr << endl;}
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define gc() getchar()
//#define gc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
char buf[1 << 21], *p1 = buf, *p2 = buf;
template <class T> void read(T &x) {
    x = 0;
    int c = gc();
    int flag = 0;
    while (c < '0' || c > '9') {
        flag |= (c == '-'), c = gc();
    }
    while (c >= '0' && c <= '9') {
        x = (x << 3) + (x << 1) + (c ^ 48), c = gc();
    }
    if (flag) {
        x = -x;
    }
}
template <class T> bool checkmax(T &a, T b) {return a < b ? a = b, 1 : 0;}
template <class T> bool checkmin(T &a, T b) {return b < a ? a = b, 1 : 0;}
const int N = 300010, inf = 0x3f3f3f3f;
int n, q;
struct node {
    int op, l, r, x;
} Q[N];
int a[N], res[N];
namespace seg_tree {
    int t[N << 2], tg[N << 2], one[N << 2];
    int mrg(int x, int y) {return (x == 0 || y == 0) ? (x + y) : -1;}
    void upd(int u) {
        t[u] = max(t[u << 1], t[u << 1 | 1]);
        one[u] = mrg(one[u << 1], one[u << 1 | 1]);
    }
    void build(int u, int l, int r) {
        if (l == r) {
            one[u] = l;
            return;
        }
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        upd(u);
    }
    void setg(int u, int v) {t[u] = tg[u] = v, one[u] = 0;}
    void push(int u) {
        if (!tg[u]) {
            return;
        }
        setg(u << 1, tg[u]), setg(u << 1 | 1, tg[u]), tg[u] = 0;
    }
    void insert(int u, int l, int r, int L, int R, int v) {
        if (L <= l && r <= R) {
            setg(u, v);
            return;
        }
        int mid = (l + r) >> 1;
        push(u);
        if (L <= mid) {
            insert(u << 1, l, mid, L, R, v);
        }
        if (R > mid) {
            insert(u << 1 | 1, mid + 1, r, L, R, v);
        }
        upd(u);
    }
    int qry(int u, int l, int r, int L, int R) {
        if (L <= l && r <= R) {
            return t[u];
        }
        int mid = (l + r) >> 1;
        push(u);
        if (R <= mid) {
            return qry(u << 1, l, mid, L, R);
        }
        if (L > mid) {
            return qry(u << 1 | 1, mid + 1, r, L, R);
        }
        return max(qry(u << 1, l, mid, L, R), qry(u << 1 | 1, mid + 1, r, L, R));
    }
    int find_one(int u, int l, int r, int L, int R) {
        if (L <= l && r <= R) {
            return one[u];
        }
        int mid = (l + r) >> 1;
        push(u);
        if (R <= mid) {
            return find_one(u << 1, l, mid, L, R);
        }
        if (L > mid) {
            return find_one(u << 1 | 1, mid + 1, r, L, R);
        }
        return mrg(find_one(u << 1, l, mid, L, R), find_one(u << 1 | 1, mid + 1, r, L, R));
    }
}
void init() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= q; i++) {
        scanf("%d", &Q[i].op);
        if (Q[i].op == 1) {
            scanf("%d", &Q[i].x);
        } else {
            scanf("%d%d%d", &Q[i].l, &Q[i].r, &Q[i].x);
        }
    }
    seg_tree::build(1, 1, n);
}

void solve() {
    for (int i = q; i; i--)
        if (Q[i].op == 0 && Q[i].x == 0)
        { seg_tree::insert(1, 1, n, Q[i].l, Q[i].r, i); }
    for (int i = 1; i <= n; i++) {
        res[i] = inf;
    }
    for (int i = q; i; i--)
        if (Q[i].op == 0 && Q[i].x == 1) {
            int x = seg_tree::find_one(1, 1, n, Q[i].l, Q[i].r);
            if (x == -1) {
                continue;
            }
            int y = seg_tree::qry(1, 1, n, Q[i].l, Q[i].r);
            res[x] = min(res[x], max(y, i));
        }
    for (int i = 1; i <= q; i++)
        if (Q[i].op == 1) {
            int x = seg_tree::qry(1, 1, n, Q[i].x, Q[i].x);
            if (x == 0) {
                if (res[Q[i].x] > i) {
                    puts("N/A");
                } else {
                    puts("YES");
                }
            } else {
                if (x > i) {
                    puts("N/A");
                } else {
                    puts("NO");
                }
            }
        }
}

//#define CASES_WITH_T
int main() {
    int t = 1;
    #ifdef CASES_WITH_T
    scanf("%d", &t);
    #endif
    while (t--) {
        init();
        solve();
    }
    return 0;
}