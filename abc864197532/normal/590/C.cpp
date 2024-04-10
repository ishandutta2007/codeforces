#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define X first
#define Y second

int main () {
    int n, m;
    cin >> n >> m;
    string s[n];
    int d[3][n][m];
    bool vi[3][n][m];
    queue <pair <pii, int>> q[3];
    fop (i,0,n) {
        cin >> s[i];
    }
    
    fop (i,0,n) {
        fop (j,0,m) {
            if (s[i][j] == '#') {
                fop (k,0,3) {
                    vi[k][i][j] = true;
                    d[k][i][j] = 1 << 20;
                }
            } else if (s[i][j] == '.') {
                fop (k,0,3) {
                    vi[k][i][j] = false;
                    d[k][i][j] = 1 << 20;
                }
            } else {
                fop (k,0,3) {
                    if (s[i][j] - '1' == k) {
                        q[k].push({{i, j}, 0});
                        d[k][i][j] = 0;
                        vi[k][i][j] = true;
                    } else {
                        d[k][i][j] = 1 << 20;
                        vi[k][i][j] = false;
                    }
                }
            }
        }
    }
    
    int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
    int x, y, a, now = 0, ans2 = 0;
    fop (k,0,3) {
        while (q[k].size()) {
            tie(x, y) = q[k].front().X;
            a = q[k].front().Y;
            q[k].pop();
            fop (i,0,4) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 and nx < n and ny >= 0 and ny < m) {
                    if (!vi[k][nx][ny]) {
                        q[k].push({{nx, ny}, a + 1});
                        d[k][nx][ny] = a + 1;
                        vi[k][nx][ny] = true;
                    }
                }
            }
        }
    }
    
    int dp[3][3];
    fop (i,0,3) {
        fop (j,0,3) {
            dp[i][j] = 1 << 20;
        }
    }
    
    fop (i,0,n) {
        fop (j,0,m) {
            if (s[i][j] >= '1' and s[i][j] <= '3') {
                fop (k,0,3) {
                    if (k == s[i][j] - '1') continue;
                    dp[k][s[i][j] - '1'] = min(dp[k][s[i][j] - '1'], d[k][i][j]);
                    dp[s[i][j] - '1'][k] = min(dp[s[i][j] - '1'][k], d[k][i][j]);
                }
            }
        }
    }
    
    int ans = 1 << 20;
    
    if (dp[0][1] != 1 << 20 and dp[0][2] != 1 << 20) ans = min(ans, dp[0][1] + dp[0][2] - 2);
    if (dp[1][0] != 1 << 20 and dp[1][2] != 1 << 20) ans = min(ans, dp[1][0] + dp[1][2] - 2);
    if (dp[2][0] != 1 << 20 and dp[2][1] != 1 << 20) ans = min(ans, dp[2][0] + dp[2][1] - 2);
    
    fop (i,0,n) {
        fop (j,0,m) {
            if (s[i][j] != '#' and d[0][i][j] != (1 << 20) and d[1][i][j] != (1 << 20) and d[2][i][j] != (1 << 20)) {
                ans = min(ans, d[0][i][j] + d[1][i][j] + d[2][i][j] - 2);
            }
        }
    }
    if (ans == (1 << 20)) ans = -1;
    cout << ans << endl;
}