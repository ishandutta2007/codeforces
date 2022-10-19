#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pii pair<int, int>

const int maxn = 500;

int ans[maxn][maxn];
int val[maxn][maxn];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> val[i][i];
        ans[i][i] = val[i][i];
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n - k; ++i) {
            if (val[k + i][i] == 1) {
                break;
            }
            val[k + 1 + i][i] = val[k + i][i] - 1;
            ans[k + 1 + i][i] = ans[k + i][i];
        }
        for (int i = n - k - 1; i >= 0; --i) {
            if (val[k + i][i] == 1) {
                break;
            }
            val[k + i][i - 1] = val[k + i][i] - 1;
            ans[k + i][i - 1] = ans[k + i][i];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}