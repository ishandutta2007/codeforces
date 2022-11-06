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
const int P = 998244353;
const int V = 300100;
int Pow(int x, int y) {
    int res = 1;
    while (y) {
        if (y & 1) res = (LL) res * x % P;
        x = (LL) x * x % P; y /= 2;
    }
    return res;
}

int a[V], L[V], U[V], dp[V];
char s[V];
int n, m;
int main() {
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 0; i < n; ++i) {
            scanf("%s", s);
            for (int j = 0; j < m; ++j) a[i * m + j] = s[j] == 'o' ? 1 : 0;
        }
        int wn = 0;
        for (int i = 0; i < n * m; ++i) wn += a[i];
        int ans = 1;
        for (int i = 0; i < wn; ++i) ans = ans * 2 % P;
        for (int i = 0; i < n * m; ++i) {
            if (a[i] == 0) continue;
            if (i / m == 0 || a[i - m] == 0) U[i] = 1;
            else U[i] = U[i - m] + 1;
            if (i % m == 0 || a[i - 1] == 0) L[i] = 1;
            else L[i] = L[i - 1] + 1;
        }
        int r2 = Pow(2,  P - 2);
        int r4 = Pow(4,  P - 2);
        int r8 = Pow(8,  P - 2);
        dp[1] = 0;
        dp[2] = r4;
        dp[3] = r8;
        for (int i = 4; i <= n * m; ++i) dp[i] = (r8 + (LL) dp[i - 2] * r4 % P) % P;
        int res = 0;
        for (int i = 0; i < n * m; ++i) {
            if (a[i] == 0) continue;
            //printf("%d %d %d %d\n", i / m, i % m, L[i], U[i]);
            res = (res + dp[L[i]]) % P;
            res = (res + dp[U[i]]) % P;
        }
        printf("%d\n", (LL) ans * res % P);
    }
    return 0;
}

/*
3 4
**oo
oo*o
**oo

3 4
**oo
oo**
**oo

2 2
oo
o*

1 4
oooo
*/