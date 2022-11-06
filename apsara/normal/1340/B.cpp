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
const int V = 2100;
const int N = 7;

int cal(string s) {
    int res = 0;
    for (int i = 0; i < N; ++i) {
        if(s[i] == '1') res |= (1 << i);
    }
    return res;
}

char ss[V][10];
int d[10], cnt[1<<N], s[V];
int ok[V][V];
int n, m;
int dfs(int x, int y) {
    if (ok[x][y] != -1) return ok[x][y];
    if (x == 0) return false;
    ok[x][y] = 0;
    for (int i = 9; i >= 0; --i) {
        if ((s[n - x] & d[i]) != s[n - x]) continue;
        int nd = cnt[d[i]] - cnt[s[n - x]];
        if (nd > y) continue;
        if (dfs(x - 1, y - nd)) ok[x][y] = 1;
    }
    //printf("%d %d %d\n", x, y, ok[x][y]);
    return ok[x][y];
}

int main() {
    for (int i = 0; i < (1 << N); ++i) {
        cnt[i] = 0;
        for (int j = 0; j < N; ++j) {
            if (i & (1 << j)) cnt[i]++;
        }
    }
    //"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"
    d[0] = cal("1110111");
    d[1] = cal("0010010");
    d[2] = cal("1011101");
    d[3] = cal("1011011");
    d[4] = cal("0111010");
    d[5] = cal("1101011");
    d[6] = cal("1101111");
    d[7] = cal("1010010");
    d[8] = cal("1111111");
    d[9] = cal("1111011");
    //for (int i = 0; i < 10; ++i) printf("%d %d\n", i, cnt[d[i]]);
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 0; i < n; ++i) scanf("%s", ss[i]);
        for (int i = 0; i < n; ++i) {
            s[i] = 0;
            for (int j = 0; j < N; ++j) {
                if(ss[i][j] == '1') s[i] |= (1 << j);
            }
        }
        memset(ok, -1, sizeof(ok));
        ok[0][0] = 1;
        int ans = dfs(n, m);
        if (ans == 0) {
            puts("-1");
        } else {
            int ny = m;
            for (int nx = n; nx > 0; --nx) {
                for (int i = 9; i >= 0; --i) {
                    if ((s[n - nx] & d[i]) != s[n - nx]) continue;
                    int nd = cnt[d[i]] - cnt[s[n - nx]];
                    //printf("%d %d %d %d\n", nx, ny, i, nd);
                    if (nd > ny) continue;
                    if (dfs(nx - 1, ny - nd)) {
                        printf("%c", '0' + i);
                        ny -= nd;
                        break;
                    }
                }
            }
            puts("");
        }
    }
    return 0;
}

/*
1 7
0000000
2 5
0010010
0010010
3 5
0100001
1001001
1010011
*/