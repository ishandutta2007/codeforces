#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#include <memory.h>
#include <bitset>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rea(a, n) for (int i = 0; i < n; i++) sci(a[i])

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;
typedef long double ldouble;

using namespace std;

struct Item {
    int d, x, y;

    bool operator<(const Item &r) const {
        return d > r.d;
    }

};

vector<int> xs[333 * 333];
vector<int> ys[333 * 333];

int td[333][333];
int d[333][333];

int main() {
    sciiid(n, m, p);
    bool f1 = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scid(x);
            if (i == 0 && j == 0 && x == 1) {
                f1 = true;
            }
            xs[x].push_back(i);
            ys[x].push_back(j);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            td[i][j] = 1e9;
        }
    }
    td[0][0] = 0;
    xs[0].push_back(0);
    ys[0].push_back(0);

    int dx[4] = { 1, -1, 0, 0 };
    int dy[4] = { 0, 0, 1, -1 };

    for (int t = 1; t <= p; t++) {
        if (t == 2 && !f1) {
            td[0][0] = 1e9;
        }
        if (xs[t].size() * xs[t - 1].size() < n * m * 8) {
            for (int i = 0; i < xs[t].size(); i++) {
                int vx = xs[t][i];
                int vy = ys[t][i];
                for (int j = 0; j < xs[t - 1].size(); j++) {
                    int x = xs[t - 1][j];
                    int y = ys[t - 1][j];
                    td[vx][vy] = min(td[vx][vy], td[x][y] + abs(x - vx) + abs(y - vy));
                }
            }
        } else {
            priority_queue<Item> q;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    d[i][j] = 1e9;
                }
            }
            for (int i = 0; i < xs[t - 1].size(); i++) {
                int x = xs[t - 1][i];
                int y = ys[t - 1][i];
                q.push(Item{td[x][y], x, y});
                    d[x][y] = td[x][y];
                }

                while (!q.empty()) {
                    Item v = q.top();
                    q.pop();
                    for (int i = 0; i < 4; i++) {
                        int x = v.x + dx[i];
                        int y = v.y + dy[i];
                        if (x < 0 || x >= n || y < 0 || y >= m) {
                            continue;
                        }
                        if (d[x][y] > v.d + 1) {
                            d[x][y] = v.d + 1;
                            q.push(Item{d[x][y], x, y});
                        }
                    }
                }

                for (int i = 0; i < xs[t].size(); i++) {
                    int x = xs[t][i];
                    int y = ys[t][i];
                    td[x][y] = d[x][y];
                }
            }
        }

    cout << td[xs[p][0]][ys[p][0]];
}