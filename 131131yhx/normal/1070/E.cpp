#include <cstdio>
#include <cstring>
#include <algorithm>
#define M 200010
#define int long long

using namespace std;

int n, k, t, A[M], ans, ansd;

bool check(int x) {
    int as = 0, nw = 0, s = 0;
    for(int i = 1; i <= n; i++) if(A[i] <= x) {
        if(s == k) {
            s = 0;
            as += nw * 2;
            nw = 0;
        }
        s++;
        nw += A[i];
    }
    return as + nw > t;
}

void ask(int x) {
    int as = 0, nw = 0, s = 0, o = 0;
    for(int i = 1; i <= n; i++) if(A[i] <= x) {
        if(s == k) {
            s = 0;
            as += nw * 2;
            nw = 0;
        }
        nw += A[i];
        s++;
        o++;
        if(as + nw > t) {
            o--;
            if(ans < o) ans = o, ansd = x;
            return;
        }
    }
    if(ans < o) ans = o, ansd = x;
}

void Solve() {
    scanf("%lld%lld%lld", &n, &k, &t);
    for(int i = 1; i <= n; i++) scanf("%lld", &A[i]);
    int tmp = t;
    ans = 0, ansd = 1;
    for(int l = 1, r = t; l <= r; ) {
        int md = (l + r) / 2;
        if(check(md)) tmp = md, r = md - 1; else l = md + 1;
    }
    ask(tmp);
    ask(tmp - 1);
    printf("%lld %lld\n", ans, ansd);
}

signed main() {// no noip
    int Cas;
    scanf("%lld", &Cas);
    while(Cas--) {
        Solve();
    }
    return 0;
}