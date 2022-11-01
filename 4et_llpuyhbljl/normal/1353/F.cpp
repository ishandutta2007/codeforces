#include<iostream>
#include<vector>
#include<stack>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<tuple>
#include<queue>
using namespace std;
int gcd(int i, int j) {
    if (j == 0)return i;
    else return gcd(j, i % j);
}
inline int getint() {
    int val = 0;
    char c;
    while ((c = getchar()) && !(c >= '0' && c <= '9'));
    do {
        val = (val * 10) + c - '0';
    } while ((c = getchar()) && (c >= '0' && c <= '9'));
    return val;
}
const long long INF = -1000;
const int Y = 100;
//const int m = 997;
long long mt[101][101];
long long dp[101][101];
long long ct[101][101];
int n, m;
long long solve(long long val) {
    for (long long i = 0; i < n; ++i) {
        for (long long j = 0; j < m; ++j) {
            if (mt[i][j] - i - j < val) {
                ct[i][j] = INF;
            }
            else {
                ct[i][j] = mt[i][j] - i - j - val;
            }
            dp[i][j] = INF;
        }
    }
    dp[0][0] = ct[0][0];
    if (ct[0][0] == INF)return INF;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (ct[i][j] == INF)continue;
            if (i == 0) {
                if (j == 0) {
                    continue;
                }
                else {
                    if (dp[i][j - 1] == INF) {
                        continue;
                    }
                    else {
                        dp[i][j] = ct[i][j] + dp[i][j - 1];
                    }
                }
            }
            else {
                if (j == 0) {
                    if (dp[i - 1][j] == INF) {
                        continue;
                    }
                    else {
                        dp[i][j] = ct[i][j] + dp[i - 1][j];
                    }
                }
                else {
                    if (dp[i - 1][j] != INF) {
                        dp[i][j] = dp[i - 1][j] + ct[i][j];
                    }
                    if (dp[i][j - 1] != INF) {
                        if (dp[i][j] != INF) {
                            dp[i][j] = min(dp[i][j], dp[i][j - 1] + ct[i][j]);
                        }
                        else {
                            dp[i][j] = dp[i][j - 1] + ct[i][j];
                        }
                    }
                }
            }
        }
    }

    return dp[n - 1][m - 1];
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    vector<long long>ans;
    while (t--) {
        long long res = INF;
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> mt[i][j];
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (res == INF)res = solve(mt[i][j] - i - j);
                else {
                    long long tmp = solve(mt[i][j] - i - j);
                    if (tmp != INF) res = min(res, tmp);
                }
            }
        }
        ans.push_back(res);
    }
    for (auto x : ans)cout << x << endl;
    return 0;
}