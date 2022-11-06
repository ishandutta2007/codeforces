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
typedef pair<int, int> PII;
#define PB push_back
#define fi first
#define se second
#define MP make_pair
const int P = 998244353;
const int V = 110;

int pow(int x, int y) {
    int res = 1;
    while (y) {
        if (y & 1) res = (LL) res * x % P;
        x = (LL) x * x % P; y /= 2;
    }
    return res;
}

int f(int n, int L) {
    if (L == 1) return 1;
    //C(n - 1 + L, L)
    int res = 1;
    for (int i = 1; i <= L; ++i) {
        res = (LL) res * (n - 1 + L + 1 - i) % P;
        res = (LL) res * pow(i, P - 2) % P;
        res = (LL) res * pow(n, P - 2) % P;
    }
    return res;
}

int dp[V][V][V];
int way[V][V];
int seg[V], rev[V], l[V], r[V];
int a[V], p[V][V];

int n, idx;

void OT() {
    puts("OT");
    printf("IDX %d\n", idx);
    for (int i = 0; i < n; ++i, puts(""))
        for (int j = 1; j < idx; ++j)
            printf("%d ", p[i][j]);
    for (int i = 1; i < idx; ++i, puts(""))
        for (int j = 1; j <= n; ++j)
            printf("%d ", way[i][j]);
    puts("OT END");
}

int main() {
    while (~scanf("%d", &n)) {
        for (int i = n - 1; i >= 0; --i) scanf("%d%d", &l[i], &r[i]);
        map<int, int> mp;
        int m = 0;
        for (int i = 0; i < n; ++i) a[m++] = l[i], a[m++] = r[i] + 1;
        sort(a, a + m);
        idx = 0;
        for (int i = 0; i < m; ++i) if (i == 0 || a[i] != a[i - 1]) mp[a[i]] = ++idx, rev[idx] = a[i];
        for (int i = 1; i < idx; ++i) seg[i] = rev[i + 1] - rev[i];
        for (int i = 1; i < idx; ++i)
            for (int j = 1; j <= n; ++j)
                way[i][j] = f(seg[i], j);
        way[0][1] = 1;
        for (int i = 0; i < n; ++i)
            for (int j = 1; j < idx; ++j)
                p[i][j] = (LL) seg[j] * pow(r[i] - l[i] + 1, P - 2) % P;
        //OT();
        memset(dp, 0, sizeof(dp));
        dp[0][0][1] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < idx; ++j) {
                for (int k = 1; k <= n; ++k) {
                    if (dp[i][j][k] == 0) continue;
                    //printf("DP %d %d %d %d\n", i, j, k, dp[i][j][k]);
                    for (int sg = max(1, j); sg < idx; ++sg) {
                        if (rev[sg] >= r[i] + 1 || rev[sg + 1] <= l[i]) continue;
                        //printf("TR %d\n", sg);
                        if (sg == j) {
                            dp[i + 1][j][k + 1] = (dp[i + 1][j][k + 1] +
                                (LL) dp[i][j][k] * p[i][sg] % P) % P;
                        } else {
                            dp[i + 1][sg][1] = (dp[i + 1][sg][1] +
                                (LL) dp[i][j][k] * way[j][k] % P * p[i][sg] % P) % P;
                        }
                    }
                }
            }
        }
        int ans = 0;
        for (int j = 0; j < idx; ++j)
            for (int k = 1; k <= n; ++k)
                ans = (ans + (LL) dp[n][j][k] * way[j][k] % P) % P;
        printf("%d\n", ans);
    }
    return 0;
}

/*
3
1 2
1 2
1 2

2
42 1337
13 420

2
1 1
0 0

2
1 1
1 1

*/