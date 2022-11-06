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
int a[V][V], n, m, r[V], c[V], ans[V][V];
int use[V * V];

bool solve() {
    memset(use, 0, sizeof(use));
    sort(r, r + n);
    sort(c, c + m);
    int pr = 0, pc = 0;
    int cur = 1;
    for (int i = 0; i < n; ++i) use[r[i]] = 1;
    for (int i = 0; i < m; ++i) use[c[i]] = 1;
    while (1) {
        if (pr == n && pc == m) break;
        if (pc == m || r[pr] < c[pc]) {
            ans[pr][pc] = r[pr];
            for (int j = m - 1; j > pc; --j) {
                while (use[cur] == 1) ++cur;
                if (cur > r[pr]) return false;
                ans[pr][j] = cur++;
            }
            ++pr;
        } else if (pr == n || c[pc] < r[pr]) {
            ans[pr][pc] = c[pc];
            for (int i = n - 1; i > pr; --i) {
                while (use[cur] == 1) ++cur;
                if (cur > c[pc]) return false;
                ans[i][pc] = cur++;
            }
            ++pc;
        } else {
            ans[pr][pc] = c[pc];
            for (int i = n - 1; i > pr; --i) {
                while (use[cur] == 1) ++cur;
                if (cur > c[pc]) return false;
                ans[i][pc] = cur++;
            }
            for (int j = m - 1; j > pc; --j) {
                while (use[cur] == 1) ++cur;
                if (cur > r[pr]) return false;
                ans[pr][j] = cur++;
            }
            ++pc;
            ++pr;
        }
    }
    return true;
}

int main() {
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j)
                scanf("%d", &a[i][j]);
        }
        for (int i = 0; i < n; ++i) {
            r[i] = -1;
            for (int j = 0; j < m; ++j) r[i] = max(r[i], a[i][j]);
        }
        for (int j = 0; j < m; ++j) {
            c[j] = -1;
            for (int i = 0; i < n; ++i) c[j] = max(c[j], a[i][j]);
        }
        bool ok = solve();
        if (!ok) puts("-1");
        else {
            for (int i = 0; i < n; ++i, puts(""))
                for (int j = 0; j < m; ++j) printf("%d ", ans[i][j]);
        }
    }
    return 0;
}

/*
3 3
3 5 6
1 7 9
4 8 2
2 2
4 1
3 2
3 4
12 10 8 6
3 4 5 7
2 11 9 1
*/