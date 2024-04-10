//#pragma GCC optimize("Ofast,unroll-loops,fast-math,inline,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx,popcnt")
#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, p, k;
        cin >> n >> p >> k;
        string s;
        cin >> s;
        int x, y;
        cin >> x >> y;
        vector<int> dp(n);
        for (int i = n - 1; i >= 0; i--) {
            if (i + k < n) {
                dp[i] = dp[i + k];
            }
            if (s[i] == '0') {
                dp[i] += x;
            }
        }
        for (int i = 0; i < n; i++) {
            if (i + p - 1 < n) {
                dp[i] = dp[i + p - 1];
            } else {
                dp[i] = 1e9 + 228;
            }
        }
        int min_ans = 1e9 + 228;
        for (int i = 0; i < n; i++) {
            min_ans = min(min_ans, y * i + dp[i]);
        }
        cout << min_ans << endl;
    }
}