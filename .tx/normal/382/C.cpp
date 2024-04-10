#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <memory.h>

#define scid(a) int a; scanf("%d", &a)
#define sciid(a, b) int a, b; scanf("%d%d", &a, &b)
#define sciiid(a, b, c) int a, b, c; scanf("%d%d%d", &a, &b, &c)

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define rveid(a, n) vector<int> a(n); for (int i = 0; i < n; i++) sci(a[i])

typedef long long lint;

using namespace std;

void init_cin() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

void ans(int x) {
    cout << x;
    exit(0);
}

void ans(int x, int y) {
    cout << x << "\n" << y;
    exit(0);
}

void ans(int x, int y, int z) {
    cout << x << "\n" << y << " " << z;
    exit(0);
}

void ans(int x, int y, int z, int k) {
    cout << x << "\n" << y << " " << z << " " << k;
    exit(0);
}

int main() {
    scid(n);
    rveid(a, n);
    sort(a.begin(), a.end());
    if (n == 1) {
        ans(-1);
    }
    if (a[0] == a[n - 1]) {
        ans(1, a[0]);
    }
    if (n == 2) {
        if (a[1] == a[0]) {
            ans(1, a[0]);
        }
        if ((a[1] + a[0]) % 2 == 0) {
            ans(3, a[0] - a[1] + a[0], (a[1] + a[0]) / 2, a[1] + a[1] - a[0]);
        }
        ans(2, a[0] - a[1] + a[0], a[1] + a[1] - a[0]);
    }
    map<int, int> m;
    for (int i = 0; i + 1 < n; i++) {
        m[a[i + 1] - a[i]]++;
    }
    if (m.size() == 1) {
        ans(2, a[0] - a[1] + a[0], a[n - 1] + a[1] - a[0]);
    }
    if (m.size() > 2) {
        ans(0);
    }
    auto it = m.begin();
    pair<int, int> a1 = *it;
    pair<int, int> a2 = *(++it);
    if (a1.first > a2.first) {
        swap(a1, a2);
    }
    if (a1.first * 2 != a2.first) {
        ans(0);
    }
    if (a2.second != 1) {
        ans(0);
    }
    int d = a2.first;
    for (int i = 0; i + 1 < n; i++) {
        if (a[i + 1] - a[i] == d) {
            ans(1, (a[i + 1] + a[i]) / 2);
        }
    }
    return 0;
}