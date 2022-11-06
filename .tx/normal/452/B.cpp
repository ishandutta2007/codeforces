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

int main() {
    sciid(n, m);
    if (n == 0) {
        cout << 0 << " " << 1 << "\n";
        cout << 0 << " " << m << "\n";
        cout << 0 << " " << 0 << "\n";
        cout << 0 << " " << m - 1 << "\n";
        return 0;
    }
    if (m == 0) {
        cout << 1 << " " << 0 << "\n";
        cout << n << " " << 0 << "\n";
        cout << 0 << " " << 0 << "\n";
        cout << n - 1 << " " << 0 << "\n";
        return 0;
    }
    double l1 = 2 * sqrt(n * n + m * m) + max(n, m);
    double l2 = sqrt(n * n + m * m) + 2 * sqrt(max(n, m) * max(n, m) + (min(n, m) - 1) * (min(n, m) - 1));
    if (l1 > l2) {
        cout << 0 << " " << 0 << "\n";
        cout << n << " " << m << "\n";
        if (n > m) {
            cout << 0 << " " << m << "\n";
            cout << n << " " << 0 << "\n";
        } else {
            cout << n << " " << 0 << "\n";
            cout << 0 << " " << m << "\n";
        }
        return 0;
    }
    if (n > m) {
        cout << 0 << " " << 1 << "\n";
        cout << n << " " << m << "\n";
        cout << 0 << " " << 0 << "\n";
        cout << n << " " << m - 1 << "\n";
    } else {
        cout << n - 1 << " " << m << "\n";
        cout << 0 << " " << 0 << "\n";
        cout << n << " " << m << "\n";
        cout << 1 << " " << 0 << "\n";
    }

    return 0;
}