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

LL cal(int a, int b, int c) {
    if (a == 0 || b == 0) return 0;
    //a + b > c
    if (a + b <= c) return 0;
    int t = a + b - c;
    printf("Cal %d %d %d %d\n", a, b, c, t);
    return (LL) t * (t + 1) / 2;
}

int A, B, C, D;
const int V = 500100;
LL s[2 * V];

int main() {
    while (~scanf("%d%d%d%d", &A, &B, &C, &D)) {
            /*
        LL ans = 0;
        for (int z = C; z <= D; ++z) {
            ans += cal(B, C, z);
            ans -= cal(A - 1, C, z);
            ans -= cal(A, B - 1, z);
            ans += cal(A - 1, B - 1, z);
        }
        printf("%I64d\n", ans);
        */
        memset(s, 0, sizeof(s));
        for (int x = A; x <= B; ++x) {
            --s[x + C + 1];
            ++s[x + B];
        }
        for (int i = 1; i <= 2 * D + 1; ++i) s[i] += s[i - 1];
        //for (int i = 1; i <= 2 * D + 1; ++i) printf("%I64d ", s[i]);puts("");
        for (int i = 2 * D + 1; i > 0; --i) s[i] += s[i + 1];
        //for (int i = 1; i <= 2 * D + 1; ++i) printf("%I64d ", s[i]);puts("");
        LL ans = 0;
        for (int z = C; z <= D; ++z) ans += s[z + 1];
        printf("%I64d\n", ans);
    }
    return 0;
}

/*
1 2 3 4
1 2 2 5
500000 500000 500000 500000
*/