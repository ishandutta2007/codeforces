#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#include <memory.h>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rea(a, n) for (int i = 0; i < n; i++) sci(a[i])

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;

using namespace std;

char a[1111][1111];
int d[3][1111][1111];

bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

int main() {
    int n, m;
    scanf("%d %d\n", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", a[i]);
        for (int j = 0; j < m; j++) {
            d[0][i][j] = d[1][i][j] = d[2][i][j] = 1e9;
        }
    }
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    for (int g = 0; g < 3; g++) {
        deque<int> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] - '1' == g) {
                    d[g][i][j] = 0;
                    q.push_back(i);
                    q.push_back(j);
                }
            }
        }
        while (!q.empty()) {
            int vx = q.front();
            q.pop_front();
            int vy = q.front();
            q.pop_front();
            for (int i = 0; i < 4; i++) {
                int x = vx + dx[i];
                int y = vy + dy[i];
                if (x < 0 || x >= n || y < 0 || y >= m || a[x][y] == '#') {
                    continue;
                }
                int cost = isDigit(a[x][y]) ? 0 : 1;
                if (d[g][x][y] > d[g][vx][vy] + cost) {
                    d[g][x][y] = d[g][vx][vy] + cost;
                    if (cost == 0) {
                        q.push_front(y);
                        q.push_front(x);
                    } else {
                        q.push_back(x);
                        q.push_back(y);
                    }
                }
            }
        }
    }
    int ans = 1e9;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int l1 = d[0][i][j];
            int l2 = d[1][i][j];
            int l3 = d[2][i][j];
            if (l1 != 1e9 && l2 != 1e9 && l3 != 1e9) {
                ans = min(ans, l1 + l2 + l3 + (a[i][j] == '.' ? -2 : 0));
            }
        }
    }

    cout << (ans == 1e9 ? -1 : ans);

    return 0;
}