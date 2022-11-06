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
const int V = 20100;

struct Tree{
    int a[V];
    struct Node{
        int l, r, mx;
    }tr[4 * V];

    void init(int id, int l, int r) {
        tr[id].l = l;
        tr[id].r = r;
        if (l == r) {
            tr[id].mx = a[l];
            return;
        }
        int mid = (l + r) / 2;
        init(id * 2, l, mid);
        init(id * 2 + 1, mid + 1, r);
        tr[id].mx = max(tr[id * 2].mx, tr[id * 2 + 1].mx);
    }
    int read(int id, int l, int r) {
        if (tr[id].l == l && tr[id].r == r) return tr[id].mx;
        int mid = (tr[id].l + tr[id].r) / 2;
        if (r <= mid) return read(id * 2, l, r);
        else if (l > mid) return read(id * 2 + 1, l, r);
        else {
            int a = read(id * 2, l, mid);
            int b = read(id * 2 + 1, mid + 1, r);
            return max(a, b);
        }
    }
}T[3];

int w[52][V];
int dp[52][V], s[52][V];

int n, m, K;
int main() {
    while (~scanf("%d%d%d", &n, &m, &K)) {
        memset(w, 0, sizeof(w));
        memset(s, 0, sizeof(s));
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; ++i) {
            s[i][0] = 0;
            for (int j = 1; j <= m; ++j) {
                scanf("%d", &w[i][j]);
                s[i][j] = s[i][j - 1] + w[i][j];
            }
        }
        m -= K - 1;
        for (int i = 1; i <= m; ++i) dp[1][i] = s[1][i + K - 1] - s[1][i - 1] + s[2][i + K - 1] - s[2][i - 1];
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                T[0].a[j] = dp[i - 1][j];
                T[1].a[j] = dp[i - 1][j] - s[i][j + K - 1];
                T[2].a[j] = dp[i - 1][j] + s[i][j - 1];
            }
            for (int k = 0; k < 3; ++k) T[k].init(1, 1, m);
            for (int j = 1; j <= m; ++j) {
                dp[i][j] = 0;
                int tmp = s[i + 1][j + K - 1] - s[i + 1][j - 1] + s[i][j + K - 1] - s[i][j - 1];
                //printf("T %d %d %d %d %d\n", i, j, tmp, T[1].read(1, max(1, j - K + 1), j), s[i][j - 1]);
                if (j - K >= 1) dp[i][j] = max(dp[i][j], tmp + T[0].read(1, 1, j - K));
                if (j + K <= m) dp[i][j] = max(dp[i][j], tmp + T[0].read(1, j + K, m));
                dp[i][j] = max(dp[i][j], tmp + T[1].read(1, max(1, j - K + 1), j) + s[i][j - 1]);
                dp[i][j] = max(dp[i][j], tmp + T[2].read(1, j, min(m, j + K - 1)) - s[i][j + K - 1]);
            }
        }
        //puts("");for (int i = 1; i <= n; ++i, puts("")) for (int j = 1; j <= m; ++j) printf("%d ", dp[i][j]);
        int ans = 0;
        for (int j = 1; j <= m; ++j) ans = max(ans, dp[n][j]);
        printf("%d\n", ans);
    }
    return 0;
}

/*
4 5 2
0 2 1 1 0
0 0 3 1 2
1 0 4 3 1
3 3 0 0 4

3 3 1
1 2 3
4 5 6
7 8 9

3 3 2
1 2 3
4 5 6
7 8 9

3 3 3
1 2 3
4 5 6
7 8 9

*/