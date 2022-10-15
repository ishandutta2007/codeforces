#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define int ll
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0); cin.sync_with_stdio(0)

int32_t main() {
    boost();
    srand(time(NULL));

    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        //a = rand() % 1000 + 1, b = rand() % 1000 + 1;
        /*int ans2 = 0;
        for (int i = 1; i <= b; i++) {
            for (int j = 1; j <= a; j++) {
                if (j % i == j / i) ans2++;
            }
        }*/
        int ans = 0;
        int lo = 1, hi = b, mid;
        while (lo < hi) {
            mid = (lo + hi + 1) >> 1;
            int cap = mid * mid - 1;
            if (cap > a) hi = mid - 1;
            else lo = mid;
        }
        //printf("%d\n", lo);
        for (int i = 1; i <= lo; i++) ans += i - 1;
        int pre = b;
        for (int freq = 0; freq < lo - 1; freq++) {
            int lo1 = 1, hi1 = b + 1;
            while (lo1 < hi1) {
                mid = (lo1 + hi1) >> 1;
                int num = (mid + 1) * (freq + 1);
                if (num > a) hi1 = mid;
                else lo1 = mid + 1;
            }
            //if (pre < lo1) break;
            //printf("%d %d %d\n", lo1, pre, freq);
            ans += (pre - lo1 + 1) * freq;
            pre = lo1 - 1;
        }
        //printf("%d %d\n", lo, pre);
        assert(lo <= pre);
        for (int i = lo + 1; i <= pre; i++) ans += lo - 1;
        printf("%lld\n", ans);
        //assert(ans2 == ans);
    }

    return 0;
}