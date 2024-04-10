#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

const int MOD = 1e9 + 7;

ll fpow(ll  b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}

int main() {
    boost();

    ll n;
    cin >> n;
//    pii dp[105];
//    dp[0] = {1, 0};
//    for (int i = 1; i < 105; i++) {
//        dp[i].s = dp[i - 1].s * 3 + dp[i - 1].f;
//        dp[i].f = dp[i - 1].f * 3 + dp[i - 1].s;
//        printf("%d %d %d\n", dp[i].f, dp[i].s, dp[i].f + dp[i].s);
//    }
    if (n == 0) {printf("1\n"); return 0;}
    ll b = fpow(2, n * 2 - 1, MOD);
    ll d = fpow(2, n - 1, MOD);
    printf("%lld\n", (b + d) % MOD);

    return 0;
}