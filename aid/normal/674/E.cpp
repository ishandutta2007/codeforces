#include <iostream>

using namespace std;

const int MAXN = 500 * 1000 + 5, MAXANS = 105;
int p[MAXN];
double dp[MAXN][MAXANS];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.setf(ios::fixed);
    cout.precision(12);
    int q;
    cin >> q;
    p[0] = -1;
    for(int i = 0; i < MAXANS; i++)
        dp[0][i] = 1;
    int n = 1;
    for(int i = 0; i < q; i++) {
        int t, v;
        cin >> t >> v;
        v--;
        if(t == 1) {
            p[n++] = v;
            v = n - 1;
            for(int j = 0; j < MAXANS; j++)
                dp[v][j] = 1;
            v = p[v];
            double x = 0.5;
            for(int j = 0; j < MAXANS && v != -1; j++) {
                double ndp = dp[v][j] * x;
                x = (1 + ndp) / (1 + dp[v][j]);
                dp[v][j] = ndp;
                v = p[v];
            }
        }
        else {
            double ans = 0;
            for(int j = 1; j < MAXANS; j++)
                ans += j * (dp[v][j] - dp[v][j - 1]);
            cout << ans << '\n';
        }
    }
    return 0;
}