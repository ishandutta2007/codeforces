#include <bits/stdc++.h>

using namespace std;

#define pb emplace_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pii pair<int, int>
#define puu pair<unsigned, unsigned>
#define ll long long
#define mp make_pair
#define ui unsigned
#define ull unsigned long long
#define ld long double

const long long INFLL = 1e18;
const int INF = 1e9 + 5;
const int mod = 1e9 + 7;

void solve() {
    int k;
    cin >> k;
    vector<ll> dp(k + 1);
    dp[1] = 1;
    for (int i = 2; i <= k; i++) {
        dp[i] = 16 * ((dp[i - 1] * dp[i - 1]) % mod);
        dp[i] %= mod;
    }
    cout << (6 * dp[k]) % mod << "\n";
    return;
}

int main() {
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif
    int t = 1;
    while (t--) solve();
    return 0;
}