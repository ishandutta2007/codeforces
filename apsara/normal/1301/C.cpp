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

int _, n, m;
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d%d", &n, &m);
        LL ans = (LL) (n + 1) * n / 2;
        int c0 = n - m;
        int re = c0 % (m + 1);
        int div = c0 / (m + 1);
        ans -= (LL) re * (div + 2) * (div + 1) / 2;
        ans -= (LL) (m + 1 - re) * (div + 1) * (div + 0) / 2;
        printf("%I64d\n", ans);
    }
    return 0;
}

/*
5
3 1
3 2
3 3
4 0
5 2
*/