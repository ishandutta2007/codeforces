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
const int maxn = -1;
const int inf = 1e9;


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
#endif
    int n, k;
    scanf("%d%d", &n, &k);
    if (n == 1) {
        if (k == 0) {
            printf("%d\n", 1);
            return 0;
        }
        printf("-1\n");
        return 0;
    }
    if (n / 2 > k) {
        printf("-1\n");
        return 0;
    }
    int x = k - (n / 2 - 1);
    printf("%d %d ", x, x * 2);
    int cur = 0;
    for (int i = 2; i < n; i++) {
        cur++;
        if (cur == x)
            cur++;
        if (cur == x * 2)
            cur++;
        printf("%d ", cur);
    }
    printf("\n");



    return 0;
}