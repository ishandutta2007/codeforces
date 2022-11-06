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
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).end()

typedef long long lint;

using namespace std;

void init_cin() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

lint ans = -1;

void fine(lint x) {
    for (lint i = 2; i * i <= x; i++) {
        if (x % (i * i) == 0) {
            return;
        }
    }
    ans = max(ans, x);
}

int main() {
    lint n;
    cin >> n;
    for (lint i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            fine(i);
            fine(n / i);
        }
    }
    cout << ans;

    return 0;
}