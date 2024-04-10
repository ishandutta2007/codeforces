#include <bits/stdc++.h>

using namespace std;

int dp[200000]['z' + 1];
char prev_c[200000]['z' + 1];
char cur[200000]['z' + 1];
char mini[200000];

int main() {
    string s;
    cin >> s;
    for (char c = 'a'; c <= 'z'; c++) {
        if (c != s[0]) {
            dp[0][c] = 1;
        }
    }
    mini[(int) s.size() - 1] = s[(int) s.size() - 1];
    for (int i = 1; i < (int) s.size(); i++) {
        for (char x = 'a'; x <= 'z'; x++) {
            dp[i][x] = INT_MAX / 2;
            for (char c = 'a'; c <= 'z'; c++) {
                if (c != x) {
                    if (dp[i - 1][c] + (s[i] != x) < dp[i][x]) {
                        dp[i][x] = dp[i - 1][c] + (s[i] != x);
                        prev_c[i][x] = c;
                        cur[i][c] = x;
                    }
                }
            }
            if (dp[i][x] <= dp[i][mini[i]]) {
                mini[i] = x;
            }
        }
    }
    int cr = (int) s.size() - 1;
    char cc = mini[cr];
    string ans = "";
    while (cr >= 0) {
        ans += cc;
        cc = prev_c[cr][cc];
        cr--;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}