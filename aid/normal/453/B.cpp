#include <iostream>
#include <cmath>

using namespace std;

const int MAXN = 105, MAXP = 17,
    MAXM = 1 << MAXP, MAXNUM = 60, INF = 1000 * 1000 * 1000 + 5;
int a[MAXN], dp[MAXN][MAXM], mask[MAXNUM], ans0[MAXN];
pair<int, int> p[MAXN][MAXM];
int pr[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 1; i < MAXNUM; i++)
        for(int j = 0; j < MAXP; j++)
            if(!(i % pr[j]))
                mask[i] += (1 << j);
    for(int i = 0; i <= n; i++)
        for(int j = 0; j < MAXM; j++)
            dp[i][j] = INF;
    dp[0][0] = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < MAXM; j++)
            for(int k = 1; k < 2 * a[i]; k++) {
                if(!(mask[k] & j)) {
                    int to = (mask[k] | j);
                    if(dp[i + 1][to] > dp[i][j] + abs(a[i] - k)) {
                        dp[i + 1][to] = dp[i][j] + abs(a[i] - k);
                        p[i + 1][to] = make_pair(k, j);
                    }
                }
            }
    int ans = INF;
    for(int i = 0; i < MAXM; i++)
        ans = min(ans, dp[n][i]);
    for(int i = 0; i < MAXM; i++)
        if(ans == dp[n][i]) {
            int q = i, nn = n;
            while(nn > 0) {
                ans0[nn - 1] = p[nn][q].first;
                q = p[nn][q].second;
                nn--;
            }
            break;
        }
    for(int i = 0; i < n; i++)
        cout << ans0[i] << ' ';
    cout << '\n';
    return 0;
}