#include <iostream>
#include <bitset>

using namespace std;

const int MAXN = 55, MAXC = 10 * 1000 + 5, INF = 1000 * 1000 * 1000 + 5;
int c[MAXN];
bitset<MAXN * MAXC> dp[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int n, d;
    cin >> n >> d;
    for(int i = 0; i < n; i++)
        cin >> c[i];
    dp[0][0] = true;
    dp[0][c[0]] = true;
    for(int i = 1; i < n; i++)
        dp[i] = dp[i - 1] | (dp[i - 1] << c[i]);
    int ans = 0, t = 0;
    while(true) {
        int cost = min(ans + d, MAXN * MAXC);
        while(!dp[n - 1][cost])
            cost--;
        if(cost <= ans)
            break;
        ans = cost;
        t++;
    }
    cout << ans << ' ' << t << '\n';
    return 0;
}