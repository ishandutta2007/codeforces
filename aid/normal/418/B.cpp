#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

const int MAXN = 105, POWM = 2000 * 1000 + 5;
const long long INF = 2000ll * 1000 * 1000 * 1000 * 1000 * 1000 + 5;
pair<pair<int, int>, int> a[MAXN];
long long dp[POWM];

int main() {
    ios_base::sync_with_stdio(false);
    int n, m, b;
    cin >> n >> m >> b;
    for(int i = 0; i < n; i++) {
        int mi;
        cin >> a[i].first.second >> a[i].first.first >> mi;
        for(int j = 0; j < mi; j++) {
            int pr;
            cin >> pr;
            a[i].second |= (1 << (pr - 1));
        }
    }
    sort(a, a + n);
    int pm = (1 << m);
    for(int i = 0; i < pm; i++)
        dp[i] = INF;
    dp[0] = 0;
    long long ans = INF;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < pm; j++) {
            if(dp[j] == INF)
                continue;
            int to = a[i].second | j;
            if(to != j && dp[to] > dp[j] + a[i].first.second)
                dp[to] = dp[j] + a[i].first.second;
        }
        if(dp[pm - 1] < INF)
            ans = min(ans, dp[pm - 1] + (long long)a[i].first.first * b);
    }
    if(ans == INF)
        cout << -1 << '\n';
    else
        cout << ans << '\n';
    return 0;
}