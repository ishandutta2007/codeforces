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
char s[V], t[V];
const int N = 20;
int vis[30][30], d[30][30], _, n;
int use[30];
int dfs(int u) {
    use[u] = 1;
    int cnt = 1;
    for (int i = 0; i < N; ++i) if (vis[u][i] && !use[i]) cnt += dfs(i);
    for (int i = 0; i < N; ++i) if (vis[i][u] && !use[i]) cnt += dfs(i);
    return cnt;
}
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        scanf("%s%s", s, t);
        memset(vis, 0, sizeof(vis));
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            if (s[i] > t[i]) ok = false;
            if (s[i] < t[i]) vis[s[i] - 'a'][t[i] - 'a'] = 1;
        }
        if (!ok) {puts("-1"); continue;}
        int ans = 0;
        memset(use, 0, sizeof(use));
        for (int i = 0; i < N; ++i) {
            if (!use[i]) ans += dfs(i) - 1;
        }
        /*
        for (int k = 0; k < N; ++k)
            for (int i = 0; i < N; ++i)
                for (int j = 0; j < N; ++j)
                    if (vis[i][k] && vis[k][j]) vis[i][j] = 1;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                d[i][j] = vis[i][j];
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                for (int k = j + 1; k < N; ++k) {
                    if (vis[i][j] && vis[j][k]) d[i][k] = 0;
                }
            }
        }
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                ans += d[i][j];
        */
        printf("%d\n", ans);
    }
    return 0;
}

/*
5
3
aab
bcc
4
cabc
abcb
3
abc
tsr
4
aabd
cccd
5
abcbd
bcdda
*/