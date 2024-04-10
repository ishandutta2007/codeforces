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
#define pld pair<ld, ld>
#define pll pair<ll, ll>

const int INF = 1e9 + 1;
const ll INFLL = 1e18;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (auto &c : a) cin >> c;
    int g = 0;
    while (m--) {
        int x;
        cin >> x;
        g = __gcd(g, x);
    }
    vector<ll> dp(2);
    for (int i = 0; i < g; i++) {
        ll sum = 0, mn = INFLL;
        int cntneg = 0;
        for (int j = i; j < n; j += g) {
            sum += abs(a[j]);
            mn = min(mn, abs(a[j]));
            if (a[j] < 0) cntneg++;
        }
        dp[cntneg % 2] += sum;
        dp[1 - cntneg % 2] += sum - 2 * mn;
    }
    cout << max(dp[0], dp[1]) << "\n";
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
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}