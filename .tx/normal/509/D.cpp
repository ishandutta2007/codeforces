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

template<typename T>
T gcd(T a, T b) {
    return b == 0 ? a : gcd(b, a % b);
}

lint w[111][111];

lint a[111];
lint b[111];

int main() {
    sciid(n, m);
    lint mx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scid(x);
            w[i][j] = x;
            mx = max(mx, (lint) x);
        }
    }
    for (int i = 0; i < m; i++) {
        b[i] = w[0][i];
    }
    for (int i = 0; i < n; i++) {
        a[i] = w[i][0] - b[0];
    }
    lint g = 1e18;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            lint e = abs(a[i] + b[j] - w[i][j]);
            if (e != 0) {
                g = g == 1e18 ? e : gcd(g, e);
            }
        }
    }
    if (g <= mx) {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    cout << g << "\n";

    for (int i = 0; i < n; i++) {
        cout << (a[i] % g + g) % g << " ";
    }
    cout << "\n";
    for (int i = 0; i < m; i++) {
        cout << b[i] << " ";
    }

    return 0;
}