#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 200 * 1000 + 5, INF = 1000 * 1000 * 1000 + 5;
int dp[MAXN];
pair<int, int> p[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x, w;
        cin >> x >> w;
        p[i] = make_pair(x + w, x - w);
    }
    sort(p, p + n);
    dp[0] = 1;
    for(int i = 1; i < n; i++) {
        int pref = lower_bound(p, p + n, make_pair(p[i].second + 1, -INF)) - p;
        if(pref == 0)
            dp[i] = 1;
        else
            dp[i] = dp[pref - 1] + 1;
        dp[i] = max(dp[i], dp[i - 1]);
    }
    cout << dp[n - 1] << '\n';
    return 0;
}