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
#include <chrono>
#include <climits>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned int uint;
typedef unsigned long long ull;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
// default_random_engine generator;
// mt19937 rnd(1);

const int MAXN = 52;

int dp[MAXN][MAXN][MAXN][MAXN];
int sum[MAXN][MAXN];

int get(int i, int j, int u, int v) {
    return sum[j][v] + sum[i][u] - sum[i][v] - sum[j][u];
}

int solve(int i, int j, int u, int v) {
    if (i == j || u == v) {
        return 0;
    }
    if (dp[i][j][u][v] != -1) { 
        return dp[i][j][u][v];
    }
    dp[i][j][u][v] = max(j - i, v - u);

    for (int k = i; k < j; ++k) {
        if (get(k, k + 1, u, v) == 0) {
            dp[i][j][u][v] = min(dp[i][j][u][v], solve(i, k, u, v) + solve(k + 1, j, u, v));
        }
    }

    for (int w = u; w < v; ++w) {
        if (get(i, j, w, w + 1) == 0) {
            dp[i][j][u][v] = min(dp[i][j][u][v], solve(i, j, u, w) + solve(i, j, w + 1, v));
        }
    }
    return dp[i][j][u][v];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  

    int n;
    cin >> n;
    
    vector<string> s(n);

    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            sum[i + 1][j + 1] = sum[i][j + 1] + sum[i + 1][j] - sum[i][j] + (s[i][j] == '#');
        }
    }

    memset(dp, -1, sizeof(dp));

    cout << solve(0, n, 0, n) << endl;
}