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
mt19937 rr(random_device{}());

const double EPS = 1e-9;
const int MAXN = 200;

int dp[MAXN][MAXN];
int full[MAXN][MAXN];
int pal[MAXN][MAXN][MAXN];

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> cost(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> cost[i];
    string s;
    cin >> s;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == j)
                continue;
            dp[i][j] = -1;
            full[i][j] = -1;
            for (int k = 0; k <= n; ++k)
                pal[i][j][k] = -1;
        }
    }

    for (int i = n - 1; i >= 0; --i) {
        for (int j = i + 1; j <= n; ++j) {

            for (int k = i; k < j; ++k) {
                if (full[i][k] != -1 && full[k + 1][j] != -1)
                    pal[i][j][1] = max(pal[i][j][1], full[i][k] + full[k + 1][j]);
            }

            for (int k = 2; k <= j - i; ++k) {

                for (int l = i + 1; l < j; ++l) {
                    if (full[i][l] == -1 || pal[l][j][k] == -1)
                        continue;
                    pal[i][j][k] = max(pal[i][j][k], full[i][l] + pal[l][j][k]);
                }

                for (int l = i; l < j - 1; ++l) {
                    if (full[l + 1][j] == -1 || pal[i][l + 1][k] == -1)
                        continue;
                    pal[i][j][k] = max(pal[i][j][k], pal[i][l + 1][k] + full[l + 1][j]);
                }

                // for (int l = i + 1; l < j; ++l) {
                //     if (s[i] != s[l] || pal[i + 1][l][k - 2] == -1 || full[l + 1][j] == -1)
                //         continue;
                //     pal[i][j][k] = max(pal[i][j][k], pal[i + 1][l][k - 2] + full[l + 1][j]);
                // }

                // for (int l = i; l < j - 1; ++l) {
                //     if (s[l] != s[j - 1] || pal[l][j - 1][k - 2] == -1 || full[i][l] == -1)
                //         continue;
                //     pal[i][j][k] = max(pal[i][j][k], full[i][l] + pal[l + 1][j - 1][k - 2]);
                // }

                if (s[i] == s[j - 1]) {
                    if (pal[i + 1][j - 1][k - 2] != -1)
                        pal[i][j][k] = max(pal[i][j][k], pal[i + 1][j - 1][k - 2]);
                }
            }

            for (int k = 1; k <= j - i; ++k) {
                if (cost[k] != -1 && pal[i][j][k] != -1)
                    full[i][j] = max(full[i][j], pal[i][j][k] + cost[k]);
            }   

            dp[i][j] = max(full[i][j], 0);
            for (int k = i; k < j; ++k)
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j]);

            pal[i][j][0] = full[i][j];
        }
    }

    // for (int i = 0; i <= n; ++i) {
    //     for (int j = 0; j <= n; ++j) {
    //         cout << full[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << dp[0][n] << endl;

    return 0;
}