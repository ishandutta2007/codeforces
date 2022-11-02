#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 3e6 + 123;
const int mod = 1e9 + 9;
int n, m;
short prv[402][402][402];
int last[402 * 402];
int a[402][402];
void solve() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            prv[i][i][j] = last[a[i][j]] + 1;
            last[a[i][j]] = j;
        }
        for(int j = 1; j <= m; j++) {
            last[a[i][j]] = 0;
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            for(int k = 1; k <= m; k++) {
                prv[i][j][k] = max(prv[i][j][k], (short)(last[a[i][k]] + 1));
                last[a[i][k]] = k;
                prv[i][j][k] = max(prv[i][j][k], (short)(last[a[j][k]] + 1));
                last[a[j][k]] = k;
            }
            for(int k = 1; k <= m; k++) {
                last[a[i][k]] = 0;
                last[a[j][k]] = 0;
            }

        }
    }
    int ans = 0;
    for(int i = n; i >= 1; i--) {
        for(int j = i; j <= n; j++) {
            for(int k = 1; k <= m; k++) {
                prv[i][j][k] = max(prv[i+1][j][k], prv[i][j][k]);
                prv[i][j][k] = max(prv[i][j-1][k], prv[i][j][k]);
                prv[i][j][k] = max(prv[i][j][k-1], prv[i][j][k]);
                ans = max(ans, (j - i + 1) * (k - prv[i][j][k] + 1));
            }
        }
    }
    cout << ans << "\n";
}
int main() {
    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }

    return 0;
}