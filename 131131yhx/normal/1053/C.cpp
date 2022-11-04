#include <cstdio>
#include <cstring>
#include <algorithm>
#define P 1000000007
#define int long long

using namespace std;

int n, q, A[200010], W[200010], Sm1[800010], Sm2[800010];

void upd(int x) {
    Sm1[x] = (Sm1[x * 2] + Sm2[x * 2 + 1]) % P;
    Sm2[x] = (Sm2[x * 2] + Sm2[x * 2 + 1]) % P;
}

/*void build(int x, int L, int R) {
    if(L == R) Sm1[x] = A[L], Sm2[x] = (A[L] - L) * W[L] % P;
    else {
        build(x * 2, L, (L + R) / 2);
        build(x * 2 + 1, (L + R) / 2 + 1, R);
        upd(x);
    }
}

void modify(int x, int L, int R, int v) {
    if(L == R) {
        Sm1[x] = A[v];
        Sm2[x] = (A[v] - L) * W[v] % P;
        return;
    }
    if(v <= (L + R) / 2) modify(x * 2, L, (L + R) / 2, v);
    else modify(x * 2 + 1, (L + R) / 2, R, v);
    upd(x);
}

int getsum1(int x, int L, int R, int l, int r) {
    if(L == l && R == r) return Sm1[x];
    int md = (L + R) / 2, ans = 0;
    if(l <= md) ans = getsum1(x * 2, L, md, l, min(md, r));
    if(r > md) ans += getsum1(x * 2 + 1, md + 1, R, max(md + 1, l), r);
    upd(x);
}

int getsum2(int x, int L, int R, int l, int r) {
    if(L == l && R == r) return Sm2[x];
    int md = (L + R) / 2, ans = 0;
    if(l <= md) ans = getsum1(x * 2, L, md, l, min(md, r));
    if(r > md) ans += getsum1(x * 2 + 1, md + 1, R, max(md + 1, l), r);
    upd(x);
}

int find(int x, int L, int R, int l, int v, int nw = 0) {
    int md = (L + R) / 2;
    if(L == R) {
        if((nw + Sm1[x]) * 2 < v) return L + 1; else return L;
    }
    if(l <= md) {
        if(getsum(L + 1, ))
    }
}*/

void add1(int x, int v) {
    for(int i = x; i <= n; i += i & -i) Sm1[i] = Sm1[i] + v;
}

void add2(int x, int v) {
    for(int i = x; i <= n; i += i & -i) Sm2[i] = (Sm2[i] + v) % P;
}

int ask1(int x) {
    int ans = 0;
    for(int i = x; i; i -= i & -i) ans = ans + Sm1[i];
    return ans;
}

int ask2(int x) {
    int ans = 0;
    for(int i = x; i; i -= i & -i) ans = (ans + Sm2[i]) % P;
    return ans;
}

#undef int
int main() {
#define int long long
    scanf("%lld%lld", &n, &q);
    for(int i = 1; i <= n; i++) scanf("%lld", &A[i]);
    for(int i = 1; i <= n; i++) scanf("%lld", &W[i]);
    for(int i = 1; i <= n; i++) {
        add1(i, W[i]);
        add2(i, (A[i] - i) * W[i] % P);
    }
    for(int T = 1; T <= q; T++) {
        int a, b;
        scanf("%lld%lld", &a, &b);
        if(a > 0) {
            int o = ask1(a - 1), p = ask1(b), v = p - o;
            int ans = a;
            for(int l = a, r = b; l <= r; ) {
                int md = (l + r) / 2;
                if((ask1(md) - o) * 2 >= v) ans = md, r = md - 1;
                else l = md + 1;
            }
            int tot = (A[ans] - ans) * ((ask1(ans) - ask1(a - 1)) % P) - (ask2(ans) - ask2(a - 1));
            tot = tot + (ask2(b) - ask2(ans)) - (A[ans] - ans) * ((ask1(b) - ask1(ans)) % P);
            printf("%lld\n", (tot % P + P) % P);
        } else {
            a = -a;
            add1(a, -W[a]);
            add2(a, -(A[a] - a) * W[a] % P);
            W[a] = b;
            add1(a, W[a]);
            add2(a, (A[a] - a) * W[a] % P);
        }
    }
    return 0;
    //build(1, 1, n);
}