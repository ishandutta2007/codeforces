#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 100005, MOD = 1e9 + 7;

int t, n, k;

int fpow(int b, int p) {
    if (!p) return 1;
    int ret = fpow(b, p / 2);
    if (p & 1) return ret * ret % MOD * b % MOD;
    else return ret * ret % MOD;
}

int32_t main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        printf("%lld\n", fpow(n, k));
    }

    return 0;
}