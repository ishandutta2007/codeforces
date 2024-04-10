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
const int V = 520;
int a[V][V], n, m;

int main() {
    int lcm = 1;
    for (int i = 1; i <= 16; ++i) {
        int gd = __gcd(i, lcm);
        lcm *= i / gd;;
    }
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) scanf("%d", &a[i][j]);
        for (int i = 0; i < n; ++i, puts("")) {
            for (int j = 0; j < m; ++j) {
                int ans = lcm;
                if ((i + j) & 1) {
                    ans = lcm - a[i][j] * a[i][j] * a[i][j] * a[i][j];
                }
                printf("%d ", ans);
            }
        }
    }
    return 0;
}

/*
2 2
1 2
2 3

2 3
16 16 16
16 16 16

2 2
3 11
12 8

*/