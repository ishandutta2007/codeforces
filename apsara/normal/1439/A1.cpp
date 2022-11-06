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

int pre[1<<4];
void init() {
    memset(pre, -1, sizeof(pre));
    int Q[1<<4];
    pre[0] = 0;
    int top = 0, tail = 0;
    Q[++tail] = 0;
    while (top != tail) {
        int u = Q[++top];
        for (int i = 0; i < (1 << 4); ++i) {
            int cnt = 0;
            for (int j = 0; j < 4; ++j) if (i & (1 << j)) ++cnt;
            if (cnt != 3) continue;
            int v = u ^ i;
            if (pre[v] == -1) {
                pre[v] = u;
                Q[++tail] = v;
            }
        }
    }
}

int ans[100100][6], K;
int s[110][110];
void add(int x_1, int y_1, int x_2, int y_2, int x_3, int y_3) {
    s[x_1][y_1] ^= 1;
    s[x_2][y_2] ^= 1;
    s[x_3][y_3] ^= 1;
    ans[K][0] = x_1;
    ans[K][1] = y_1;
    ans[K][2] = x_2;
    ans[K][3] = y_2;
    ans[K][4] = x_3;
    ans[K][5] = y_3;
    K++;
}

void add4(int x, int y) {
    int u = 0;
    for (int i = 0; i < 2; ++i) for (int j = 0; j < 2; ++j) if (s[x + i][y + j] == 1) u ^= (1 << (i * 2 + j));
    while (u != 0) {
        int t = u ^ pre[u];
        vector<int> v;
        for (int i = 0; i < 2; ++i) for (int j = 0; j < 2; ++j) if (t & (1 << (i * 2 + j))) v.PB(x + i), v.PB(y + j);
        add(v[0], v[1], v[2], v[3], v[4], v[5]);
        u = pre[u];
    }
}
char mp[120][120];
int n, m, _;
int main() {
    init();
    scanf("%d", &_);
    while (_--) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i) scanf("%s", mp[i]);
        for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) s[i][j] = mp[i][j] - '0';
        K = 0;
        if (n % 2 == 1) {
            for (int i = 0; i < m; ++i) {
                if (s[n - 1][i] == 1) {
                    if (i != 0) add(n - 1, i, n - 2, i - 1, n - 2, i);
                    else add(n - 1, i, n - 2, i + 1, n - 2, i);
                }
            }
        }
        if (m % 2 == 1) {
            for (int i = 0; i < n; ++i) {
                if (s[i][m - 1] == 1) {
                    if (i != 0) add(i, m - 1, i - 1, m - 2, i, m - 2);
                    else add(i, m - 1, i + 1, m - 2, i, m - 2);
                }
            }
        }
        for (int i = 0; i < n; i += 2) for (int j = 0; j < m; j += 2) add4(i, j);
        printf("%d\n", K);
        for (int i = 0; i < K; ++i) {
            for (int j = 0; j < 6; ++j) printf("%d ", ans[i][j] + 1); puts("");
        }
        //for (int i = 0; i < n; ++i, puts("")) for (int j = 0; j < m; ++j) printf("%d ", s[i][j]);
    }
    return 0;
}

/*
5
2 2
10
11
3 3
011
101
110
4 4
1111
0110
0110
1111
5 5
01011
11001
00010
11011
10000
2 3
011
101
*/