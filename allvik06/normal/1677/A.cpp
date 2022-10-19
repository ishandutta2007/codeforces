#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <array>
#include <map>
#include <utility>
#include <set>
#include <cassert>

using namespace std;
const int MAXN = 5e3;
int cnt[MAXN][MAXN];
#define ll long long

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cnt[i][j] = 0;
            }
        }
        for (int b = 0; b < n; ++b) {
            int now = 0;
            for (int i = b + 1; i < n; ++i) {
                if (a[i] < a[b]) ++now;
            }
            for (int c = b + 1; c < n; ++c) {
                if (a[c] < a[b]) --now;
                cnt[b][c] = now;
            }
        }
        for (int c = 0; c < n; ++c) {
            int now = 0;
            for (int i = 0; i < c; ++i) {
                if (a[i] < a[c]) ++now;
            }
            for (int b = c - 1; b >= 0; --b) {
                if (a[b] < a[c]) --now;
                cnt[c][b] = now;
            }
        }
        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                ans += cnt[i][j] * cnt[j][i];
            }
        }
        cout << ans << "\n";
    }
    return 0;
}