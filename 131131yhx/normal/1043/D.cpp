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

using namespace std;

int n, m, A[111111][12], tmp[111111];

bool cmp(int x, int y) {
    return A[x][1] < A[y][1];
}

int same(int x, int y) {
    for(int i = 1; i < m; i++) if(A[x][i] != A[y][i]) return 0;
    return 1;
}

signed main() {
    scanf("%lld%lld", &n, &m);
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++) {
            int x;
            scanf("%lld", &x);
            A[x][i] = j;
        }
    for(int i = 1; i <= n; i++) tmp[i] = i;
    sort(tmp + 1, tmp + n + 1, cmp);
    vector <int> V;
    V.clear();
    for(int i = 1; i <= n; i++) {
        int x = tmp[i];
        for(int j = 1; j < m; j++)
            A[x][j] -= A[x][j + 1];
    }
    int ans = 0;
    for(int i = 1, lst = 1; i <= n; i = ++lst) {
        while(lst < n && same(tmp[lst + 1], tmp[i])) lst++;
        ans = ans + (lst - i + 1) * (lst - i + 2) / 2;
    }
    printf("%lld\n", ans);
    return 0;
}