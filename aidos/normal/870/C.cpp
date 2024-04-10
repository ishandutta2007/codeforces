#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = 998244353;
const int inf = (1<<30) - 1;
const double pi = acos(-1);
const double eps = 1e-15;
int n, k;

int dp[maxn];
void solve() {
    cin >> n;
    if(n <= 150) {
        if(dp[n] < 0) {
            cout << -1 << "\n";
        }else {
            cout << dp[n] << "\n";
        }
        return;
    }
    int x = (n-100)/4;
    cout << dp[n - x * 4] + x << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //srand(time(0));
    for(int i = 1; i < 202; i++) {
        dp[i] = -inf;
        for(int j = 4; j <= i; j++) {
            int ok = 0;
            for(int k = 2; k < j; k++) {
                if(j % k == 0) ok = 1;
            }
            if(ok) {
                dp[i] = max(dp[i-j] + 1, dp[i]);
            }
        }
    }
    int t = 1;
    //scanf("%d", &t);
    cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}