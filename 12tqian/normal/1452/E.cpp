
#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k; 
    cin >> n >> m >> k;
    vector<array<int, 2>> range(m);
    for (int i = 0; i < m; i++) {
        cin >> range[i][0] >> range[i][1];
        range[i][0]--, range[i][1]--;
    }
    sort(range.begin(), range.end(), [](array<int, 2>& a, array<int, 2> b) {
        return a[0] + a[1] < b[0] + b[1];
    });
    auto calc = [&](int a, int b, int c, int d) {
        int val = min(b, d) - max(a, c) + 1;
        return max(val, 0);
    };
    vector<vector<int>> sum1(m + 1, vector<int>(n, 0));
    vector<vector<int>> sum2(m + 1, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n - k + 1; j++) {
            sum1[i][j] += calc(range[i][0], range[i][1], j, j + k - 1); 
            if (i) sum1[i][j] += sum1[i - 1][j];
        }
    }
    for (int i = m - 1; i >= 0; i--) {
        for (int j = 0; j < n - k + 1; j++) {
            sum2[i][j] += calc(range[i][0], range[i][1], j, j + k - 1);
            if (i != m - 1) sum2[i][j] += sum2[i + 1][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
        int s1 = 0;
        int s2 = 0;
        for (int j = 0; j < n; j++) {
            s1 = max(s1, sum1[i][j]);
            s2 = max(s2, sum2[i + 1][j]);
        }
        ans = max(ans, s1 + s2);
    }
    cout << ans << '\n';
    return 0;
}