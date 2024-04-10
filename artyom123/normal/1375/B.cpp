#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long

const int INF = 2e9 + 1;
const ll INFLL = 1e18 + 1;
const int mod = 1e9 + 7;

int n, m;

int nei(int i, int j) {
    if (i == 0 && j == 0) return 2;
    if (i == n - 1 && j == 0) return 2;
    if (i == 0 && j == m - 1) return 2;
    if (i == n - 1 && j == m - 1) return 2;
    if (i == 0) return 3;
    if (j == 0) return 3;
    if (i == n - 1) return 3;
    if (j == m - 1) return 3;
    return 4;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
        bool f = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] > nei(i, j)) f = false;
                else a[i][j] = nei(i, j);
            }
        }
        if (!f) cout << "NO\n";
        else {
            cout << "YES\n";
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    cout << a[i][j] << " ";
                }
                cout << "\n";
            }
        }
    }
    return 0;
}