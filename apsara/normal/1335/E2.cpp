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
const int N = 200;
vector<int> g[V];
int s[V][N + 5];
int _, n, a[V];

int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        int MX = 1;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
            MX = max(a[i], MX);
        }
        for (int i = 1; i <= MX; ++i) s[0][i] = 0, g[i].clear();
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= MX; ++j) s[i][j] = s[i - 1][j];
            s[i][a[i]]++;
            g[a[i]].PB(i);
        }
        int ans = 0;
        for (int i = 1; i <= MX; ++i) {
            int cnt = g[i].size();
            for (int j = 1; j <= MX; ++j) {
                int mx = 0;
                for (int l = 0; 2 * l + 1 < g[i].size(); ++l) {
                    int r = g[i].size() - l - 1;
                    mx = max(mx, s[g[i][r] - 1][j] - s[g[i][l]][j] - (r - l - 1));
                }
                ans = max(ans, cnt + mx);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

/*
6
8
1 1 2 2 3 2 1 1
3
1 3 3
4
1 10 10 1
1
26
2
2 1
3
1 1 1
*/