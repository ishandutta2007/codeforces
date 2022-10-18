#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

const int maxn = 5000;

int dp[maxn][maxn];
int ans[maxn][maxn];

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    for(int i = 0; i < n; i++) {
        dp[i][i] = ans[i][i] = a[i];
    }
    for(int j = 1; j < n; j++) {
        for(int i = 0; i + j < n; i++) {
            dp[i][i + j] = dp[i][i + j - 1] ^ dp[i + 1][i + j];
            ans[i][i + j] = max({dp[i][i + j], ans[i][i + j - 1], ans[i + 1][i + j]});
        }
    }
    int q;
    cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        cout << ans[l][r] << endl;
    }
    return 0;
}