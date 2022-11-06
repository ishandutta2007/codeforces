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

int a[8][3];

lint dot(lint x1, lint y1, lint z1, lint x2, lint y2, lint z2) {
    return x1 * x2 + y1 * y2 + z1 * z2;
}

lint dist(lint x1, lint y1, lint z1, lint x2, lint y2, lint z2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2);
}

#define dd(x, y) dot(a[ms[x]][0] - a[i][0], a[ms[x]][1] - a[i][1], a[ms[x]][2] - a[i][2], a[ms[y]][0] - a[i][0], a[ms[y]][1] - a[i][1], a[ms[y]][2] - a[i][2])

bool check_cube() {
    lint min_dist = 1e18;
    for (int i = 0; i < 8; i++) {
        for (int j = i + 1; j < 8; j++) {
            min_dist = min(min_dist, dist(a[i][0], a[i][1], a[i][2], a[j][0], a[j][1], a[j][2]));
        }
    }

    for (int i = 0; i < 8; i++) {
        vector<int> ms;
        for (int j = 0; j < 8; j++) {
            if (dist(a[i][0], a[i][1], a[i][2], a[j][0], a[j][1], a[j][2]) == min_dist) {
                ms.push_back(j);
            }
        }
        if (ms.size() != 3) {
            return false;
        }
        if (dd(0, 1) != 0 || dd(0, 2) != 0 || dd(1, 2) != 0) {
            return false;
        }
    }
    return true;
}

int main() {
    for (int i = 0; i < 8; i++) {
        sciii(a[i][0], a[i][1], a[i][2]);
        sort(a[i], a[i] + 3);
    }

    do {
        if (check_cube()) {
            cout << "YES\n";
            for (int i = 0; i < 8; i++) {
                printf("%d %d %d\n", a[i][0], a[i][1], a[i][2]);
            }
            return 0;
        }

        int i = 1;
        while (i < 8 && !next_permutation(a[i], a[i] + 3)) {
            sort(a[i], a[i] + 3);
            i++;
        }
        if (i == 8) {
            break;
        }
    } while (true);

    cout << "NO";

    return 0;
}