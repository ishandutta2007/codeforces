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
const int dx[6] = {0,0,0,0,1,-1};
const int dy[6] = {0,0,1,-1,0,0};
const int dz[6] = {1,-1,0,0,0,0};

int k, n, m;
char a[15][15][15];
bool used[15][15][15];

int bfs(pair <pair <int, int>, int> start) {
    queue <pair < pair <int, int>, int> > q;
    q.push(start);
    used[start.first.first][start.first.second][start.second] = true;
    int res = 0;

    while (!q.empty()) {
        pair < pair <int, int>, int> cur = q.front();
        q.pop();
        ++res;
        for (int i = 0; i < 6; ++i) {
            pair <pair <int, int>, int> tmp = cur;
            tmp.first.first += dx[i];
            tmp.first.second += dy[i];
            tmp.second += dz[i];
            if ((tmp.first.first < 0) || (tmp.first.first == k))
                continue;
            if ((tmp.first.second < 0) || (tmp.first.second == n))
                continue;
            if ((tmp.sec < 0) || (tmp.sec == m))
                continue;
            if (used[tmp.first.first][tmp.first.second][tmp.second])
                continue;
            used[tmp.first.first][tmp.first.second][tmp.second] = true;
            q.push(tmp);
        }
    }
    return res;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    cin >> k >> n >> m;
    for (int i = 0; i < k; ++i)
        for (int j = 0; j < n; ++j)
            for (int z = 0; z < m; ++z) {
                char c;
                scanf(" %c ", &c);
                if (c == '#')
                    used[i][j][z] = true;
            }
    int x, y;
    cin >> x >> y;
    --x;
    --y;
    int ans = bfs(mp(mp(0, x), y));
    cout << ans << endl;
    return 0;
}