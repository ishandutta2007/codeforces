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
const int maxn = 1e3 + 10;
const int inf = 1e9;
const int MOD = 1e9;

int a[maxn];
long long f[maxn];


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    int n, m, x, y, type;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    f[0] = 1;
    f[1] = 1;
    for (int i = 2; i < n; i++) {
        f[i] = (f[i - 1] + f[i - 2]) % MOD;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &type, &x, &y);
        if (type == 1) {
            a[x - 1] = y;
        }
        if (type == 2) {
            long long ans = 0;
            for (int i = 0; i < y - x + 1; i++) {
                ans = (ans + f[i] * a[x - 1 + i]) % MOD;
            }
            printf("%lld\n", ans);
        }
        if (type == 3) {
            int z;
            scanf("%d", &z);
            for (int i = x - 1; i < y; i++)
                a[i] += z;
        }
    }

    return 0;
}