#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>

using namespace std;

#define pb push_back
#define mp make_pair
#define fir first
#define fi first
#define sec second
#define y1 botva23
typedef long long int64;
typedef long double ld;

const int inf = 2000000000;
const ld eps = 1e-07;
const int dx[4] = {0,0,1,-1};
const int dy[4] = {1,-1,0,0};

int n, m;
int a[2000][2000];
pair <int, int> start, _end;
int d[2000][2000];

void bfs(pair <int, int> start) {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            d[i][j] = inf;

    d[start.first][start.second] = 0;
    queue <pair <int, int> > q;
    q.push(start);
    while (!q.empty()) {
        pair <int, int> cur = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            if (!((cur.first + dx[i]) >= 0))
                continue;
            if (!((cur.first + dx[i]) < n))
                continue;
            if (!((cur.second + dy[i]) >= 0))
                continue;
            if (!((cur.second + dy[i]) < m))
                continue;
            if (!(a[cur.first + dx[i]][cur.second + dy[i]] != -1))
                continue;
            if (d[cur.first + dx[i]][cur.second + dy[i]] != inf)
                continue;
            d[cur.first + dx[i]][cur.second + dy[i]] = d[cur.first][cur.second] + 1;
            q.push(mp(cur.first + dx[i], cur.second + dy[i]));
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c;
            scanf(" %c ", &c);
            if (c == 'S') {
                start = mp(i, j);
                a[i][j] = 0;
            }
            if (c == 'E') {
                _end = mp(i, j);
                a[i][j] = 0;
            }
            if (c == 'T') {
                a[i][j] = -1;
            }
            if ((c >= '0') && (c <= '9')) {
                a[i][j] = int(c) - int('0');
            }
        }
    }
    bfs(_end);
    int res = 0;
    int min = d[start.first][start.second];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if ((a[i][j] >= 0) && (d[i][j] <= min)) {
                res += a[i][j];
            }
    cout << res << endl;
    return 0;
}