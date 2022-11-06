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

const int V = 100100;
const int N = 31;
const int M = 20;
int dp[N + 1][N + 1][2][2];
int dfs(int L, int R, int x, int y) {
    if (dp[L][R][x][y] != -1) return dp[L][R][x][y];
    if (L + R == 0) {
        return x;
    }
    dp[L][R][x][y] = 0;
    if (L > 0 && !dfs(L - 1, R, y, x ^ 1)) dp[L][R][x][y] = 1;
    if (R > 0 && !dfs(L, R - 1, y, x)) dp[L][R][x][y] = 1;
    return dp[L][R][x][y];
}
void init() {
    memset(dp, -1, sizeof(dp));
    for (int L = 1; L < M; L += 2)
        for (int R = 0; R < M; ++R)
            printf("%d %d %d\n", L, R, dfs(L, R, 0, 0));
}
int _, n, a[V];

int main() {
    //init();
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        int s = 0;
        for (int i = 0; i < n; ++i) s ^= a[i];
        int bit = -1;
        for (int i = 0; i < N; ++i) if (s & (1 << i)) bit = i;
        if (bit == -1) {puts("DRAW"); continue;}
        int cnt = 0;
        for (int i = 0; i < n; ++i) if (a[i] & (1 << bit)) ++cnt;
        //printf("B %d\n", bit);
        if (cnt % 4 == 1) {
            puts("WIN");
        } else {
            if (n % 2 == cnt % 2) puts("LOSE");
            else puts("WIN");
        }
    }
    return 0;
}

/*
3
3
1 2 2
3
2 2 3
5
0 0 0 2 2

4
5
4 1 5 1 3
4
1 0 1 6
1
0
2
5 4
*/