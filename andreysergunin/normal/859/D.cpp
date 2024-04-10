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
#define sz(a) (int)(a).size()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

const int INF = 1e9;
const int MAXN = 70;

ld p[MAXN][MAXN];
ld dp[2 * MAXN][MAXN];
ld prob[2 * MAXN][MAXN];

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie();

    int k;
    cin >> k;
    int n = 1 << k;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> p[i][j];
            p[i][j] /= 100.;
        }
    }

    for (int i = 0; i < n; ++i) 
        prob[n + i][i] = 1;

    int st = -1;
    for (int i = n - 1; i >= 1; --i) {
        if (!(i & (i + 1))) {
            ++st;
        }
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                for (int l = 0; l < n; ++l) {
                    if (j != k && j != l) {
                        continue;
                    }
                    prob[i][j] += prob[2 * i][k] * prob[2 * i + 1][l] * p[j][k + l - j];
                    dp[i][j] = max(dp[i][j], dp[2 * i][k] + dp[2 * i + 1][l]);
                }
            }
            dp[i][j] += prob[i][j] * (1 << st);
        }
    }
    ld ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, dp[1][i]);
    }
    cout.precision(12);
    cout << fixed;
    cout << ans << endl;
            

}