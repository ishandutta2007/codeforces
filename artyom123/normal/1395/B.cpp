#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define pii pair<int, int>
#define ld long double

const int INF = 2e9 + 1;

void solve() {
    int n, m;
    cin >> n >> m;
    int x, y;
    cin >> x >> y;
    cout << x << " " << y << "\n";
    vector<vector<int>> usd(n + 1, vector<int>(m + 1));
    usd[x][y] = 1;
    for (int i = 1; i < n * m; i++) {
        bool f = false;
        for (int j = 1; j <= m; j++) {
            if (!usd[x][j]) {
                cout << x << " " << j << "\n";
                y = j;
                f = true;
                usd[x][y] = 1;
                break;
            }
        }
        if (f) continue;
        for (int i = 1; i <= n; i++) {
            if (!usd[i][y]) {
                cout << i << " " << y << "\n";
                x = i;
                usd[x][y] = 1;
                break;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}