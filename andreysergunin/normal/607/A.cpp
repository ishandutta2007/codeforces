#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <map>

using namespace std;

const int MAXN = 100100;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    pair<int, int> a[MAXN];
    int dp[MAXN];
    a[0].first = -1e9;
    for (int i = 1; i <= n; i++)
        cin >> a[i].first >> a[i].second;
    sort(a, a + n + 1);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        int x = a[i].first - a[i].second - 1;
        int l = 0, r = i + 1;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (a[m].first <= x)
                l = m;
            else
                r = m;
        }
        dp[i] = dp[l] + 1;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, dp[i]);
    cout << n - ans;
    return 0;
}