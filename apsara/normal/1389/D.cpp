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
const int ooo = 1000000000;
const LL oo = (LL) ooo * ooo;
int _, n, K, A, B, C, D;

int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d%d", &n, &K);
        scanf("%d%d%d%d", &A, &B, &C, &D);
        int fr = max(0, min(B, D) - max(A, C));
        int c0 = max(0, max(A, C) - min(B, D));
        int c1 = max(B, D) - min(A, C) - fr;
        LL ans = oo;
        if (K <= (LL) fr * n) {
            puts("0");
            continue;
        }
        //printf("%d %d %d\n", fr, c0, c1);
        K -= fr * n;
        for (int i = 1; i <= n; ++i) {
            LL cost = (LL) i * c0;
            if ((LL) i * c1 >= K) cost += K;
            else cost += 2 * K - (LL) i * c1;
            ans = min(ans, cost);
        }
        printf("%I64d\n", ans);
    }
    return 0;
}

/*
3
3 5
1 2
3 4
2 1000000000
1 1
999999999 999999999
10 3
5 10
7 8
*/