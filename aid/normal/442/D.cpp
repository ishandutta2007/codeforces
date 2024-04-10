#include <iostream>

using namespace std;

const int MAXN = 1000 * 1000 + 5;
int p[MAXN], dp[MAXN], maxdp[MAXN][2], ans[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i <= n; i++) {
        maxdp[i][0] = MAXN - 1;
        maxdp[i][1] = MAXN - 1;
    }
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
        p[i]--;
    }
    for(int i = 1; i <= n; i++) {
        dp[i] = 1;
        int v = i;
        while(v) {
            if(dp[v] > dp[maxdp[p[v]][0]]) {
                maxdp[p[v]][1] = maxdp[p[v]][0];
                maxdp[p[v]][0] = v;
            }
            else if(v != maxdp[p[v]][0] && dp[v] > dp[maxdp[p[v]][1]])
                maxdp[p[v]][1] = v;
            v = p[v];
            int olddp = dp[v];
            if(v)
                dp[v] = max(dp[maxdp[v][0]], dp[maxdp[v][1]] + 1);
            else
                dp[v] = dp[maxdp[v][0]];
            if(dp[v] == olddp)
                break;
        }
        ans[i - 1] = dp[0];
    }
    for(int i = 0; i < n; i++)
        cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}