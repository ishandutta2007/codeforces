#include <bits/stdc++.h>
using namespace std;

#define PB push_back
// #define int long long
#define LL long long
#define siz(a) ((int)((a).size()))
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
const int N = 1e5;
const int M = 1e7;
const int mod = 1e9 + 7;
const int inf = 1e9;
int read() {
    int x = 0, y = 0;
    char c = getchar();
    for (; c < '0' || c > '9'; c = getchar()) y |= (c == '-');
    for (; c >= '0' && c <= '9'; x = x * 10 + (c ^ 48), c = getchar());
    return (y ? -x : x);
}


// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/hash_policy.hpp>
// using namespace __gnu_pbds;
int a, b, q[N + 5], top, rt[N + 5], u[N + 5], tot, s[M + 5], id, ls[M + 5], rs[M + 5];
struct node {
    int x, y, z;
    bool operator<(const node &o) const {return y > o.y;}
} p[N + 5];

void ins(int &n, int l, int r, int k) {
    if(!n) n = ++id;
    ++s[n];
    if(l == r) return;
    int mid = (l + r) >> 1;
    if(k <= mid) ins(ls[n], l, mid, k);
    else ins(rs[n], mid + 1, r, k);
}
LL ask(int n, int l, int r, int L, int R) {
    if(!n) return 0;
    if(l >= L && r <= R) return s[n];
    int mid = (l + r) >> 1, res = 0;
    if(L <= mid) res += ask(ls[n], l, mid, L, R);
    if(mid < R) res += ask(rs[n], mid + 1, r, L, R);
    return res;
}

signed main() {
    // freopen("in1.in", "r", stdin);
    // freopen("out.out", "w", stdout);
    a = read();
    b = read();
    rep(i, 1, a) {
        p[i].x = read();
        p[i].y = read();
        p[i].z = read();
        // q[++top] = p[i].x - p[i].y;
        // q[++top] = p[i].x + p[i].y;
        q[++top] = p[i].x;
        u[++tot] = p[i].z;
    }
    sort(u + 1, u + tot + 1);
    tot = unique(u + 1, u + tot + 1) - u - 1;
    q[++top] = 2 * inf + 1;
    sort(q + 1, q + top + 1);
    top = unique(q + 1, q + top + 1) - q - 1;
    sort(p + 1, p + a + 1);
    LL ans = 0;
    rep(i, 1, a) {
        int L = p[i].x - p[i].y, R = p[i].x + p[i].y, M = p[i].x, o = p[i].z, l = p[i].z - b, r = p[i].z + b;
        l = lower_bound(u + 1, u + tot + 1, l) - u;
        r = upper_bound(u + 1, u + tot + 1, r) - u - 1;
        o = lower_bound(u + 1, u + tot + 1, o) - u;
        L = lower_bound(q + 1, q + top + 1, L) - q;
        R = upper_bound(q + 1, q + top + 1, R) - q - 1;
        M = lower_bound(q + 1, q + top + 1, M) - q;
        rep(j, l, r) ans += ask(rt[j], 1, top, L, R);
        ins(rt[o], 1, top, M);
    }
    cout << ans;
    return 0;
}