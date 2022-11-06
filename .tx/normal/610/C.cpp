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

int** createArray(int n, int m) {
    int** res = new int*[n];
    for (int i = 0; i < n; i++) {
        res[i] = new int[m];
    }
    return res;
}

int** get(int k) {
    if (k == 0) {
        int** r = createArray(1, 1);
        r[0][0] = 1;
        return r;
    }
    int** t = get(k - 1);
    int** r = createArray(1 << k, 1 << k);
    for (int i = 0; i < 1 << (k - 1); i++) {
        for (int j = 0; j < (1 << k); j++) {
            r[i][j] = t[i][j & ((1 << (k - 1)) - 1)];
        }
    }
    for (int i = 1 << (k - 1); i < (1 << k); i++) {
        for (int j = 0; j < (1 << k); j++) {
            r[i][j] = t[i & ((1 << (k - 1)) - 1)][j & ((1 << (k - 1)) - 1)] ^ (j >= (1 << (k - 1)));
        }
    }
    return r;
}

int main() {
    scid(k);
    int** a = get(k);
    for (int i = 0; i < (1 << k); i++) {
        for (int j = 0; j < (1 << k); j++) {
            cout << (a[i][j] == 1 ? "+" : "*");
        }
        cout << "\n";
    }

    return 0;
}