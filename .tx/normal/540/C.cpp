#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>

#define sci(a) int a; scanf("%d", &a)
#define scii(a, b) int a, b; scanf("%d%d", &a, &b)
#define sciii(a, b, c) int a, b, c; scanf("%d%d%d", &a, &b, &c)

#define scig(a) scanf("%d", &a)
#define sciig(a, b) scanf("%d%d", &a, &b)
#define sciiig(a, b, c) scanf("%d%d%d", &a, &b, &c)

typedef long long lint;

using namespace std;

char a[555][555];
bool b[555][555];

int n, m;

bool isX(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m || a[i][j] == 'X') {
        return true;
    }
    return false;
}

int main() {
    sciig(n, m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", a[i]);
    }
    scii(r1, c1);
    scii(r2, c2);
    --r1; --r2; --c1; --c2;
    if (r1 != r2 || c1 != c2) {
        a[r1][c1] = '.';
    }

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    int cx = 0;
    for (int i = 0; i < 4; ++i) {
        if (isX(r2 + dx[i], c2 + dy[i])) {
            cx++;
        }
    }
    if (!isX(r2, c2) && cx >= 3) {
        cout << "NO";
        return 0;
    }
    a[r2][c2] = '.';

    queue< pair<int, int> > q;
    q.push({r1, c1});
    while (!q.empty()) {
        auto v = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int x = v.first + dx[i];
            int y = v.second + dy[i];
            if (!isX(x, y) && !b[x][y]) {
                b[x][y] = true;
                q.push({x, y});
            }
        }
    }
    cout << (b[r2][c2] ? "YES" : "NO");

    return 0;
}