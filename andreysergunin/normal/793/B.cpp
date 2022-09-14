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
typedef pair<int, int> pii;
mt19937 rr(random_device{}());

const int INF = 1e9 + 100;
const int MAXN = 1010;

vector<int> dx = {0, -1, 0, 1};
vector<int> dy = {-1, 0, 1, 0};
int n, m;
vector<string> b;

int sx, sy;
int tx, ty;

bool used[MAXN][MAXN][4][4];

bool inBoard(int x, int y) {
    return (0 <= x && x < n && 0 <= y && y < m);
}

bool dfs(int x, int y, int d, int k) {
    if (k > 2)
        return false;

    if (x == tx && y == ty) 
        return true;

    used[x][y][d][k] = 1;
    for (int i = 0; i < 4; ++i) {
        int x1 = x + dx[i];
        int y1 = y + dy[i];
        int k1 = k + (i == d ? 0 : 1);
        if (inBoard(x1, y1) && b[x1][y1] != '*' && used[x1][y1][i][k1] == 0) {
            if (dfs(x1, y1, i, k1))
                return true;
        }
    }
    return false;
}

int main() {
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    b.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        for (int j = 0; j < m; ++j) {
            if (b[i][j] == 'S') {
                sx = i;
                sy = j;
            }
            if (b[i][j] == 'T') {
                tx = i;
                ty = j;
            }
        }
    }
 
    for (int i = 0; i < 4; ++i) {
        if (dfs(sx, sy, i, 0)) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}