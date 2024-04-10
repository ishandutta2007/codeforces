#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

int numz(int x, int s) {
    int blk = 1 << (s + 1);
    int ret = x / blk * (1 << s);
    int rem = min(1ll << s, x % blk + 1);
    return ret + rem;
}

int32_t main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        int ans = r - l;
        for (int i = 20; i >= 0; i--) {
            int cnt = numz(r, i) - numz(l - 1, i);
            ans = min(ans, cnt);
        }
        printf("%lld\n", ans);
    }

    return 0;
}