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

int _, n, m, K, L, R, x, y;
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d%d%d", &n, &K, &m);
        L = K, R = K;
        while (m--) {
            scanf("%d%d", &x, &y);
            if (max(x, L) <= min(y, R)) {
                L = min(x, L);
                R = max(y, R);
            }
        }
        printf("%d\n", R - L + 1);
    }
    return 0;
}

/*
3
6 4 3
1 6
2 3
5 5
4 1 2
2 4
1 2
3 3 2
2 3
1 2
*/