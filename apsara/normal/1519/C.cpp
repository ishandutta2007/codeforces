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
const int V = 200100;

int a[V], b[V];
vector<int> g[V];
vector<LL> s[V];
LL ans[V];

int _, n;
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        for (int i = 0; i < n; ++i) scanf("%d", &b[i]);
        for (int i = 1; i <= n; ++i) g[i].clear();
        for (int i = 0; i < n; ++i) g[a[i]].PB(b[i]);
        for (int i = 1; i <= n; ++i) ans[i] = 0;
        for (int i = 1; i <= n; ++i) {
            sort(g[i].begin(), g[i].end());
            s[i].clear();
            s[i].PB(0);
            for (int j = 1; j <= g[i].size(); ++j) s[i].PB(s[i][j - 1] + g[i][g[i].size() - j]);
            for (int j = 1; j <= g[i].size(); ++j) {
                for (int k = 2 * j; k <= g[i].size(); k += j) s[i][j] = s[i][k];
            }
            for (int j = 1; j <= g[i].size(); ++j) ans[j] += s[i][j];
        }
        for (int i = 1; i <= n; ++i) printf("%I64d ", ans[i]); puts("");
    }
    return 0;
}

/*
4
7
1 2 1 2 1 2 1
6 8 3 1 5 1 5
10
1 1 1 2 2 2 2 3 3 3
3435 3014 2241 2233 2893 2102 2286 2175 1961 2567
6
3 3 3 3 3 3
5 9 6 7 9 7
1
1
3083
*/