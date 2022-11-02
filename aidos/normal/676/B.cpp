#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)3e2 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
const double pi = acos(-1);
int n, t;
double dp[maxn][maxn];
void solve() {
    cin >> n >> t;
    dp[0][0] = t;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            if(dp[i][j] >= 1) {
                ans++;
                double r = max(0.0, dp[i][j] - 1);
                dp[i+1][j] += r * 0.5;
                dp[i+1][j+1] += r * 0.5;
            } else {

            }
        }
    }
    cout << ans << "\n";
}


int main() {
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