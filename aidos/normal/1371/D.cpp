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
        int n, k;
        cin >> n >> k;
        vector<string> ans(n, string(n, '0'));
        int x = (k/n);
        for(int it = 0; it < x; it++) {
            for(int j = 0; j < n; j++) {
                ans[j][(it+j) % n] = '1';
            }
        }
        for(int it=x*n; it < k; it++) {
            ans[(it-x*n)][(x+it) % n] = '1';
        }
        if(k % n == 0) cout << 0 << "\n";
        else cout << 2 << "\n";
        for(auto d: ans) cout << d << "\n";
    }
}