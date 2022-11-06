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

int m[100][100];
int a[100];

int t[100][100];

const int mod = 1e9 + 7;

void mulm(int a[100][100], int b[100][100]) {
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            t[i][j] = 0;
            for (int k = 0; k < 100; k++) {
                t[i][j] = (t[i][j] + 1LL * a[i][k] * b[k][j]) % mod;
            }
        }
    }
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            a[i][j] = t[i][j];
        }
    }
}

int r[100][100];

void pow(int p) {
    for (; p > 0; p >>= 1) {
        if (p & 1) {
            mulm(r, m);
        }
        mulm(m, m);
    }
}

int main() {
    scid(n);
    sciiid(b, k, x);
    for (int i = 0; i < n; i++) {
        scid(t);
        a[t % x]++;
    }
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            m[i][j] = a[(i - j * 10 + 10 * x) % x];
        }
    }

    for (int i = 0; i < x; i++) {
        r[i][i] = 1;
    }

    pow(b);

    cout << r[k][0];

    return 0;
}