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
int n, a, b, c, d;
int main() {
    while (~scanf("%d", &n)) {
        ////scanf("%d%d%d%d", &a, &c, &b, &d);
        scanf("%d%d%d%d", &a, &b, &c, &d);
        //printf("%d %d %d %d\n", a, b, c, d);
        int g2 = __gcd(abs(a), abs(c));
        int g1 = __gcd(abs(b), abs(d));
        //printf("%d %d\n", g1, g2);
        if (g1 == 0 || g2 == 0) {
            puts("NO");
            continue;
        }
        LL x = llabs((LL) b * c / g1 - (LL) a * d / g1);
        LL y = llabs((LL) b * c / g2 - (LL) a * d / g2);
        //printf("%lld %lld\n", x, y);
        if (g2 > n || y > n || (LL) g2 * y != n) {
            puts("NO");
        } else {
            puts("YES");
            for (int i = 0; i < g2; ++i)
                for (int j = 0; j < y; ++j)
                    printf("%d %d\n", i, j);
        }
    }
    return 0;
}

/*
4
2 0
0 2

5
2 6
1 5

2
3 4
1 2
*/