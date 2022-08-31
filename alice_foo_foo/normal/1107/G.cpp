#include <bits/stdc++.h>
#define int long long
#define Fast_cin ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> " << endl;
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while(c < '0' || c > '9') { if(c == '-') fu = -1; c = getchar(); }
    while(c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if(x < 0) putchar('-'), x = -x;
    if(x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 3e5 + 5;

struct info {
    int lmax, rmax, sum;
    info () { lmax = rmax = sum = 0; }
};

info merge(info a, info b) {
    info ans;
    ans.lmax = max(a.lmax, a.sum + b.lmax);
    ans.rmax = max(b.rmax, b.sum + a.rmax);
    ans.sum = a.sum + b.sum;
    return ans;
}

struct node_t {
    int l, r;
    info val;
} p[N << 2];

int a[N], d[N];
int n, k, ans;

void build(int u, int l, int r) {
    p[u].l = l; p[u].r = r;
    if(l == r) {
        p[u].val.lmax = p[u].val.rmax = max(0ll, a[l]);
        p[u].val.sum = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(u << 1, l, mid); build(u << 1 | 1, mid + 1, r);
    p[u].val = merge(p[u << 1].val, p[u << 1 | 1].val);
}

info query(int u, int l, int r) {
    if(l > r) return info();
    if(l <= p[u].l && p[u].r <= r) return p[u].val;
    int mid = (p[u].l + p[u].r) >> 1;
    if(mid >= l && mid + 1 <= r) return merge(query(u << 1, l, r), query(u << 1 | 1, l, r));
    if(mid >= l) { return query(u << 1, l, r); } return query(u << 1 | 1, l, r);
}

int st[N][20], wz[N][20], lg[N];

pii query(int l, int r) {
    int k = lg[r - l + 1];
    int x = st[l][k], y = st[r - (1 << k) + 1][k];
    if(x > y) return make_pair(x, wz[l][k]);
    return make_pair(y, wz[r - (1 << k) + 1][k]);
}

void solve(int l, int r) {
    if(l == r) return;
    pii t = query(l, r - 1);
    int wz = t.second, now = a[wz] + a[wz + 1] - t.first;
    now += (query(1, l, wz - 1).rmax + query(1, wz + 2, r).lmax);
    ans = max(ans, now); solve(l, wz); solve(wz + 1, r);
}

#undef int
int main() {
#define int long long
    read(n); read(k);
    for(register int i = 1; i <= n; i++) read(d[i]), read(a[i]), a[i] = k - a[i], ans = max(ans, a[i]);
    build(1, 1, n);
    for(register int i = 1; i < n; i++) {
        st[i][0] = (d[i + 1] - d[i]) * (d[i + 1] - d[i]);
        wz[i][0] = i;
    }
    lg[0] = -1; for(register int i = 1; i < n; i++) lg[i] = lg[i >> 1] + 1;
    for(register int j = 1; j <= 18; j++) {
        for(register int i = 1; i <= n; i++) {
            int x = st[i][j - 1], y = st[i + (1 << (j - 1))][j - 1];
            if(x > y) st[i][j] = x, wz[i][j] = wz[i][j - 1];
            else st[i][j] = y, wz[i][j] = wz[i + (1 << (j - 1))][j - 1];
        }
    }
    solve(1, n); cout << ans << endl;
    return 0;
}