#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

const int INF = 1e9, MAXC = 10000;
int _dp[2][MAXC + 5], arr[105], brr[105];
int *dp = _dp[0], *tdp = _dp[1];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        ll ans = 9e18, base = 0;
        cin >> n;
        for (int i = 1; i <= n; ++i)
            cin >> arr[i], base += (ll)arr[i] * arr[i];
        for (int i = 1; i <= n; ++i)
            cin >> brr[i], base += (ll)brr[i] * brr[i];
        if (n == 1) {
            cout << "0\n";
            continue;
        }
        base *= (n - 2);
        fill(dp, dp + MAXC + 1, INF);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            fill(tdp, tdp + MAXC + 1, INF);
            for (int j = 1; j <= MAXC; ++j) {
                if (j >= arr[i])
                    tdp[j] = min(tdp[j], dp[j - arr[i]] + brr[i]);
                if (j >= brr[i])
                    tdp[j] = min(tdp[j], dp[j - brr[i]] + arr[i]);
            }
            swap(dp, tdp);
        }
        for (int i = 1; i <= MAXC; ++i)
            ans = min(ans, (ll)i * i + (ll)dp[i] * dp[i]);
        cout << base + ans << "\n";
    }
}