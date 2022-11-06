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

char a[2][111111];
int d[2][222222];

int main() {
    sciid(n, k);
    scanf("\n%s", a[0]);
    scanf("\n%s", a[1]);
    queue<pair<int, int> > q;
    q.push({0, 0});
    int dx[3] = {0, 0, 1};
    int dy[3] = {1, -1, k};

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 222222; j++) {
            d[i][j] = 1e9;
        }
    }
    d[0][0] = 0;

    while (!q.empty()) {
        auto v = q.front();
        q.pop();
        int cw = v.first;
        int ch = v.second;
        if (ch >= n) {
            cout << "YES";
            return 0;
        }
        if (ch < d[cw][ch]) {
            continue;
        }
        for (int i = 0; i < 3; i++) {
            int x = cw ^ dx[i];
            int y = ch + dy[i];
            if (y < 0 || y >= 222222 || (y < n && a[x][y] == 'X')) {
                continue;
            }
            if (d[x][y] > d[cw][ch] + 1) {
                d[x][y] = d[cw][ch] + 1;
                q.push({x, y});
            }
        }
    }

    cout << "NO";
    return 0;
}