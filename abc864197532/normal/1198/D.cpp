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
#define pli pair<lli,int> 
#define X first
#define Y second

int input[50][50], dp[50][50][50][50], pre[51][51];

int ask (int x1, int y1, int x2, int y2) {
    return pre[x2 + 1][y2 + 1] - pre[x1][y2 + 1] - pre[x2 + 1][y1] + pre[x1][y1];
}

int solve(int x1, int y1, int x2, int y2) {
    if (x1 > x2 or y1 > y2) return 0;
    if (dp[x1][y1][x2][y2] != -1) return dp[x1][y1][x2][y2];
    if (ask(x1, y1, x2, y2) == 0) return dp[x1][y1][x2][y2] = 0;
    dp[x1][y1][x2][y2] = max(x2 - x1 + 1, y2 - y1 + 1);
    // x
    for (int i = x1; i <= x2; ++i) {
        if (ask(i, y1, i, y2) == 0) {
            dp[x1][y1][x2][y2] = min(dp[x1][y1][x2][y2], solve(x1, y1, i - 1, y2) + solve(i + 1, y1, x2, y2));
        }
    }
    // y
    for (int i = y1; i <= y2; ++i) {
        if (ask(x1, i, x2, i) == 0) {
            dp[x1][y1][x2][y2] = min(dp[x1][y1][x2][y2], solve(x1, y1, x2, i - 1) + solve(x1, i + 1, x2, y2));
        }
    }
    return dp[x1][y1][x2][y2];
}


int main () {
    int n;
    cin >> n;
    char c;
    fop (i,0,n) {
        fop (j,0,n) {
            cin >> c;
            if (c == '#') input[i][j] = 1;
            else input[i][j] = 0;
        }
    }
    fop (i,0,n) {
        fop (j,0,n) {
            fop (ii,0,n) {
                fop (jj,0,n) {
                    dp[i][j][ii][jj] = -1;
                }
            }
        }
    }
    fop (i,0,51) pre[i][0] = pre[0][i] = 0;
    fop (i,0,n) {
        int now = 0;
        fop (j,0,n) {
            now += input[i][j];
            pre[i+1][j+1] = pre[i][j+1] + now;
        }
    }
    cout << solve(0, 0, n - 1, n - 1) << endl;
}