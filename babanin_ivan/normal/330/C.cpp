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
int a[2000][200];
int b[2000];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    scanf("%d %d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            char c;
            scanf(" %c ", &c);
            if (c == 'E')
                a[i][j] = 1;
            else a[i][j] = 0;
        }
    }
    
    int k;

    k = 0;
    for (int i = 0; i < n; ++i) {
        b[i] = -1;
        for (int j = 0; j < n; ++j)
            if (!a[i][j])
                b[i] = j;
        if (b[i] != -1)
            ++k;
    }
    if (k == n) {
        for (int i = 0; i < n; ++i) {
            printf("%d %d\n", i + 1, b[i] + 1);
        }
        return 0;
    }

    k = 0;
    for (int i = 0; i < n; ++i) {
        b[i] = -1;
        for (int j = 0; j < n; ++j)
            if (!a[j][i])
                b[i] = j;
        if (b[i] != -1)
            ++k;
    }
    if (k == n) {
        for (int i = 0; i < n; ++i) {
            printf("%d %d\n", b[i] + 1, i + 1);
        }
        return 0;
    }
    printf("-1\n");
    return 0;
}