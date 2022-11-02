#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e3 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
const double pi = acos(-1);
int dp[maxn][maxn];

void solve() {
    string s, t;
    cin >> s >> t;
    int n = t.size();
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            dp[i][j] = i==0?j:inf;
        }
    }
    for(const char &c: s) {
        for(int i = n; i >= 0; i--) {
            for(int j=n; j >= 0; j--) {
                if(i < n && t[i] == c) {
                    dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
                }
                if(j < n && t[j] == c) {
                    dp[i][j+1] = min(dp[i][j+1], dp[i][j]);
                }
            }
        }
    }
    for(int i = 0; i <= n; i++) {
        if(dp[i][n] <= i) {
            cout << "YES\n";
            return;
        }
        if(dp[n][i] <= i) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";


}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}