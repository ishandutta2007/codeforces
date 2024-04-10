#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long

using namespace std;

signed main() {
    int n, m;
    scanf("%lld%lld", &n, &m);
    int a = 0, b = 0, ans = 0;
    for(int i = 1; i <= n; i++) {
        int x;
        scanf("%lld", &x);
        x += a;
        if(x < m) {
            if(a) ans++, x = 0;
        } else {
            ans += x / m;
            x %= m;
        }
        a = x;
    }
    printf("%lld\n", ans + !!a);
    return 0;
}