#include <iostream>

using namespace std;

const int MAXN = 100 * 1000 + 5;
const long long INF = 1000ll * 1000 * 1000 * 1000 * 1000 * 1000 + 5;
int v[MAXN], c[MAXN];
long long dp[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i++)
        cin >> v[i];
    for(int i = 0; i < n; i++) {
        cin >> c[i];
        c[i]--;
    }
    for(int t = 0; t < q; t++) {
        int a, b;
        cin >> a >> b;
        for(int i = 0; i < n; i++)
            dp[i] = -INF;
        int maxdp0 = -1, maxdp1 = -1;
        for(int i = 0; i < n; i++) {
            long long va = (long long)v[i] * a, vb = (long long)v[i] * b;
            if(va > 0 && dp[c[i]] != -INF) {
                dp[c[i]] += va;
                if(maxdp0 == -1 || dp[c[i]] > dp[maxdp0]) {
                    maxdp1 = maxdp0;
                    maxdp0 = c[i];
                }
                else if(maxdp0 != c[i] &&
                        (maxdp1 == -1 || dp[c[i]] > dp[maxdp1]))
                    maxdp1 = c[i];
            }
            int p = maxdp0 == c[i]? maxdp1 : maxdp0;
            long long pdp = p == -1? 0 : max(dp[p], 0ll);
            if(dp[c[i]] < pdp + vb) {
                dp[c[i]] = pdp + vb;
                if(maxdp0 == -1 || dp[c[i]] > dp[maxdp0]) {
                    maxdp1 = maxdp0;
                    maxdp0 = c[i];
                }
                else if(maxdp0 != c[i] &&
                        (maxdp1 == -1 || dp[c[i]] > dp[maxdp1]))
                    maxdp1 = c[i];
            }
        }
        long long ans = 0;
        for(int i = 0; i < n; i++)
            if(ans < dp[i])
                ans = dp[i];
        cout << ans << '\n';
    }
    return 0;
}