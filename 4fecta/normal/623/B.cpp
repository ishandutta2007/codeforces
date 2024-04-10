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

const int MN = 1000005;

int n, x, y, a[MN], dp[MN][3], sieve[MN];
vector<int> primes;

int upd(int num) {
    for (int i = 0; i < MN; i++) for (int j = 0; j < 3; j++) dp[i][j] = 1LL << 50;
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] % num == 0) {
            dp[i][0] = min(dp[i][0], dp[i - 1][0]);
            dp[i][2] = min(dp[i][2], dp[i - 1][2]);
            dp[i][2] = min(dp[i][2], dp[i - 1][1]);
        } else if ((a[i] + 1) % num == 0 || (a[i] - 1) % num == 0) {
            dp[i][0] = min(dp[i][0], dp[i - 1][0] + y);
            dp[i][2] = min(dp[i][2], dp[i - 1][2] + y);
            dp[i][2] = min(dp[i][2], dp[i - 1][1] + y);
        }
        dp[i][1] = min(dp[i][1], dp[i - 1][1] + x);
        dp[i][1] = min(dp[i][1], dp[i - 1][0] + x);
    }
    return min({dp[n][0], dp[n][1], dp[n][2]});
}

bool prime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++) if (x % i == 0) return false;
    return true;
}

int check(int num) {
    int ans = 1LL << 60;
    for (int i = 2; i * i <= num; i++) {
        if (num % i) continue;
        ans = min(ans, upd(i));
        while (num % i == 0) num /= i;
    }
    if (num > 1) ans = min(ans, upd(num));
    return ans;
}

int32_t main() {
    boost();

    for (int i = 2; i < MN; i++) {
        if (sieve[i]) continue;
        primes.push_back(i);
        for (int j = i + i; j < MN; j += i) sieve[j] = 1;
    }

    cin >> n >> x >> y;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int ans = 1LL << 60;
    ans = min(ans, check(a[1] + 1));
    ans = min(ans, check(a[1]));
    ans = min(ans, check(a[1] - 1));
    ans = min(ans, check(a[n] + 1));
    ans = min(ans, check(a[n]));
    ans = min(ans, check(a[n] - 1));
    printf("%lld\n", ans);

    return 0;
}