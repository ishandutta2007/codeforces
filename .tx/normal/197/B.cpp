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

int a[111], b[111];

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    sciid(n, m);
    for (int i = 0; i <= n; i++) {
        sci(a[i]);
    }
    for (int j = 0; j <= m; j++) {
        sci(b[j]);
    }
    if (n < m) {
        cout << "0/1";
    } else if (n > m) {
        cout << (a[0] * b[0] > 0 ? "Infinity" : "-Infinity");
    } else {
        int g = gcd(abs(a[0]), abs(b[0]));
        if (a[0] * b[0] < 0) {
            cout << "-";
        }
        cout << abs(a[0]) / g << "/" << abs(b[0]) / g;
    }

    return 0;
}