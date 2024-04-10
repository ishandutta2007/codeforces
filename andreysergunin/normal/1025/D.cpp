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
#include <bitset>
#include <functional>
#include <tuple>
#include <complex>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef unsigned int uint;

mt19937 rnd(random_device{}());

const int MAXN = 777;
int g[MAXN][MAXN];

int gcd(int a, int b) {
    return (b == 0 ? a : gcd(b, a % b));
}

int dp[MAXN][MAXN][2];

bool solve(int l, int r, int t) {
    if (dp[l][r][t]) {
        return dp[l][r][t] - 1;
    }

    if (l == r) {
        dp[l][r][t] = 2;
        return true;
    }

    if (t == 0) {
        for (int i = l + 1; i <= r; ++i) {
            if (g[l][i] && solve(l + 1, i, 1) && solve(i, r, 0)) {
                dp[l][r][t] = 2;
                return true;
            }
        }
        dp[l][r][t] = 1;
        return false;
    } else {
        for (int i = l; i <= r - 1; ++i) {
            if (g[i][r] && solve(l, i, 1) && solve(i, r - 1, 0)) {
                dp[l][r][t] = 2;
                return true;
            }
        }
        dp[l][r][t] = 1;
        return false;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            g[i][j] = (gcd(a[i], a[j]) > 1 ? 1 : 0);
        }
    }

    for (int i = 0; i < n; ++i) {
        if (solve(0, i, 1) && solve(i, n - 1, 0)) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;

}