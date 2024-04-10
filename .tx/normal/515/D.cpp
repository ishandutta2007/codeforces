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
#include <fstream>

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

char a[2222][2222];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int getDeg(int x, int y) {
    if (a[x][y] != '.') {
        return -1;
    }
    int res = 0;
    for (int i = 0; i < 4; i++) {
        if (a[x + dx[i]][y + dy[i]] == '.') {
            res++;
        }
    }
    return res;
}

int main() {
    init_cin
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= m + 1; j++) {
            a[i][j] = '*';
        }
    }
    int cf = 0;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            a[i][j + 1] = s[j];
            if (s[j] == '.') {
                cf++;
            }
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (getDeg(i, j) == 1) {
                q.push(i);
                q.push(j);
            }
        }
    }

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        int y = q.front();
        q.pop();
        if (a[x][y] != '.') {
            continue;
        }
        int nx = x, ny = y;
        if (a[x + 1][y] == '.') {
            a[x][y] = '^';
            a[x + 1][y] = 'v';
            nx++;
        } else if (a[x - 1][y] == '.') {
            a[x][y] = 'v';
            a[x - 1][y] = '^';
            nx--;
        } else if (a[x][y + 1] == '.') {
            a[x][y] = '<';
            a[x][y + 1] = '>';
            ny++;
        } else {
            a[x][y] = '>';
            a[x][y - 1] = '<';
            ny--;
        }
        cf -= 2;
        for (int i = 0; i < 4; i++) {
            if (getDeg(nx + dx[i], ny + dy[i]) == 1) {
                q.push(nx + dx[i]);
                q.push(ny + dy[i]);
            }
        }
    }

    if (cf != 0) {
        cout << "Not unique";
    } else {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cout << a[i][j];
            }
            cout << "\n";
        }
    }

    return 0;
}