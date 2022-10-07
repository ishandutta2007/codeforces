#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <queue>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)
const int maxn = 1000 + 10;
const int inf = 1e9;

int a[maxn][maxn];
int b[maxn];
int c[maxn];
int r[2][2][maxn];


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
#endif
    int n, type, x, m;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = (ans + a[i][i]) % 2;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &type);
        if (type == 3) {
            printf("%d", ans);
        }
        else {
            scanf("%d", &x);
            ans ^= 1;
        }
    }
    return 0;
}