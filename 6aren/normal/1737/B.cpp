#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include<cp/debugger.hpp>
#else 
#define debug(...) 42
#endif

long long calc(long long x) {
    if (x == 0) return 0;
    long long ans = 0;

    // calc i * i
    {
        long long l = 1, r = 2e9;
        int res = 0;
        while (r >= l) {
            long long mid = (l + r) / 2;
            if (mid * mid <= x) {
                res = mid;
                l = mid + 1;
            } else r = mid - 1;
        }
        ans += res;
    }

    // calc i * (i + 1)
    {
        long long l = 1, r = 2e9;
        int res = 0;
        while (r >= l) {
            long long mid = (l + r) / 2;
            if (mid * (mid + 1) <= x) {
                res = mid;
                l = mid + 1;
            } else r = mid - 1;
        }
        ans += res;
    }

    // calc i * (i + 2)
    {
        long long l = 1, r = 2e9;
        int res = 0;
        while (r >= l) {
            long long mid = (l + r) / 2;
            if (mid * (mid + 2) <= x) {
                res = mid;
                l = mid + 1;
            } else r = mid - 1;
        }
        ans += res;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        long long l, r;
        cin >> l >> r;
        cout << calc(r) - calc(l - 1) << '\n';
    }
    return 0;
}