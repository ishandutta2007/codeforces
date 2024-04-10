#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 100005, MOD = 998244353;

int t, n, a[MN], fact[MN], inv[MN];
char c;

int fpow(int b, int p) {
    if (!p) return 1;
    int ret = fpow(b, p / 2);
    if (p & 1) return ret * ret % MOD * b % MOD;
    else return ret * ret % MOD;
}

int C(int n, int k) {
    return fact[n] * inv[k] % MOD * inv[n - k] % MOD;
}

int32_t main() {
    boost();

    fact[0] = inv[0] = 1;
    for (int i = 1; i < MN; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        inv[i] = fpow(fact[i], MOD - 2);
    }
    cin >> t;
    while (t--) {
        cin >> n;
        int tot = n, len = 0, cnt = 0;
        for (int i = 1; i <= n; i++) {
            cin >> c;
            a[i] = c - '0';
            if (a[i]) len++;
            else {
                cnt += len / 2;
                if (len % 2) tot--;
                len = 0;
            }
        }
        cnt += len / 2;
        if (len % 2) tot--;
        len = 0;
        tot -= 2 * cnt;
        tot += cnt;
        printf("%lld\n", C(tot, cnt));
    }

    return 0;
}