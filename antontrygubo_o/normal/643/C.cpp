#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int mod = (int)1e9 + 7;
const int maxN = 2 * (int)1e5 + 100;
ll t[maxN];
ld revT[maxN];
ll prefT[maxN];
ld prefRevT[maxN];
ld prefMult[maxN];
int n, k;
ld getCost(int from, int to) {
    return prefMult[to] - prefMult[from - 1] - prefT[from - 1] * (prefRevT[to] - prefRevT[from - 1]);
}
const int maxK = 55;
ld dp[maxK][maxN];
void computeDp(int i, int left, int right, int optLeft, int optRight) {
    int mid = (left + right) / 2;
    int bestk = -1;
    for (int k = optLeft; k + 1 <= min(mid, optRight + 1); k++) {
        if (dp[i - 1][k] + getCost(k + 1, mid) < dp[i][mid]) {
            dp[i][mid] = dp[i - 1][k] + getCost(k + 1, mid);
            bestk = k;
        }
    }
    if (left < mid) {
        computeDp(i, left, mid - 1, optLeft, bestk);
    }
    if (mid < right) {
        computeDp(i, mid + 1, right, bestk, optRight);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
        prefT[i] = prefT[i - 1] + t[i];
        prefRevT[i] = prefRevT[i - 1] + 1.0 / t[i];
    }
    for (int i = 1; i <= n; i++) {
        prefMult[i] = prefMult[i - 1] + (1.0 * prefT[i]) / t[i];
    }
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = (ld)1e18;
        }
    }
    dp[0][0] = 0;
    for (int i = 1; i <= k; i++) {
        computeDp(i, 1, n, 0, n);
    }
    cout << fixed << setprecision(10) << dp[k][n];
}