#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)5e5 + 10;
const int mod = (int) 1e9 + 7;
const int inf = (1<<30) - 1;
string s;
int n;
int d[5050][5050];
int dp[5050][5050];
int sum[5050][5050];
void solve() {
    cin >>n>> s;
    for(int i = 0; i <= n; i++) {
        d[n][i] = -1;
        d[i][n] = -1;
    }
    for(int i = n-1; i >= 0; i--) {
        for(int j = i + 1; j < n; j++) {
            if(s[i] != s[j]) {
                d[i][j] = i;
            } else {
                d[i][j] = d[i + 1][j + 1];
            }
        }
    }
    for(int i = n-1; i >= 0; i--) {
        if(s[i] == '0') continue;
        dp[i][n-1] = (dp[i][n-1] + 1) % mod;
        for(int j = i+1; j < n; j++) {
            int cur = j - i;
            if(j + cur <= n) {
                int pos = d[i][j];
                int len = pos-i;
                if(pos == -1 || len >= cur || s[i + len] > s[j + len]) {
                    dp[i][j-1] = sum[j][j + cur];
                } else {
                    dp[i][j-1] = sum[j][j + cur - 1];
                }
            } else {
                dp[i][j-1] = 0;
            }
        }
        for(int j = n-1; j >= i; j--) {
            sum[i][j] = (sum[i][j + 1] + dp[i][j]) % mod;
        }
    }
    cout << sum[0][0] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
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