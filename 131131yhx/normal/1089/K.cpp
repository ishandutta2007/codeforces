#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <set>
#include <vector>
#define M 1048576 * 4
#define int long long

using namespace std;

int Q, A[M], B[M];

int Tg[M], Mx[M], K[M], Bel[M];

const int MxN = 1e6;

void pd(int x) {
    if(Tg[x]) {
        Tg[x * 2] += Tg[x];
        Tg[x * 2 + 1] += Tg[x];
        Mx[x * 2] += Tg[x];
        Mx[x * 2 + 1] += Tg[x];
        Tg[x] = 0;
    }
}

void add(int x, int L, int R, int l, int r, int v) {
    if(L == l && R == r) {
        Tg[x] += v;
        Mx[x] += v;
        return;
    }
    pd(x);
    int md = (L + R) / 2;
    if(l <= md) add(x * 2, L, md, l, min(md, r), v);
    if(r > md) add(x * 2 + 1, md + 1, R, max(md + 1, l), r, v);
    Mx[x] = max(Mx[x * 2], Mx[x * 2 + 1]);
}

void modify(int x, int L, int R, int s, int v) {
    if(L == R) {
        K[x] = v;
        Mx[x] = Tg[x] + K[x];
        return;
    }
    pd(x);
    int md = (L + R) / 2;
    if(s <= md) modify(x * 2, L, md, s, v);
    else modify(x * 2 + 1, md + 1, R, s, v);
    Mx[x] = max(Mx[x * 2], Mx[x * 2 + 1]);
}

int ask(int x, int L, int R, int l, int r) {
    if(L == l && R == r) return Mx[x];
    int ans = -1e9;
    int md = (L + R) / 2;
    pd(x);
    if(l <= md) ans = max(ans, ask(x * 2, L, md, l, min(md, r)));
    if(r > md) ans = max(ans, ask(x * 2 + 1, md + 1, R, max(md + 1, l), r));
    Mx[x] = max(Mx[x * 2], Mx[x * 2 + 1]);
    return ans;
}

int asktg(int x, int L, int R, int s) {
    if(L == R) {
        return Tg[x];
    }
    pd(x);
    int md = (L + R) / 2, ans;
    if(s <= md) ans = asktg(x * 2, L, md, s);
    else ans = asktg(x * 2 + 1, md + 1, R, s);
    //Mx[x] = max(Mx[x * 2], Mx[x * 2 + 1]);
    return ans;
}

signed main() {
    scanf("%lld", &Q);
    for(int T = 1; T <= Q; T++) {
        char op[7];
        int a, b;
        scanf("%s", op);
        if(op[0] == '?') {
            scanf("%lld", &a);
            int ans = ask(1, 1, MxN, 1, a);
            ans -= asktg(1, 1, MxN, a + 1);
            printf("%lld\n", max(ans, a) - a);
        } else if(op[0] == '+') {
            scanf("%lld%lld", &a, &b);
            A[T] = a;
            B[T] = b;
            modify(1, 1, MxN, a, a);
            add(1, 1, MxN, 1, a, b);
        } else if(op[0] == '-') {
            scanf("%lld", &a);
            b = B[a], a = A[a];
            modify(1, 1, MxN, a, -1e18);
            add(1, 1, MxN, 1, a, -b);
        }
    }
    return 0;
}
/*
4
+ 2 3
? 2
? 1
? 4
*/