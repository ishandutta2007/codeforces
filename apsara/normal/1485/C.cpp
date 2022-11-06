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
int _, A, B;
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d%d", &A, &B);
        LL ans = 0;
        for (int i = 1; ; ++i) {
            int L = i + 1;
            int R = min(B, A / i - 1);
            if (L > R) break;
            ans += R - L + 1;
        }
        printf("%I64d\n", ans);
    }
    return 0;
}

/*
9
3 4
2 100
4 3
50 3
12 4
69 420
12345 6789
123456 789
12345678 9
*/