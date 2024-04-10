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
 
const int V = 100100;
LL sqr(int x) {return (LL) x * x;}
int c[3], a[3][V], p[3];
 
int _;
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d%d%d", &c[0], &c[1], &c[2]);
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < c[i]; ++j) scanf("%d", &a[i][j]);
            sort(a[i], a[i] + c[i]);
        }
        LL ans = sqr(a[0][0] - a[1][0]) + sqr(a[0][0] - a[2][0]) + sqr(a[2][0] - a[1][0]);
        for(int i = 0; i < 3; ++i) {
            for (int j = 0; j < 2; ++j) {
                int x = (i + 1 + j) % 3;
                int y = (i + 2 - j) % 3;
                memset(p, 0, sizeof(p));
                for (int k = 0; k < c[i]; ++k) {
                    while (p[x] != c[x] - 1 && a[i][k] >= a[x][p[x] + 1]) p[x]++;
                    while (p[y] != c[y] - 1 && a[i][k] > a[y][p[y]]) p[y]++;
                    LL tmp = sqr(a[i][k] - a[x][p[x]]) + sqr(a[i][k] - a[y][p[y]]) + sqr(a[x][p[x]] - a[y][p[y]]);
                    ans = min(ans, tmp);
                }
            }
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
 
/*
5
2 2 3
7 8
6 3
3 1 4
1 1 1
1
1
1000000000
2 2 2
1 2
5 4
6 7
2 2 2
1 2
3 4
6 7
3 4 1
3 2 1
7 3 3 4
6
*/