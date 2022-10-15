#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

const int MN = 200005;

int n, k, l1, r1, l2, r2;

int cross(pii x, pii y) {
    return max(0ll, min(x.s, y.s) - max(x.f, y.f));
}

int32_t main() {
    boost();

    int t;
    cin >> t;
    outer: while (t--) {
        cin >> n >> k >> l1 >> r1 >> l2 >> r2;
        int lft = min(l1, l2), rit = max(r1, r2);
        if (l1 > l2) swap(l1, l2), swap(r1, r2);
        int cur = max(0ll, min(r1, r2) - l2);
        k -= cur * n;
        if (k <= 0) {
            printf("0\n");
            goto outer;
        }
        int len = 0, ans = 0, opt = 1LL << 60;
        for (int i = 1; i <= n; i++) {
            pii x = {l1, r1}, y = {l2, r2};
            int add = 0, moves = 0;
            if (x.s - x.f >= y.s - y.f) {
                moves += y.f - lft;
                y.f = lft;
                add = cross(x, y) - cur;
                if (len + add >= k) {
                    ans += moves;
                    ans -= len + add - k;
                    printf("%lld\n", min(ans, opt));
                    goto outer;
                }
            } else {
                moves += rit - x.s;
                x.s = rit;
                add = cross(x, y) - cur;
                if (len + add >= k) {
                    ans += moves;
                    ans -= len + add - k;
                    printf("%lld\n", min(ans, opt));
                    goto outer;
                }
            }
            if (x.s - x.f >= y.s - y.f) {
                moves += rit - y.s;
                y.s = rit;
                add = cross(x, y) - cur;
                if (len + add >= k) {
                    ans += moves;
                    ans -= len + add - k;
                    printf("%lld\n", min(ans, opt));
                    goto outer;
                }
            } else {
                moves += rit - x.s;
                x.s = rit;
                add = cross(x, y) - cur;
                if (len + add >= k) {
                    ans += moves;
                    ans -= len + add - k;
                    printf("%lld\n", min(ans, opt));
                    goto outer;
                }
            }
            if (x.s - x.f >= y.s - y.f) {
                moves += y.f - lft;
                y.f = lft;
                add = cross(x, y) - cur;
                if (len + add >= k) {
                    ans += moves;
                    ans -= len + add - k;
                    printf("%lld\n", min(ans, opt));
                    goto outer;
                }
            } else {
                moves += rit - x.s;
                x.s = rit;
                add = cross(x, y) - cur;
                if (len + add >= k) {
                    ans += moves;
                    ans -= len + add - k;
                    printf("%lld\n", min(ans, opt));
                    goto outer;
                }
            }
            len += cross(x, y) - cur, ans += moves;
            opt = min(opt, ans + (k - len) * 2);
            //printf("%d %d %d %d %d %d\n", len, ans, x.f, x.s, y.f, y.s);
        }
        if (len < k) {
            ans += (k - len) * 2;
        }
        printf("%lld\n", min(ans, opt));
    }

    return 0;
}