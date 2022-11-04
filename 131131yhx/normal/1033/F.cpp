#include <cstdio>
#include <cstring>
#include <algorithm>

#define ct(x) __builtin_popcount(x)
#define int long long

using namespace std;

int w, n, m, X[1 << 12], Y[1 << 12], Ans[(1 << 24)], ans = 0;

char ch[15];

void FWT(int tot) {
    for(int b = 1; b < tot; b *= 2)
        for(int i = 0; i < tot; i += b + b)
            for(int j = i; j < i + b; j++) {
                int A = Y[j], B = Y[j + b];
                Y[j] = A + B;
                Y[j + b] = A - B;;
            }
}

void IFWT(int tot) {
    for(int b = 1; b < tot; b *= 2)
        for(int i = 0; i < tot; i += b + b)
            for(int j = i; j < i + b; j++) {
                int A = Y[j], B = Y[j + b];
                Y[j] = A + B;
                Y[j + b] = A - B;
            }
}

void Search(int x, int mask = 0) {
    if(x == -1) {
        ans += Ans[mask];
        return;
    }
    if(ch[x] == 'A') Search(x - 1, mask * 4), Search(x - 1, mask * 4 + 2); else
    if(ch[x] == 'O') Search(x - 1, mask * 4); else
    if(ch[x] == 'X') Search(x - 1, mask * 4), Search(x - 1, mask * 4 + 1); else
    if(ch[x] == 'a') Search(x - 1, mask * 4 + 1); else
    if(ch[x] == 'o') Search(x - 1, mask * 4 + 1), Search(x - 1, mask * 4 + 2); else
    if(ch[x] == 'x') Search(x - 1, mask * 4 + 2);
}

signed main() {
    scanf("%lld%lld%lld", &w, &n, &m);
    while(n--) {
        int x;
        scanf("%lld", &x);
        X[x]++;
    }
    for(int x = 0; x < (1 << w); x++) {
        int rx = (1 << w) - x - 1;
        int tot = 1 << ct(x);
        for(int a = rx; ; a = (a - 1) & rx) {
            for(int xx = x, v = tot - 1; v != -1; xx = (xx - 1) & x, v--) Y[v] += X[xx + a];
            FWT(tot);
            for(int i = 0; i < tot; i++) Y[i] *= Y[i];
            IFWT(tot);
            int tt = 0;
            for(int i = 0; i < w; i++) tt = tt + (((x >> i & 1) * 2 + (a >> i & 1)) << i + i);
            Ans[tt] = Y[tot - 1] / tot;
            for(int i = 0; i < tot; i++) Y[i] = 0;
            if(!a) break;
        }
    }
    while(m--) {
        ans = 0;
        scanf("%s", ch);
        reverse(ch, ch + w);
        Search(w - 1);
        printf("%lld\n", ans);
    }
    return 0;
}