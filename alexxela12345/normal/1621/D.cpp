#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;

#define int ll

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> arr(2 * n, vector<int> (2 * n));
    for (int i = 0; i < 2 * n; i++) {
        for (int j = 0; j < 2 * n; j++) {
            cin >> arr[i][j];
        }
    }
    int ans = 0;
    for (int i = n; i < 2 * n; i++) {
        for (int j = n; j < 2 * n; j++) {
            ans += arr[i][j];
            arr[i][j] = 0;
        }
    }
    auto left = arr, right = arr, up = arr, down = arr;
    for (int i = 0; i < 2 * n; i++) {
        for (int j = 1; j < 2 * n; j++) {
            left[i][j] += left[i][j - 1];
        }
    }
    for (int i = 0; i < 2 * n; i++) {
        for (int j = 2 * n - 2; j >= 0; j--) {
            right[i][j] += right[i][j + 1];
        }
    }
    for (int i = 1; i < 2 * n; i++) {
        for (int j = 0; j < 2 * n; j++) {
            up[i][j] += up[i - 1][j];
        }
    }
    for (int i = 2 * n - 2; i >= 0; i--) {
        for (int j = 0; j < 2 * n; j++) {
            down[i][j] += down[i + 1][j];
        }
    }
    int min_ans = LLONG_MAX;
    /*for (int i = 0; i < 2 * n; i++) {
        for (int j = 0; j < 2 * n; j++) {
            if ((i / n) ^ (j / n)) {
                min_ans = min(min_ans, min(left[i][j], right[i][j]) + min(up[i][j], down[i][j]) - arr[i][j]);
            }
        }
    }*/
    min_ans = min(min_ans, arr[n][0]);
    min_ans = min(min_ans, arr[n][n - 1]);
    min_ans = min(min_ans, arr[2 * n - 1][0]);
    min_ans = min(min_ans, arr[2 * n - 1][n - 1]);
    min_ans = min(min_ans, arr[0][n]);
    min_ans = min(min_ans, arr[0][2 * n - 1]);
    min_ans = min(min_ans, arr[n - 1][n]);
    min_ans = min(min_ans, arr[n - 1][2 * n - 1]);
    ans += min_ans;
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}