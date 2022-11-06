#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <string>
#include <memory.h>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rvei(a, n) for (int i = 0; i < n; i++) sci(a[i])
#define rveid(a, n) vector<int> a(n); rvei(a, n)

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;

using namespace std;

char s[11];
string pad[4];
int n;

pair<int, int> p[11];

bool check(int x, int y) {
    if (x < 0 || x >= 4 || y < 0 || y >= 3 || pad[x][y] == ' ') {
        return false;
    }
    return true;
}

bool ok(int sx, int sy) {
    if (!check(sx, sy)) {
        return false;
    }

    for (int i = 1; i < n; i++) {
        sx += p[i].first - p[i - 1].first;
        sy += p[i].second - p[i - 1].second;
        if (!check(sx, sy)) {
            return false;
        }
    }

    return true;
}


int main() {
    pad[0] = "123";
    pad[1] = "456";
    pad[2] = "789";
    pad[3] = " 0 ";

    sci(n);
    scanf("\n%s", s);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 3; k++) {
                if (pad[j][k] == s[i]) {
                    p[i] = {j, k};
                }
            }
        }
    }

    int kok = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            if (ok(i, j)) {
                kok++;
            }
        }
    }

    if (kok == 1) {
        cout << "YES";
    } else {
        cout << "NO";
    }


    return 0;
}