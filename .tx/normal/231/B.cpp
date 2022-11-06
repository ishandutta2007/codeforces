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

void solvePos(int n, int d, int l) {
    int mx = (n + 1) / 2 * l - n / 2;
    if (mx < d) {
        cout << -1;
        return;
    }
    d -= (n + 1) / 2 - n / 2;
    for (int i = 0; i < n; i++) {
        if (i & 1) {
            cout << 1;
        } else {
            int t = min(d, l - 1);
            cout << 1 + t;
            d -= t;
        }
        cout << " ";
    }
}

void solveNeg(int n, int d, int l) {
    int mn = -n / 2 * l + (n + 1) / 2;
    if (mn > d) {
        cout << -1;
        return;
    }
    d -= (n + 1) / 2 - n / 2;
    d = -d;
    for (int i = 0; i < n; i++) {
        if (i & 1) {
            int t = min(d, l - 1);
            cout << 1 + t;
            d -= t;
        } else {
            cout << 1;
        }
        cout << " ";
    }
}

int main() {
    sciiid(n, d, l);
//    if (d == 0) {
//        if (n & 1) {
//            cout << -1;
//        } else {
//            for (int i = 0; i < n; i++) {
//                cout << "1 ";
//            }
//        }
//        return 0;
//    }
    if (d > 0) {
        solvePos(n, d, l);
    } else {
        solveNeg(n, d, l);
    }

    return 0;
}