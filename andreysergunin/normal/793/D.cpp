#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <cassert>
#include <unordered_map>
#include <fstream>
#include <random>
#include <cstring>
#include <complex>
#include <bitset>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
mt19937 rr(random_device{}());

const int INF = 1e9;
const int MAXN = 100;

int dp[MAXN][MAXN][MAXN][2];

int main() {
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
        
    int n, k;
    cin >> n >> k;
    vector<vector<int>> c(n, vector<int>(n, INF));
    
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, cost;
        cin >> u >> v >> cost;
        --u; --v;
        c[u][v] = min(c[u][v], cost);
    }

    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < n; ++j)
    //         cout << c[i][j] << " ";
    //     cout << endl;
    // }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k <= n; ++k) {
                for (int e = 0; e < 2; ++e)
                    dp[i][j][k][e] = INF;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            dp[i][j][1][0] = 0;
            dp[i][j][1][1] = 0;
        }
    } 


    for (int len = 1; len < n; ++len) {
        for (int l = 0; l < n - len; ++l) {
            int r = l + len;
            for (int d = 2; d <= r - l + 1; ++d) {
                for (int to = l + 1; to <= r; ++to) {
                    dp[l][r][d][0] = min(dp[l][r][d][0], dp[l + 1][to][d - 1][1] + c[l][to]);
                    dp[l][r][d][0] = min(dp[l][r][d][0], dp[to][r][d - 1][0] + c[l][to]);
                }

                for (int to = l; to <= r - 1; ++to) {
                    dp[l][r][d][1] = min(dp[l][r][d][1], dp[to][r - 1][d - 1][0] + c[r][to]);
                    dp[l][r][d][1] = min(dp[l][r][d][1], dp[l][to][d - 1][1] + c[r][to]);
                }
            }
        }
    }
    
    int ans = INF;

    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            ans = min(ans, dp[i][j][k][0]);
            ans = min(ans, dp[i][j][k][1]);
        }
    }

    cout << (ans == INF ? -1 : ans) << endl;

    return 0;
}