#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <cstdlib>
#include <cmath>


using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)
const int N = 1e3;
const int INF = 1e9;

int a[N];


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    int n, m, v, u, c;
    double ans = 0;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &v, &u, &c);
        v--; u--;
        ans = max(ans, (a[v] + a[u]) * 1.0 / c);
    }
    printf("%.15lf\n", ans);
    return 0;
}