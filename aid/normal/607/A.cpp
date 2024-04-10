#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100 * 1000 + 5;
pair<int, int> p[MAXN];
int dp[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> p[i].first >> p[i].second;
    sort(p, p + n);
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int j = lower_bound(p, p + n,
                            make_pair(p[i].first - p[i].second, 0)) - p - 1;
        dp[i] = (j == -1? 1 : dp[j] + 1);
        ans = max(ans, dp[i]);
    }
    ans = n - ans;
    cout << ans << '\n';
    return 0;
}