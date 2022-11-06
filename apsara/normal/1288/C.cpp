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

using namespace std;
typedef long long LL;
const int P = 1000000007;

const int N = 1050;
const int V = 1100;
int C[V][V];

int n, m;
int main() {
    for (int i = 0; i <= N; ++i) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; ++j)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % P;
    }
    while (~scanf("%d%d", &n, &m)) {
        int ans = 0;
        for (int l = 1; l <= n; ++l) {
            for (int r = l; r <= n; ++r) {
                ans += (LL)C[l - 1 + m - 1][m - 1] * C[n - r + m - 1][m - 1] % P;
                ans %= P;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

/*
2 2
10 1
723 9
*/