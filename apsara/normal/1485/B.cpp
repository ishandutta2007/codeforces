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
int a[V], b[V], n, Q, K, l, r;
LL s[V];

int main() {
    while (~scanf("%d%d%d", &n, &Q, &K)) {
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        a[0] = 0; a[n + 1] = K + 1;
        for (int i = 1; i <= n; ++i) b[i] = a[i + 1] - a[i - 1] - 2;
        s[0] = 0;
        for (int i = 1; i <= n; ++i) s[i] = s[i - 1] + b[i];
        while (Q--) {
            scanf("%d%d", &l, &r);
            LL ans = s[r] - s[l - 1];
            ans += a[l - 1];
            ans += K + 1 - a[r + 1];
            if (l == r) ans = K - 1;
            printf("%I64d\n", ans);
        }
    }
    return 0;
}

/*
4 2 5
1 2 4 5
2 3
3 4

6 5 10
2 4 6 7 8 9
1 4
1 2
3 5
1 6
5 5
*/