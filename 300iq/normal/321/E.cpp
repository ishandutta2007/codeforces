#include <iostream>
#include <stdio.h>
#include <vector>
#include <climits>
#include <cstring>
#include <algorithm>
#include <set>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/detail/standard_policies.hpp>
#define mp make_pair
#define pb push_back
#define fc first
#define sc second
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double
#define min(a, b) (a < b ? a : b)

using namespace std;

const int MAXN = 4007;
const int MAXK = 807;
int dp[MAXK][MAXN]; //dp[k][n]
int opt[MAXK][MAXN];
int u[MAXN][MAXN];

int cost(int i, int j) {
    return u[j][j] - u[i - 1][j] - u[j][i - 1] + u[i - 1][i - 1];
}

void rec(int i, int jl, int jr, int ql, int qr) {
    if (jl > jr) {
        return;
    }
    if (jl == jr) {
        int m = (jl + jr) >> 1;
        dp[i][m] = INT_MAX >> 1;
        for (int q = ql; q <= min(m - 1, qr); q++) {
            if (dp[i - 1][q] + cost(q + 1, m) < dp[i][m]) {
                dp[i][m] = dp[i - 1][q] + cost(q + 1, m);
                opt[i][m] = q;
            }
        }
    } else {
        int m = (jl + jr) >> 1;
        dp[i][m] = INT_MAX >> 1;
        for (int q = ql; q <= min(m - 1, qr); q++) {
            if (dp[i - 1][q] + cost(q + 1, m) < dp[i][m]) {
                dp[i][m] = dp[i - 1][q] + cost(q + 1, m);
                opt[i][m] = q;
            }
        }
        rec(i, jl, m - 1, ql, opt[i][m]);
        rec(i, m + 1, jr, opt[i][m], qr);
    }
}

inline int readInt() {
    char c = getchar();
    while (c > '9' || c < '0') {
        c = getchar();
    }
    int next = 0;
    while (c >= '0' && c <= '9') {
        next = next * 10 + (c - '0');
        c = getchar();
    }
    return next;
}

int main() {
    #ifdef __linux__
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    #ifndef __linux__
        //freopen("towers.in", "r", stdin);
        //freopen("towers.out", "w", stdout);
    #endif
    int n, k;
    n = readInt(), k = readInt();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            u[i][j] = readInt();
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            u[i][j] += u[i - 1][j] + u[i][j - 1] - u[i - 1][j - 1];
        }
    }
    for (int i = 0; i < n; i++) {
        dp[1][i] = cost(0, i);
    }
    for (int i = 2; i <= k; i++) {
        rec(i, 0, n - 1, 0, n - 1);
    }
    printf("%d\n", dp[k][n - 1] >> 1);
}