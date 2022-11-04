#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <bitset>
#define int long long
#define M 600010

using namespace std;

int n, m, X[M], Y[M], D[M], tmp[M], oAns[M];

bool cmp(int x, int y) {
    return D[x] < D[y];
}

signed main() {
    scanf("%lld%lld", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%lld%lld", &X[i], &Y[i]), D[i] = Y[i] - X[i], tmp[i] = i;
    for(int i = 1; i <= m; i++) {
        int a, b;
        scanf("%lld%lld", &a, &b);
        int s = min(X[a] + Y[b], X[b] + Y[a]);
        oAns[a] -= s;
        oAns[b] -= s;
    }
    int smD = 0, smX = 0;
    for(int i = 1; i <= n; i++) smX += X[i];
    sort(tmp + 1, tmp + n + 1, cmp);
    for(int i = 1; i <= n; i++) {
        int x = tmp[i];
        oAns[x] += (n - i) * D[x] + smD + smX + X[x] * (n - 2);
        smD += D[x];
    }
    for(int i = 1; i <= n; i++) printf("%lld ", oAns[i]);
    putchar('\n');
    return 0;
}