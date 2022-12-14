#include <bits/stdc++.h>

using namespace std;

long long a[122][122];

long long get(long long t, int x, int y) {
    memset(a, 0, sizeof a);
    a[0][0] = t;
    for (int i = 0; i <= x; i++) {
        for (int j = 0; j <= y; j++) {
            a[i][j + 1] += (a[i][j] + 1) / 2;
            a[i + 1][j] += a[i][j] / 2;
        }
    }
    return a[x][y];
}

void solve() {
    int x, y;
    long long t;
    cin >> t >> x >> y;
    if (t >= x + y and get(t - x - y + 1, x, y) > get(t - x - y, x, y))
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
}