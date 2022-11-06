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

const int V = 310;

int _, n, m, a[V][V], b[V][V];

int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d%d", &n, &m);
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                scanf("%d", &a[i][j]);
                b[i][j] = 0;
                if (i != 0) ++b[i][j];
                if (i != n - 1) ++b[i][j];
                if (j != 0) ++b[i][j];
                if (j != m - 1) ++b[i][j];
                if (a[i][j] > b[i][j]) ok = false;
            }
        }
        if (!ok) {
            puts("NO");
        } else {
            puts("YES");
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) printf("%d ", b[i][j]); puts("");
            }
        }
    }
    return 0;
}

/*
5
3 4
0 0 0 0
0 1 0 0
0 0 0 0
2 2
3 0
0 0
2 2
0 0
0 0
2 3
0 0 0
0 4 0
4 4
0 0 0 0
0 2 0 1
0 0 0 0
0 0 0 0
*/