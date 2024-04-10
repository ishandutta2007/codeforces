#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
int const maxn = 1e6 + 5;
int a[maxn];
pair < ll, int > dp[maxn];
ll inf = 1e18;

inline int check(int n, int l, int cost) {
    for (int i = 1; i <= n; ++i) {
        dp[i] = {dp[i - 1].first + a[i], dp[i - 1].second};
        pair < ll, int > cur = dp[max(i - l, 0)];
        cur.first += cost, cur.second++;
        dp[i] = min(dp[i], cur);
    }
    return dp[n].second;
}

inline ll solve(int n, int k, int l) {
    if ((ll)k * (ll)l >= n) return 0;
    int lcost = 0, rcost = n + 1;
    while (rcost - lcost > 1) {
        int mid = (rcost + lcost) / 2;
        if (check(n, l, mid) > k) lcost = mid;
        else rcost = mid;
    }
    if (check(n, l, lcost) <= k) return 0;
    check(n, l, rcost);
    return dp[n].first - (ll)rcost * k;
}

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k, l;
    cin >> n >> k >> l;
    string s;
    cin >> s;
    s = "#" + s;
    for (int i = 1; i <= n; ++i) {
        if ('a' <= s[i] && s[i] <= 'z') a[i] = 0;
        else a[i] = 1;
    }
    ll ans = solve(n, k, l);
    for (int i = 1; i <= n; ++i) a[i] = (a[i]^1);
    ans = min(ans, solve(n, k, l));
    cout << ans << '\n';
    return 0;
}