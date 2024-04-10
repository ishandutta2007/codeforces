#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)5e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n, q, c;
int dp[111][111][12];
void solve() {
    cin >> n >> q >> c;
    for(int i = 0; i < n; i++) {
        int x, y, s;
        cin >> x >> y >> s;
        for(int t = 0; t <= c; t++) {
            dp[x][y][t] += s;
            if(s + 1 <= c) s++;
            else s = 0;
        }
    }
    for(int t = 0; t <= c; t++) {
        for(int i = 1; i <= 100; i++) {
            for(int j = 1; j <= 100; j++) {
                dp[i][j][t] += dp[i-1][j][t] + dp[i][j-1][t] - dp[i-1][j-1][t];
            }
        }
    }
    for(int i = 0; i < q; i++){
        int t, x1, y1, x2, y2;
        cin >> t >> x1 >> y1 >> x2 >> y2;
        t %= c + 1;
        cout << dp[x2][y2][t] - dp[x1-1][y2][t] - dp[x2][y1-1][t] + dp[x1-1][y1-1][t] << "\n";
    }

}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}