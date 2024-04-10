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

bool g[555][555];
int cc[555];

int n;

void dfs(int v, int p, int c) {
    cc[v] = c;
    for (int i = 0; i < n; i++) {
        if (i == p || g[v][i] || i == v) {
            continue;
        }
        if (cc[i] == -1) {
            dfs(i, v, 1 - c);
        } else if (cc[i] == c) {
            cout << "No";
            exit(0);
        }
    }
}

bool nb[555];

char s[555];

int main() {
    sci(n);
    scid(m);
    for (int i = 0; i < m; i++) {
        sciid(x, y);
        --x; --y;
        g[x][y] = g[y][x] = true;
    }

    memset(cc, -1, sizeof(cc));

    for (int i = 0; i < n; i++) {
        int ce = 0;
        for (int j = 0; j < n; j++) {
            if (g[i][j]) {
                ce++;
            }
        }
        if (ce == n - 1) {
            s[i] = 'b';
            continue;
        }
        if (s[i] == 0) {
            s[i] = 'a';
        }
        for (int j = 0; j < n; j++) {
            if (i != j && !g[i][j]) {
                if (s[j] == 0) {
                    s[j] = (s[i] == 'a' ? 'c' : 'a');
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            if (g[i][j] && abs(s[i] - s[j]) > 1) {
                cout << "No";
                return 0;
            }
            if (!g[i][j] && abs(s[i] - s[j]) <= 1) {
                cout << "No";
                return 0;
            }
        }
    }

    cout << "Yes\n";
    puts(s);


    return 0;
}