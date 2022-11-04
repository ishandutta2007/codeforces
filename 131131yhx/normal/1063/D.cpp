#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long

using namespace std;

const int Lim = 1000000;

int n, l, r, k;

int bigeq(int x, int y) {
    int tmp = x / y;
    while(tmp * y < x) tmp++;
    while((tmp - 1) * y >= x) tmp--;
    return tmp;
}

int smalleq(int x, int y) {
    int tmp = x / y;
    while(tmp * y > x) tmp--;
    while((tmp + 1) * y <= x) tmp++;
    return tmp;
}

signed main() {
    scanf("%lld%lld%lld%lld", &n, &l, &r, &k);
    r = (r + n - l) % n + 1;
    int ans = -1;
    // Case 2
    for(int i = 0; i <= Lim && i <= n; i++) {
        int L = max(r, r + r + i - n - 1), R = min(r + r, r + i), s = (k - 1) % (i + n) + 1;
        if(s <= R && s >= L) ans = i;
    }
    // Case 1
    for(int t = 0; t <= Lim; t++) {
        int k = ::k - t * n;
        int r1 = !t ? (k - r >= 0 ? n : -1) : smalleq(k - r, t);
        int r2 = smalleq(k + n + 1 - r - r, t + 1);
        int l1 = !t ? (k - r - r <= 0 ? 0 : n + 1) : bigeq(k - r - r, t);
        int l2 = bigeq(k - r, t + 1);
        if(max(l1, l2) <= min(min(r1, r2), n)) ans = max(ans, min(min(r1, r2), n));
    }
    printf("%lld\n", ans);
    return 0;
}