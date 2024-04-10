#include<bits/stdc++.h>

using namespace std;

int const maxn = 105;
int dp[maxn][maxn][2][2];

int get(int cnt0, int cnt1, int type, int score) {
    if (cnt0 + cnt1 == 0) {
        return (score == 0);
    }
    if (dp[cnt0][cnt1][type][score] != -1) return dp[cnt0][cnt1][type][score];
    if (type == 0) {
        if (cnt0 && get(cnt0 - 1, cnt1, (type^1), score)) {
            dp[cnt0][cnt1][type][score] = 1;
            return 1;
        }
        if (cnt1 && get(cnt0, cnt1 - 1, (type^1), (score^1))) {
            dp[cnt0][cnt1][type][score] = 1;
            return 1;
        }
        dp[cnt0][cnt1][type][score] = 0;
        return 0;
    } else {
        if (cnt0 && !get(cnt0 - 1, cnt1, (type^1), score)) {
            dp[cnt0][cnt1][type][score] = 0;
            return 0;
        }
        if (cnt1 && !get(cnt0, cnt1 - 1, (type^1), score)) {
            dp[cnt0][cnt1][type][score] = 0;
            return 0;
        }
        dp[cnt0][cnt1][type][score] = 1;
        return 1;
    }
}

void solve() {
    int n, cnt0 = 0, cnt1 = 0, x;
    cin >> n;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            for (int z = 0; z <= 1; z++) {
                for (int k = 0; k <= 1; k++) dp[i][j][z][k] = -1;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cin >> x;
        if (x % 2 == 0) cnt0++;
        else cnt1++;
    }
    if (get(cnt0, cnt1, 0, 0)) cout << "Alice" << '\n';
    else cout << "Bob" << '\n';
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}