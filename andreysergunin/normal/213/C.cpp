#include <iostream>
#include <stdio.h>
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
#define pb push_back
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

const int MAXN = 333;
const int INF = 1e9;

int n;
int a[MAXN][MAXN];
int dp[MAXN][MAXN][MAXN];
int diag[2][MAXN][MAXN];

void solve(int type) {
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i <= k; ++i) {
            for (int j = 0; j <= k; ++j) {
                dp[k][i][j] = -INF;
            }
        }
    }
    dp[0][0][0] = 0;

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i <= k; ++i) {
            for (int j = 0; j <= k; ++j) {
                dp[k][i][j] += (i == j ? a[i][k - i] : a[i][k - i] + a[j][k - j]); 
                if (k < n - 1) {
                    dp[k + 1][i][j] = max(dp[k + 1][i][j], dp[k][i][j]);
                    dp[k + 1][i + 1][j] = max(dp[k + 1][i + 1][j], dp[k][i][j]);
                    dp[k + 1][i][j + 1] = max(dp[k + 1][i][j + 1], dp[k][i][j]);
                    dp[k + 1][i + 1][j + 1] = max(dp[k + 1][i + 1][j + 1], dp[k][i][j]);
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            diag[type][i][j] = dp[n - 1][i][j];
        }
    }
}

int main() {
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);    

    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    solve(0);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; i + j < n; ++j) {
            swap(a[i][j], a[n - j - 1][n - i - 1]);
        }
    }

    solve(1);


    int res = -INF;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int cur = diag[0][i][j] + diag[1][i][j] - (i == j ? a[i][n - 1 - i] : a[i][n - 1 - i] + a[j][n - 1 - j]); 
            res = max(res, cur);
        }
    }
    cout << res << endl;

}