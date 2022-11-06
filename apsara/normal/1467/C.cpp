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
const int V = 300100;
int c[3], a[3][V];
LL s[3];
int main() {
    while (~scanf("%d%d%d", &c[0], &c[1], &c[2])) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < c[i]; ++j) scanf("%d", &a[i][j]);
            sort(a[i], a[i] + c[i]);
            s[i] = 0;
            for (int j = 0; j < c[i]; ++j) s[i] += a[i][j];
        }
        LL ans = 0;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    if (i == j || i == k || j == k) continue;
                    LL tmp1 = s[i] + s[j] - s[k];
                    LL tmp2 = s[i] + s[j] + s[k] - 2LL * (a[j][0] + a[k][0]);
                    //printf("A %d %d %d %I64d %I64d\n", i, j, k, tmp1, tmp2);
                    ans = max(ans, tmp1);
                    ans = max(ans, tmp2);
                }
            }
        }
        printf("%I64d\n", ans);
    }
    return 0;
}

/*
2 4 1
1 2
6 3 4 5
5

3 2 2
7 5 4
2 9
7 1
*/