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

char ans[1111][1111];

void edge(int x, int y) {
    ans[x][y] = ans[y][x] = 'Y';
}

int main() {
    scid(k);
    int c = 2;
    int b = 999;
    for (int i = 0; i < 30; i++) {
        edge(b, b - 1);
        edge(b - 1, b - 2);
        b = b - 2;
    }
    edge(b, 1);
    edge(0, 2);
    for (int p = 0; p <= 30; p++) {
        if (k & (1 << p)) {
            edge(c, 999 - 2 * p);
        }
        edge(c, c + 1);
        edge(c, c + 2);
        edge(c + 1, c + 3);
        edge(c + 2, c + 3);
        c = c + 3;
    }
    cerr << c << endl;

    int n = 1000;
    cout << n << "\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << (ans[i][j] == 'Y' ? 'Y' : 'N');
        }
        cout << "\n";
    }

    return 0;
}