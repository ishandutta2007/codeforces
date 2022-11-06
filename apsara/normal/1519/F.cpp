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
const int V = 10;
const int M = 5;
int a[V], b[V], c[V][V];
int n, m;

int mask(vector<int> s) {
    int res = 0;
    for (int i = m - 1; i >= 0; --i) {
        res *= M;
        res += s[i];
    }
    return res;
}

vector<int> des(int res) {
    vector<int> s;
    for (int i = 0; i < m; ++i) {
        s.PB(res % M);
        res /= M;
    }
    return s;
}

map<int, int> dp[V];

int use[V];

void dfs(int i, int mk, int id, int re, vector<int> s, int cost) {
    if (id == m) {
        if (re == 0) {
            vector<int> is;
            for (int j = 0; j < m; ++j) is.PB(s[j] - use[j]);
            int msk = mask(is);
            //printf("%d %d  MK: ", mk, cost);
            //for (int j = 0; j < s.size(); ++j) printf("%d ", is[j]); puts("");
            int tmp = cost;
            if (dp[i].find(msk) != dp[i].end()) tmp = min(tmp, dp[i][msk]);
            dp[i][msk] = tmp;
        }
        return;
    }
    int R = 0;
    if (mk & (1 << id)) R = min(s[id], re);
    for (int j = 0; j <= R; ++j) {
        use[id] = j;
        dfs(i, mk, id + 1, re - j, s, cost);
    }
}

int main() {
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        for (int i = 0; i < m; ++i) scanf("%d", &b[i]);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                scanf("%d", &c[i][j]);
            }
        }
        for (int i = 0; i <= n; ++i) dp[i].clear();
        vector<int> is;
        for (int i = 0; i < m; ++i) is.PB(b[i]);
        dp[0][mask(is)] = 0;
        for (int i = 0; i < n; ++i) {
            for (map<int, int>::iterator it = dp[i].begin(); it != dp[i].end(); ++it) {
                vector<int> s = des(it->fi);
                int w = it->se;
                //printf("%d %d DP: ", i, w);
                //for (int j = 0; j < s.size(); ++j) printf("%d ", s[j]); puts("");
                for (int j = 0; j < (1 << m); ++j) {
                    int cost = 0;
                    for (int k = 0; k < m; ++k) {
                        if (j & (1 << k)) cost += c[i][k];
                    }
                    for (int k = 0; k < m; ++k) use[k] = 0;
                    //printf("%d %d\n", j, cost);
                    dfs(i + 1, j, 0, a[i], s, cost + w);
                }
            }
        }
        int ans = -1;
        for (map<int, int>::iterator it = dp[n].begin(); it != dp[n].end(); ++it) {
            int w = it->se;
            if (ans == -1 || ans > w) ans = w;
        }
        printf("%d\n", ans);
    }
    return 0;
}

/*
2 3
3 3
1 1 4
10 20 100
20 15 80

2 3
3 3
2 1 4
10 20 100
20 15 80

2 3
3 4
1 1 4
10 20 100
20 15 80

*/