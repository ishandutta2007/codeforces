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
const int V = 5010;
int s[V], f[V], h[V], pc[V][V];
int cnt[V];
vector<int> g[V];
int n, m;
int main() {
    while (~scanf("%d%d", &n, &m)) {
        n++;
        s[1] = n;
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n; ++i) g[i].clear();
        for (int i = 2; i <= n; ++i) {
            scanf("%d", &s[i]);
        }
        memset(pc, 0, sizeof(pc));
        for (int i = 1; i <= n; ++i) {
            cnt[s[i]]++;
            for (int j = 1; j <= n; ++j) pc[i][j] = pc[i - 1][j];
            pc[i][s[i]]++;
        }
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &f[i], &h[i]);
        }
        f[m] = n, h[m] = 1;
        m++;
        for(int i = 0; i < m; ++i) g[f[i]].PB(h[i]);
        for (int i = 1; i <= n; ++i) sort(g[i].begin(), g[i].end());
        int mx = 0, ans = 0;
        for (int i = 0; i < m; ++i) {
            if (cnt[f[i]] < h[i]) continue;
            int p = 0;
            for (int j = 1; j <= n; ++j) if(pc[j][f[i]] == h[i]) {p = j; break;}
            int tx = 0, ta = 1;
            for (int j = 1; j <= n; ++j) {
                if (g[j].size() == 0 || g[j][0] > cnt[j]) continue;
                //if (g[j].size() > 0)printf("cnt %d %d %d %d\n", j, cnt[j], g[j].size(), g[j][0]);
                int tw = 1;
                int L = 0, R = 0, LR = 0;
                for (int k = 0; k < g[j].size(); ++k) {
                    if (g[j][k] <= pc[p][j]) L++;
                    if (g[j][k] <= cnt[j] - pc[p][j]) R++;
                    if (g[j][k] <= pc[p][j] && g[j][k] <= cnt[j] - pc[p][j]) LR++;
                }
                if (j == f[i]) {
                    L = 1;
                    LR = 0;
                    if(h[i] <= cnt[j] - pc[p][j]) --R;
                }
                if (L * R - LR > 0) {
                //if (L > 0 && R > 0 && max(L, R) - LR > 0) {
                    tx += 2;
                    tw = L * R - LR;
                } else if (L + R > 0) {
                    tx += 1;
                    tw = L + R;
                }
                //printf("TC %d %d %d %d %d %d %d\n", p, j, L, R, LR, tx, tw);
                ta = (LL) ta * tw % P;
            }
            //printf("Cal %d %d %d %d %d\n", i, f[i], h[i], tx, ta);
            if (tx == mx) ans = (ans + ta) % P;
            else if (tx > mx) {
                mx = tx;
                ans = ta;
            }
        }
        printf("%d %d\n", mx - 1, (ans + P) % P);
    }
    return 0;
}

/*
5 2
1 1 1 1 1
1 2
1 3

5 2
1 1 1 1 1
1 2
1 4

3 2
2 3 2
3 1
2 1

5 1
1 1 1 1 1
2 5

6 4
1 1 1 2 2 2
1 1
1 2
2 1
2 2

2 2
1 2
1 1
2 1

3 2
1 2 1
1 2
2 1
*/