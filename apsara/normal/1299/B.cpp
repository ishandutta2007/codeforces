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
const int P = 1000000007;
const int V = 100100;
int n, m, x[V], y[V];
int main() {
    while (~scanf("%d", &n)) {
        for (int i = 0; i < n; ++i) scanf("%d%d", &x[i], &y[i]);
        if (n % 2 != 0) {
            puts("NO");
            continue;
        }
        m = n / 2;
        bool ok = true;
        for (int i = 0; i < m; ++i) {
            if (x[i + 1] - x[i] != x[i + m] - x[(i + m + 1) % n] ||
                y[i + 1] - y[i] != y[i + m] - y[(i + m + 1) % n])
                ok = false;
        }
        if (ok) puts("YES");
        else puts("NO");
    }
    return 0;
}

/*

*/