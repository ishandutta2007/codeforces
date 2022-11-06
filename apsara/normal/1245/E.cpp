#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
typedef long long LL;
const int P = 1000000007;

const int V = 110;
const int N = 10;
double dp[V];

int id(int x, int y) {
    if (x % 2 == 0) return x * N + y;
    else return x * N + 9 - y;
}

int a[N][N];
int px[V], py[V];

double dfs(int x) {
    if (dp[x] >= -0.5) return dp[x];
    double self = 0.0;
    double cost = 0.0;
    for (int i = 1; i <= 6; ++i) {
        if (x - i < 0) self += 1.0 / 6;
        else {
            int nx = px[x - i];
            int ny = py[x - i];
            if (a[nx][ny] == 0) cost += dfs(x - i) / 6.0;
            else {
                cost += min(dfs(x - i), dfs(id(nx - a[nx][ny], ny))) / 6.0;
            }
        }
    }
    dp[x] = (1.0 + cost) / (1.0 - self);
    return dp[x];
}

int main() {
    while (~scanf("%d", &a[0][0])) {
        for (int i = 1; i < N; ++i) scanf("%d", &a[0][i]);
        for (int i = 1; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                scanf("%d", &a[i][j]);
            }
        }
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                int k = id(i, j);
                px[k] = i;
                py[k] = j;
            }
        }
        for (int i = 0; i < N * N; ++i) dp[i] = -1.0;
        dp[0] = 0.0;
        printf("%.10f\n", dfs(N * N - 1));
    }
    return 0;
}

/*
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0

0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 3 0 0 0 4 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 4 0 0 0
0 0 3 0 0 0 0 0 0 0
0 0 4 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 9

0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 6 6 6 6 6 6 0 0 0
1 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0

*/