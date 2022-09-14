#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <cassert>
#include <unordered_map>
#include <fstream>
#include <random>
#include <cstring>
#include <complex>
#include <bitset>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
mt19937 rr(random_device{}());

int n, m;
vector<vector<int>> board;
vector<vector<int>> dist;

vector<int> dx = {1, 0, 0, -1};
vector<int> dy = {0, -1, 1, 0};
vector<char> c = {'D', 'L', 'R', 'U'};

bool inBoard(int x, int y) {
    return (0 <= x && x < n && 0 <= y && y < m);
}

void bfs(int sx, int sy) {
    dist.resize(n, vector<int>(m, -1));
    queue<int> q;
    q.push(sx);
    q.push(sy);
    dist[sx][sy] = 0;
    while (sz(q) > 0) {
        int x = q.front(); q.pop();
        int y = q.front(); q.pop();
        for (int i = 0; i < 4; ++i) {
            int xx = x + dx[i];
            int yy = y + dy[i];

            if (inBoard(xx, yy) && !board[xx][yy] && dist[xx][yy] == -1)  {
                q.push(xx);
                q.push(yy);
                dist[xx][yy] = dist[x][y] + 1;
            }
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin)p;
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int k;
    cin >> n >> m >> k;
    if (k & 1) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    board.resize(n, vector<int>(m));
    int x = 0, y = 0;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            board[i][j] = (s[j] == '*' ? 1 : 0);
            if (s[j] == 'X') {
                x = i;
                y = j;
            }
        }
    }

    bfs(x, y);

    string res;
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < 4; ++j) {
            int xx = x + dx[j];
            int yy = y + dy[j];
            if (inBoard(xx, yy) && !board[xx][yy] && dist[xx][yy] < k - i) {
                res += c[j];
                x = xx;
                y = yy;
                break;
            }
        }
    }

    if (sz(res) != k) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    cout << res << endl;

}