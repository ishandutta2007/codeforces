#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <memory.h>

#define scid(a) int a; scanf("%d", &a)
#define sciid(a, b) int a, b; scanf("%d%d", &a, &b)
#define sciidm(a, b) int a, b; scanf("%d%d", &a, &b); if (a > b) swap(a, b)
#define sciiid(a, b, c) int a, b, c; scanf("%d%d%d", &a, &b, &c)

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define rveid(a, n) vector<int> a(n); for (int i = 0; i < n; i++) sci(a[i])
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

typedef long long lint;

using namespace std;

void init_cin() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

int main() {
    sciidm(x1, y1);
    sciidm(x2, y2);
    sciidm(x3, y3);
    int sq = x1 * y1 + x2 * y2 + x3 * y3;
    int a = (int) floor(sqrt(sq));
    if (a * a != sq) {
        cout << -1;
        return 0;
    }
    if (y1 != a && y2 != a && y3 != a) {
        cout << -1;
        return 0;
    }
    char r[3] = {'A', 'B', 'C'};
    if (y2 == a) {
        swap(x1, x2);
        swap(y1, y2);
        swap(r[0], r[1]);
    }
    if (y3 == a) {
        swap(x1, x3);
        swap(y1, y3);
        swap(r[0], r[2]);
    }
    if (y1 == a && y2 == a && y3 == a) {
        if (x1 + x2 + x3 != a) {
            cout << -1;
            return 0;
        }
        cout << a << "\n";
        for (int i = 0; i < x1; i++) {
            for (int j = 0; j < a; j++) {
                cout << r[0];
            }
            cout << "\n";
        }
        for (int i = 0; i < x2; i++) {
            for (int j = 0; j < a; j++) {
                cout << r[1];
            }
            cout << "\n";
        }
        for (int i = 0; i < x3; i++) {
            for (int j = 0; j < a; j++) {
                cout << r[2];
            }
            cout << "\n";
        }
        return 0;
    }
    if (x1 + x2 != a && x1 + y2 != a) {
        cout << -1;
        return 0;
    }
    if (x1 + y2 == a) {
        swap(x2, y2);
    }
    if (x1 + x3 != a && x1 + y3 != a) {
        cout << -1;
        return 0;
    }
    if (x1 + y3 == a) {
        swap(x3, y3);
    }
    if (y2 + y3 != a) {
        cout << -1;
        return 0;
    }
    cout << a << "\n";
    for (int i = 0; i < x1; i++) {
        for (int j = 0; j < a; j++) {
            cout << r[0];
        }
        cout << "\n";
    }
    for (int i = x1; i < a; i++) {
        for (int j = 0; j < a; j++) {
            if (j < y2) {
                cout << r[1];
            } else {
                cout << r[2];
            }
        }
        cout << "\n";
    }

    return 0;
}