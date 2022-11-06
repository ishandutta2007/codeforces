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
vector<int> g[V];
int n, m, _, x, y, cnt[V], ans[V];
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i) cnt[i] = 0;
        for (int i = 0; i < m; ++i) g[i].clear();
        for (int i = 0; i < m; ++i) {
            scanf("%d", &x);
            for (int j = 0; j < x; ++j) {
                scanf("%d", &y);
                g[i].PB(y);
            }
        }
        for (int i = 0; i < m; ++i) {
            if (g[i].size() == 1) {
                cnt[g[i][0]]++;
                ans[i] = g[i][0];
            }
        }
        for (int i = 0; i < m; ++i) {
            if (g[i].size() == 1) continue;
            int id = -1;
            for (int j = 0; j < g[i].size(); ++j) {
                if (id == -1 || cnt[id] > cnt[g[i][j]]) id = g[i][j];
            }
            cnt[id]++;
            ans[i] = id;
        }
        bool ok = true;
        for (int i = 1; i <= n; ++i) if (cnt[i] > (m + 1) / 2) ok = false;
        if (ok) {
            puts("YES");
            for (int i = 0; i < m; ++i) printf("%d ", ans[i]); puts("");
        } else {
            puts("NO");
        }
    }
    return 0;
}

/*
2
4 6
1 1
2 1 2
3 1 2 3
4 1 2 3 4
2 2 3
1 3
2 2
1 1
1 1
*/