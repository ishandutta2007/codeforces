#include <iostream>

using namespace std;

const int MAXN = 20, POWN = (1 << MAXN);
int popcnt[POWN];
double p[MAXN], dp[POWN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.setf(ios::fixed);
    cout.precision(12);
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> p[i];
    for(int i = 0; i < (1 << n); i++)
        popcnt[i] = __builtin_popcount(i);
    for(int s = 0; s < n; s++) {
        if(p[s] < 1e-9) {
            cout << 0. << ' ';
            continue;
        }
        swap(p[s], p[n - 1]);
        dp[0] = p[n - 1];
        double ans = dp[0];
        for(int i = 1; i < (1 << (n - 1)); i++) {
            double ss = 0;
            dp[i] = 0;
            for(int j = 0; j < n - 1; j++)
                if(i & (1 << j)) {
                    dp[i] += dp[i ^ (1 << j)] * p[j];
                    ss += p[j];
                }
            dp[i] /= 1 - ss;
            if(popcnt[i] < k)
                ans += dp[i];
        }
        cout << ans << ' ';
        swap(p[s], p[n - 1]);
    }
    cout << '\n';
    return 0;
}