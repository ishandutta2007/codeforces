#include <bits/stdc++.h>

using namespace std;
#define int long long
const int inf = 1e16;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector <pair <int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    vector <int> dp(k, -inf);
    vector <int> bl(k);
    for (int i = 0; i < min(a[0].first + 1, k); ++i) {
        int kol = (a[0].first - i) / k, now = (a[0].first - i) % k;
        if (now + a[0].second >= k || now == 0) {
            dp[i] = kol + (now + a[0].second) / k;
            bl[i] = (now + a[0].second) % k;
        }
    }
    for (int i = 1; i < n; ++i) {
        vector <int> dpp = dp;
        vector <int> bll = bl;
        for (int j = 0; j < min(k, a[i].first + 1); ++j) {
            int kol = (a[i].first - j) / k, now = (a[i].first - j) % k;
            if (now == 0 || (now + a[i].second >= k)) {
                kol += (now + a[i].second) / k;
                int b = (now + a[i].second) % k;
                for (int l = 0; l < k; ++l) {
                    int koll = kol;
                    int r, bb;
                    if (l + j >= k) {
                        ++koll;
                        r = l + j - k;
                    }
                    else {
                        r = l + j;
                    }
                    if (bl[l] + b >= k) {
                        ++koll;
                        bb = bl[l] + b - k;
                    }
                    else {
                        bb = bl[l] + b;
                    }
                    if (dpp[r] < dp[l] + koll || (dpp[r] == dp[l] + koll && bll[r] < bb)) {
                        dpp[r] = dp[l] + koll;
                        bll[r] = bb;
                    }
                }
            }
        }
        dp = dpp;
        bl = bll;
    }
    cout << *max_element(dp.begin(), dp.end());
}