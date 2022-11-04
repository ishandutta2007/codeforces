#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long
#define M 100010

using namespace std;

typedef long long ll;

ll L[M], n;

char ch[M];

signed main() {
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++) scanf("%lld", &L[i]);
    scanf("%s", ch + 1);
    int b = 1;
    ll _1 = 0, _2 = 0, ans = 0;
    for(int i = 1; i <= n; i++) {
        if(ch[i] == 'W') b = 0, _1 += L[i] * 2; else if(ch[i] == 'G') _2 += L[i] * 2;
        ans += L[i];
        int t = min(_1, L[i]);
        ans += 1 * t, L[i] -= t, _1 -= t;
        t = min(_2, L[i]);
        ans += 2 * t, L[i] -= t, _2 -= t;
        if(b == 0) ans += 3 * L[i]; else ans += 5 * L[i];
    }
    printf("%lld\n", ans);
    return 0;
}