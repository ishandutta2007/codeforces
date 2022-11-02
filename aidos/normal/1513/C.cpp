#include <bits/stdc++.h>

using namespace std;
string s;
int n;
int a[100100];
int dp[200200][10];
const int mod = (int)1e9 + 7;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for(int i = 0; i < 10; i++) {
        dp[0][i] = 1;
    }
    for(int j = 1; j < 2 * 100010; j++) {
        dp[j][9] = (dp[j-1][1] + dp[j-1][0]) % mod;
        for(int c = 0; c < 9; c++) {
            dp[j][c] = dp[j-1][c+1];
        }
    }
    for(int i = 1; i <= t; i++) {
        int x;
        cin >> s >> x;
        int ans = 0;
        for(char c: s) {
            ans = (ans + dp[x][c-'0']) % mod;
        }
        cout << ans << "\n";
    }
}