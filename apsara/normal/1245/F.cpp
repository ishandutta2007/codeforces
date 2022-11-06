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

const int V = 40;

LL dp[V][2][2][2][2];

int a[V], b[V];

LL dfs(int pos, int al, int bl, int au, int bu) {
    if (pos < 0) return 1;
    if (dp[pos][al][bl][au][bu] != -1) return dp[pos][al][bl][au][bu];
    dp[pos][al][bl][au][bu] = 0;
    int la = al ? a[pos] : 0;
    int lb = bl ? a[pos] : 0;
    int ua = au ? b[pos] : 1;
    int ub = bu ? b[pos] : 1;
    for (int x = la; x <= ua; ++x) {
        for (int y = lb; y <= ub; ++y) {
            if (x + y == 2) continue;
            dp[pos][al][bl][au][bu] += dfs(pos - 1,
                al & (x == a[pos]), bl & (y == a[pos]), au & (x == b[pos]), bu & (y == b[pos]));
        }
    }
    /*
    for (int x = 0; x <= ua; ++x) {
        for (int y = 0; y <= ub; ++y) {
            if (x + y == 2) continue;
            printf("Add %d %d %d %d %I64d\n", x, y, au & (x == a[pos]), bu & (y == b[pos]), dfs(pos - 1, au & (x == a[pos]), bu & (y == b[pos])));
        }
    }
    if (pos < 3) printf("DP %d %d %d %d %d %I64d\n", pos, au, bu, ua, ub, dp[pos][au][bu]);
    */
    return dp[pos][al][bl][au][bu];
}

LL Cal(int L, int R) {
    if (L < 0 || R < 0) return 0;
    for (int i = 30; i >= 0; --i) {
        if (L & (1 << i)) a[i] = 1;
        else a[i] = 0;
        if (R & (1 << i)) b[i] = 1;
        else b[i] = 0;
    }
    memset(dp, -1, sizeof(dp));
    LL ans = dfs(30, 1, 1, 1, 1);
    //printf("Cal %d %d %I64d\n", L, R, ans);
    return ans;
}

int _, L, R;
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d%d", &L, &R);
        LL ans = Cal(L, R);
        printf("%I64d\n", ans);
    }
    return 0;
}

/*
3
1 4
323 323
1 1000000

*/