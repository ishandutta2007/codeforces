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

int a[222][222];
bool inq[222][222];

int main() {
    sciid(n, t);
    a[100][100] = n;
    deque<int> q;
    q.push_back(100);
    q.push_back(100);
    inq[100][100] = true;

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};


    while (!q.empty()) {
        int vx = q.front(); q.pop_front();
        int vy = q.front(); q.pop_front();
        int ta = a[vx][vy] / 4;
        a[vx][vy] %= 4;
        inq[vx][vy] = false;
        for (int i = 0; i < 4; i++) {
            int x = vx + dx[i];
            int y = vy + dy[i];
            a[x][y] += ta;
            if (a[x][y] >= 4) {
                if (!inq[x][y]) {
                    q.push_back(x);
                    q.push_back(y);
                    inq[x][y] = true;
                }
            }
        }
    }

    while (t-- > 0) {
        sciid(x, y);
        if (x < -100 || x > 100 || y < -100 || y > 100) {
            cout << "0\n";
            continue;
        }
        cout << a[100 + x][100 + y] << "\n";
    }

    return 0;
}