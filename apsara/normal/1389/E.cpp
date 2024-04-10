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
const int T = 33333;

int gcd(int x, int y) {
    if (!y) return x;
    if (!x) return y;
    return gcd(y, x % y);
}
int _, m, d, w;
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d%d%d", &m, &d, &w);
        if (d == 0) {
            puts("0");
            continue;
        }
        int n = min(m, d);
        int gd = gcd(d - 1, w);
        int mul = w / gd;
        LL ans = 0;
        if (mul < T) {
            for (int i = 0; i < mul; ++i) {
                int cnt = n / mul;
                if (i < n % mul) ++cnt;
                ans += (LL) cnt * (cnt - 1) / 2;
            }
        } else {
            for (int i = 1; i * mul <= n; ++i) {
                ans += n - i * mul;
            }
        }
        printf("%I64d\n", ans);
    }
    return 0;
}

/*
5
6 7 4
10 7 12
12 30 7
1 1 1
3247834 10298779 625324
*/