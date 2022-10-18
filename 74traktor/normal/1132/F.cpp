#include <bits/stdc++.h>

using namespace std;

int inf = 1e9;
int dp[505][505][27];
char check[505][505];
string s;

/*bool check(int l, int r, int z){
    for (int i = l; i <= r; ++i) if (s[i] != char('a' + z - 1)) return false;
    return true;
}*/

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string s1;
    s = "0";
    cin >> s1;
    s += s1;
    for (int i = 0; i <= 501; ++i) for (int j = 0; j <= 501; ++j) check[i][j] = '#';
    for (int l = 1; l <= n; ++l){
        int r = l;
        while (r <= n && s[r] == s[l]){
            check[l][r] = s[l];
            ++r;
        }
    }
    for (int i = 0; i <= 501; ++i) for (int j = 0; j <= 501; ++j) for (int z = 0; z <= 26; ++z) dp[i][j][z] = inf;
    for (int len = 1; len <= n; ++len){
        for (int l = 1; l <= n; ++l){
            int r = (l + len - 1);
            if (r > n) break;
            for (int z = 1; z <= 26; ++z){
                if (l == r){
                    if (s[l] == char('a' + z - 1)) dp[l][r][z] = 0;
                    else dp[l][r][z] = 1;
                }
                else{
                    if (check[l][r] == char('a' + z - 1)) dp[l][r][z] = 0;
                    else{
                        for (int M = l; M < r; ++M){
                            dp[l][r][z] = min(dp[l][r][z], dp[l][M][z] + dp[M + 1][r][z]);
                            dp[l][r][z] = min(dp[l][r][z], dp[l][M][z] + dp[M + 1][r][0]);
                            dp[l][r][z] = min(dp[l][r][z], dp[l][M][0] + dp[M + 1][r][z]);
                        }
                    }
                }
            }
            if (l != r) for (int z = 1; z <= 26; ++z) dp[l][r][0] = min(dp[l][r][0], dp[l][r][z] + 1);
        }
    }
    int ans = 1e9;
    for (int i = 1; i <= 26; ++i) ans = min(ans, dp[1][n][i] + 1);
    cout << min(ans, dp[1][n][0]) << '\n';
    return 0;
}