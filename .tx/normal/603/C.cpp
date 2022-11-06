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

int k;

int mex(int a, int b) {
    if (min(a, b) > 0) {
        return 0;
    }
    if (max(a, b) == 1) {
        return 2;
    }
    return 1;
}

int mex(int a) {
    return a == 0 ? 1 : 0;
}

int st[2][7] = {{0, 1, 2, 0, 1, 0, 1}, {0, 1, 0, 1, 2, 0, 2}};

int g(int x) {
    if (x <= 6) {
        return st[k % 2][x];
    }
    if (k & 1) {
        if (x & 1) {
            return 0;
        }
        return mex(0, g(x / 2));
    }
    return 1 - x % 2;
}

int main() {
    scid(n);
    sci(k);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        scid(x);
        ans ^= g(x);
    }
    puts(ans ? "Kevin" : "Nicky");
    return 0;
}