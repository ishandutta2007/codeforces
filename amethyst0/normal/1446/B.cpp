#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <cassert>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <random>
#include <bitset>
#include <limits.h>
#include <fstream>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
#define uint unsigned int
#define mp make_pair

const int maxn = 5010;

int dp[2][maxn];

int main() {
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;

    int it = 0;
    int ans = 0;

    for (int i = n - 1; i >= 0; i--) {
        for (int j = m; j >= 0; j--) {
            if (j == m) {
                dp[it ^ 1][j] = 0;
                continue;
            }
            dp[it ^ 1][j] = dp[it ^ 1][j + 1] - 1;
            dp[it ^ 1][j] = max(dp[it ^ 1][j], dp[it][j] - 1);
            if (s[i] == t[j]) {
                dp[it ^ 1][j] = max(dp[it ^ 1][j], dp[it][j + 1] + 2);
            }
            dp[it ^ 1][j] = max(dp[it ^ 1][j], 0);
            ans = max(ans, dp[it ^ 1][j]);
        }

        it ^= 1;
    }

    cout << ans << '\n';
}