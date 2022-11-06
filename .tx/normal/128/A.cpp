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

char a[11][11][11];
bool w[11][11][11];

queue<int> q;

void pq(int a, int b, int c) {
    q.push(a);
    q.push(b);
    q.push(c);
    w[a][b][c] = true;
}

void rq(int& a, int& b, int& c) {
    a = q.front();
    q.pop();
    b = q.front();
    q.pop();
    c = q.front();
    q.pop();
}

int main() {
    for (int i = 0; i < 8; i++) {
        scanf("%s", a[0][i]);
    }
    for (int p = 1; p <= 8; p++) {
        for (int i = 0; i < 8; i++) {
            a[p][0][i] = '.';
        }
        for (int i = 1; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                a[p][i][j] = a[p - 1][i - 1][j];
            }
        }
    }

    pq(0, 7, 0);
    while (!q.empty()) {
        int p, x, y;
        rq(p, x, y);
        int np = min(p + 1, 8);
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int nx = x + i;
                int ny = y + j;
                if (nx < 0 || nx >= 8 || ny < 0 || ny >= 8 || a[np][nx][ny] == 'S' || a[p][nx][ny] == 'S' || w[np][nx][ny]) {
                    continue;
                }
                pq(np, nx, ny);
            }
        }
    }

    for (int i = 0; i <= 8; i++) {
        if (w[i][0][7]) {
            cout << "WIN";
            return 0;
        }
    }
    cout << "LOSE";

    return 0;
}