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

int AD(LL n) {
    LL x = n;
    int mx = 0, mi = 9;
    while (x) {
        int y = x % 10;
        mx = max(y, mx);
        mi = min(y, mi);
        x /= 10;
    }
    return mi * mx;
}
int _;
LL n, K;

int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%I64d%I64d", &n, &K);
        --K;
        while (K--) {
            int add = AD(n);
            if (add == 0) break;
            n += add;
        }
        printf("%I64d\n", n);
    }
    return 0;
}

/*
8
1 4
487 1
487 2
487 3
487 4
487 5
487 6
487 7
*/