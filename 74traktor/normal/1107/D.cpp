#include <bits/stdc++.h>

using namespace std;

char g[5210][5210];
int dp[5210][5210];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    map < char, string > T;
    T['0'] = "0000";
    T['1'] = "0001";
    T['2'] = "0010";
    T['3'] = "0011";
    T['4'] = "0100";
    T['5'] = "0101";
    T['6'] = "0110";
    T['7'] = "0111";
    T['8'] = "1000";
    T['9'] = "1001";
    T['A'] = "1010";
    T['B'] = "1011";
    T['C'] = "1100";
    T['D'] = "1101";
    T['E'] = "1110";
    T['F'] = "1111";
    for (int i = 1; i <= n; ++i){
        string s;
        cin >> s;
        for (int j = 1; j <= n; j += 4){
            string p1 = T[s[j / 4]];
            for (int p = j; p <= j + 3; ++p) g[i][p] = p1[p - j];
        }
    }
    for (int i = 1; i <= n; ++i){
        dp[i][n] = 1;
        for (int j = n - 1; j >= 1; --j){
            if (g[i][j] == g[i][j + 1]) dp[i][j] = dp[i][j + 1] + 1;
            else dp[i][j] = 1;
        }
    }
    int ans = 1;
    for (int len = 2; len <= n; ++len){
        if (n % len == 0){
            bool f = true;
            for (int i = 1; i <= n; i += len){
                if (!f) break;
                for (int j = 1; j <= n; j += len){
                    if (!f) break;
                    for (int p1 = i; p1 < i + len; p1++){
                        if (dp[p1][j] < len) f = false;
                        if (g[p1][j] != g[i][j]) f = false;
                        if (!f) break;
                    }
                }
            }
            if (f) ans = len;
        }
    }
    cout << ans << '\n';
    return 0;
}