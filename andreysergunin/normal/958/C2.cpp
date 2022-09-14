#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <vector>
#include <cstring>
#include <random>

#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

const int maxn = (int)2e4 + 10, inf = (int)1e9;
int v[maxn];

int dp[2][110][110];

int main() {
    int n, k, p;

    cin >> n >> k >> p;

    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    for (int i = 0; i <= k; i++) {
        for (int j = 0; j < p; j++) {
            dp[0][i][j] = -inf;
        }
    }

    dp[0][0][0] = 0;

    int it = 1;

    for (int ps = n - 1; ps >= 0; ps--) {
        for (int i = 0; i <= k; i++) {
            for (int j = 0; j < p; j++) {
                dp[it][i][j] = dp[it ^ 1][i][(j + v[ps]) % p];

                if (i != 0) {
                    dp[it][i][j] = max(dp[it][i][j], dp[it ^ 1][i - 1][0] + (j + v[ps]) % p);
                }
            }
        }

        it ^= 1;
    }

    cout << dp[it ^ 1][k][0] << endl;
}