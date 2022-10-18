#include <bits/stdc++.h>

using namespace std;

#define int int64_t
const int maxn = 2e5 + 42;
const int inf = 1e16;

void solve() {
    int n, m;
    cin >> n >> m;
    int a[n][m];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
            a[i][j] = (a[i][j] + 1) / 2;
        }
    }
    int target = n + m - 1;
    if(target % 2) {
        cout << "NO\n";
        return;
    }
    target /= 2;
    int L[n][m];
    int R[n][m];
    L[0][0] = R[0][0] = a[0][0];
    for(int i = 1; i < n; i++) {
        L[i][0] = R[i][0] = L[i - 1][0] + a[i][0];
    }
    for(int j = 1; j < m; j++) {
        L[0][j] = R[0][j] = L[0][j - 1] + a[0][j];
    }
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            assert(max(L[i - 1][j], L[i][j - 1]) <= min(R[i - 1][j], R[i][j - 1]) + 1); 
            L[i][j] = min(L[i - 1][j], L[i][j - 1]) + a[i][j];
            R[i][j] = max(R[i - 1][j], R[i][j - 1]) + a[i][j];
        }
    }
    if(L[n - 1][m - 1] <= target && target <= R[n - 1][m - 1]) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}