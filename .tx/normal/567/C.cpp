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

typedef long long lint;

using namespace std;

void init_cin() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

int main() {
    sciid(n, k);
    map<lint, lint> m[3];
    for (int i = 0; i < n; i++) {
        scid(x);
        if (x % k == 0) {
            m[2][x] += m[1][x / k];
            m[1][x] += m[0][x / k];
        }
        m[0][x]++;
    }
    lint ans = 0;
    for (auto i : m[2]) {
        ans += i.second;
    }
    cout << ans;
    return 0;
}