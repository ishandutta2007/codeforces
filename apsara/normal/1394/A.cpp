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
int a[V], b[V], c[V], n, d, m, x, y;
LL s[V];
int main() {
    while (~scanf("%d%d%d", &n, &d, &m)) {
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        sort(a, a + n);
        x = y = 0;
        for (int i = n - 1; i >= 0; --i) if (a[i] <= m) b[++x] = a[i];
        s[0] = 0;
        for (int i = 1; i <= x; ++i) s[i] = s[i - 1] + b[i];
        LL ans = s[x];
        for (int i = n - 1; i >= 0; --i) if(a[i] > m) c[++y] = a[i];
        LL tmp = 0;
        for (int i = 1; (i - 1) * (d + 1) + 1 <= n; ++i) {
            if (i > y) break;
            tmp += c[i];
            int re = n - (i - 1) * (d + 1) - 1;
            re = min(re, x);
            //printf("%d %I64d %d %I64d\n", i, tmp, re, s[re]);
            ans = max(ans, tmp + s[re]);
        }
        printf("%I64d\n", ans);
    }
    return 0;
}

/*
5 2 11
8 10 15 23 5
20 2 16
20 5 8 2 18 16 2 16 16 1 5 16 2 13 6 16 4 17 21 7
*/