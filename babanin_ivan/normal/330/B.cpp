#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>

using namespace std;

#define pb push_back
#define mp make_pair
#define fir first
#define fi first
#define sec second
#define y1 botva23
typedef long long int64;
typedef long double ld;

const int inf = 2000000000;
const ld eps = 1e-07;

int n, m;
int a[2000];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        ++a[x];
        ++a[y];
    }
    for (int i = 0; i < n; ++i)
        if (a[i + 1] == 0) {
            printf("%d\n", n - 1);
            for (int j = 1; j <= n; ++j) {
                if (j != (i + 1))
                    printf("%d %d\n", i + 1, j);
            }
            return 0;
        }
    return 0;
}