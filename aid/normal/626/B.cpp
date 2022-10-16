#include <iostream>
#include <string>

using namespace std;

const int MAXN = 205;
char dp[MAXN][MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    int r = 0, g = 0;
    for(int i = 0; i < n; i++)
        if(s[i] == 'R')
            r++;
        else if(s[i] == 'G')
            g++;
    dp[n][r][g] = true;
    for(int i = n; i > 0; i--)
        for(int j = 0; j <= i; j++)
            for(int k = 0; k <= i; k++) {
                if(!dp[i][j][k])
                    continue;
                int l = i - j - k;
                if(j > 0 && k > 0)
                    dp[i - 1][j - 1][k - 1] = true;
                if(j > 0 && l > 0)
                    dp[i - 1][j - 1][k + 1] = true;
                if(k > 0 && l > 0)
                    dp[i - 1][j + 1][k - 1] = true;
                if(j > 1)
                    dp[i - 1][j - 1][k] = true;
                if(k > 1)
                    dp[i - 1][j][k - 1] = true;
                if(l > 1)
                    dp[i - 1][j][k] = true;
            }
    if(dp[1][0][0])
        cout << 'B';
    if(dp[1][0][1])
        cout << 'G';
    if(dp[1][1][0])
        cout << 'R';
    cout << '\n';
    return 0;
}