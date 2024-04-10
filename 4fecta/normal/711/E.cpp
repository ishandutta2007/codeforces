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

const int MOD = 1e6 + 3;

int fpow(int b, int p) {
    if (!p) return 1;
    int ret = fpow(b, p / 2);
    if (p & 1) return ret * ret % MOD * b % MOD;
    return ret * ret % MOD;
}

int n, k;

int32_t main() {
    boost();

    cin >> n >> k;
    int st = n, ed = n - k + 1;
    if (n <= 60 && k > (1LL << n)) return 0 * printf("1 1\n");
    int den = fpow(2, n);
    int num = 1;
    for (int i = 0; i < k; i++) {
        num *= den - i; num %= MOD;
        if (!num) break;
    }
    int den2 = fpow(den, k);
    int cnt2 = n; k--;
    while (k) k >>= 1, cnt2 += k;
    int inv = fpow(2, cnt2); inv = fpow(inv, MOD - 2);
    num *= inv; den2 *= inv;
    num %= MOD, den2 %= MOD;
    num += MOD, den2 += MOD;
    num %= MOD, den2 %= MOD;
    printf("%lld %lld\n", (((den2 - num) % MOD) + MOD) % MOD, den2);

    return 0;
}