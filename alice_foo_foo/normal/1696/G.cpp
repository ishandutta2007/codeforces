#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename T>
inline void read(T &f) {
    f = 0; T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const ll INF = 1e18;
const int N = 2e5 + 5;

struct atom { long double a[3][3]; };

atom operator + (const atom a, const atom b) {
    atom ans;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            long double val = -INF;
            for (int k = 0; k < 3; k++) {
                for (int t = 0; t < 3; t++) {
                    if (k + t <= 2) {
                        val = max(val, a.a[i][k] + b.a[t][j]);
                    }
                }
            }
            ans.a[i][j] = val;
        }
    }
    return ans;
}

struct node_t { int l, r; atom sum; } p[N << 2];

long double t[3];
int a[N];
int n, q, x, y;

void update(int u) {
    p[u].sum = p[u << 1].sum + p[u << 1 | 1].sum;
}

void build(int u, int l, int r) {
    p[u].l = l; p[u].r = r;
    if (l == r) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == j) p[u].sum.a[i][j] = t[i] * a[l];
                else p[u].sum.a[i][j] = -INF;
            }
        }
        return;
    }
    int mid = (l + r) >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    update(u);
}

void modify(int u, int x, int y) {
    if (p[u].l == p[u].r) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == j) p[u].sum.a[i][j] = t[i] * y;
                else p[u].sum.a[i][j] = -INF;
            }
        }
        return;
    }
    int mid = (p[u].l + p[u].r) >> 1;
    if (mid >= x) modify(u << 1, x, y);
    else modify(u << 1 | 1, x, y);
    update(u);
}

atom query(int u, int l, int r) {
    if (l <= p[u].l && p[u].r <= r) return p[u].sum;
    int mid = (p[u].l + p[u].r) >> 1;
    if (mid >= l && mid + 1 <= r) return query(u << 1, l, r) + query(u << 1 | 1, l, r);
    if (mid >= l) return query(u << 1, l, r);
    return query(u << 1 | 1, l, r);
}

int main() {
    read(n); read(q); read(x); read(y);
    t[0] = 0; t[1] = (long double)1 / (x + y); t[2] = (long double)1 / max(x, y);
    for (int i = 1; i <= n; i++) read(a[i]);
    build(1, 1, n);
    while (q--) {
        int opt, x, y;
        read(opt); read(x); read(y);
        if (opt == 1) modify(1, x, y);
        if (opt == 2) {
            atom res = query(1, x, y); long double ans = -INF;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    ans = max(ans, res.a[i][j]);
                }
            }
            printf("%.10lf\n", (double)ans);
        }
    }
    return 0;
}