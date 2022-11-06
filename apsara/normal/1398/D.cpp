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
#include <queue>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define PB push_back
#define fi first
#define se second
#define MP make_pair
const int P = 1000000007;
const int V = 210;
int dp[V][V][V];
int r[V], g[V], b[V];
int dfs(int x, int y, int z) {
    if (dp[x][y][z] != -1) return dp[x][y][z];
    if (x + y + z < 2) return 0;
    dp[x][y][z] = 0;
    if (x > 0 && y > 0) dp[x][y][z] = max(dp[x][y][z], dfs(x - 1, y - 1, z) + r[x] * g[y]);
    if (x > 0 && z > 0) dp[x][y][z] = max(dp[x][y][z], dfs(x - 1, y, z - 1) + r[x] * b[z]);
    if (y > 0 && z > 0) dp[x][y][z] = max(dp[x][y][z], dfs(x, y - 1, z - 1) + g[y] * b[z]);
    return dp[x][y][z];
}

int R, G, B;
int main() {
    while (~scanf("%d%d%d", &R, &G, &B)) {
        for (int i = 1; i <= R; ++i) scanf("%d", &r[i]);
        for (int i = 1; i <= G; ++i) scanf("%d", &g[i]);
        for (int i = 1; i <= B; ++i) scanf("%d", &b[i]);
        sort(r + 1, r + R + 1);
        sort(g + 1, g + G + 1);
        sort(b + 1, b + B + 1);
        memset(dp, -1, sizeof(dp));
        printf("%d\n", dfs(R, G, B));
    }
    return 0;
}

/*
1 1 1
3
5
4

2 1 3
9 5
1
2 8 5

10 1 1
11 7 20 15 19 14 2 4 13 14
8
11
*/