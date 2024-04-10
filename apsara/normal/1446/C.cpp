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
const int V = 200100;
const int M = 30;
struct Node{
    int ne[2];
    int ct;
}tr[V * 32], VD;
int tn, root;

void init() {
    VD.ct = 0;
    VD.ne[0] = VD.ne[1] = -1;
    root = 0;
    tr[0] = VD;
    tn = 1;
}

void add(int x) {
    int p = root;
    for (int i = M; i >= 0; --i) {
        int y = 0;
        if (x & (1 << i)) y = 1;
        if (tr[p].ne[y] == -1) {
            tr[p].ne[y] = tn;
            tr[tn++] = VD;
        }
        p = tr[p].ne[y];
    }
    tr[p].ct = 1;
}

int dp[V * 32][2];

void dfs(int u) {
    dp[u][0] = dp[u][1] = 0;
    if (tr[u].ct == 1) dp[u][0] = dp[u][1] = 1;
    for (int i = 0; i < 2; ++i) {
        int v = tr[u].ne[i];
        if (v == -1) continue;
        dfs(v);
        dp[u][1] = max(dp[u][1], max(dp[u][0] + dp[v][1], dp[u][1] + dp[v][0]));
        dp[u][0] = min(1, dp[u][0] + dp[v][0]);
    }
}
int n, a[V];

int main() {
    while (~scanf("%d", &n)) {
        init();
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        for (int i = 0; i < n; ++i) add(a[i]);
        dfs(root);
        printf("%d\n", n - max(dp[root][0], dp[root][1]));
    }
    return 0;
}

/*
5
0 1 5 2 6

7
6 9 8 7 3 5 2
*/