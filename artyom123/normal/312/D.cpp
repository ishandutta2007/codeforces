#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pb emplace_back
#define ld long double
#define pii pair<int, int>

const int INF = 1e9 + 1;
const ll INFLL = 2e18 + 1;

vector<ll> pr;

ll get(int l, int r) {
    return pr[r + 1] - pr[l];
}

vector<vector<ll>> dp;
vector<ll> a;

void solve(int l, int r, int optl, int optr, int k) {
    if (l > r) return;
    int m = (l + r) / 2;
    ll ans = INFLL;
    int optm = -1;
    for (int j = max(0, optl); j <= optr && j <= m; j++) {
        if (ans > dp[j][k - 1] + a[m] * (m - j + 1) - get(j, m)) {
            ans = dp[j][k - 1] + a[m] * (m - j + 1) - get(j, m);
            optm = j;
        }
    }
    dp[m + 1][k] = ans;
    solve(l, m - 1, optl, optm, k);
    solve(m + 1, r, optm, optr, k);
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n, m, p;
    cin >> n >> m >> p;
    p = min(p, m);
    vector<ll> d(n);
    for (int i = 0; i < n - 1; i++) {
        int x;
        cin >> x;
        d[i + 1] = d[i] + x;
    }
    a.resize(m);
    for (int i = 0; i < m; i++) {
        int h, t;
        cin >> h >> t;
        a[i] = t - d[h - 1];
    }
    sort(all(a));
    pr.resize(m + 1);
    for (int i = 0; i < m; i++) pr[i + 1] = pr[i] + a[i];
    dp.assign(m + 1, vector<ll>(p + 1, INFLL));
    dp[0][0] = 0;
    for (int k = 1; k <= p; k++) {
        solve(0, m - 1, 0, m - 1, k);
    }
    cout << dp[m][p];
    return 0;
}