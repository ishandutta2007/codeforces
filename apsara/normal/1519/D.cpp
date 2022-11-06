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
const int V = 5010;
int n, a[V], b[V];
LL s[V], r[V];
int main() {
    while (~scanf("%d", &n)) {
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        for (int i = 1; i <= n; ++i) scanf("%d", &b[i]);
        s[0] = 0;
        for (int i = 1; i <= n; ++i) s[i] = s[i - 1] + (LL) a[i] * b[i];
        LL ans = s[n];
        for (int i = 1; i <= 2 * n; ++i) {
            r[0] = 0;
            for (int j = 1; j <= n; ++j) {
                r[j] = r[j - 1];
                if (i - j >= 1 && i - j <= n) r[j] += (LL) a[j] * b[i - j];
            }
            for (int L = 1; L <= n; ++L) {
                int R = i - L;
                if (R <= 0 || R > n || R < L) continue;
                int y = R;
                int z = L - 1;
                LL tmp = s[L - 1] + s[n] - s[R] + r[y] - r[z];
                //printf("LL %d %d %d %d %lld %lld %lld\n", L, R, y, z, s[L - 1], s[n] - s[R], tmp);
                ans = max(ans, tmp);
            }
            //for (int j = 1; j <= n; ++j) printf("%I64d ", r[j]); puts("");
        }
        printf("%I64d\n", ans);
    }
    return 0;
}

/*
5
2 3 2 1 3
1 3 2 4 2

2
13 37
2 4

6
1 8 7 6 3 6
5 9 6 8 8 6
*/