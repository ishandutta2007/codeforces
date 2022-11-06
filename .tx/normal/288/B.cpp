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

int can = 0;
int a[11];

bool can1[11];
bool used[11];

bool check(int i) {
    if (i == 0) {
        return true;
    }
    if (can1[i]) {
        return true;
    }
    if (used[i]) {
        return false;
    }
    used[i] = true;
    can1[i] = check(a[i]);
    return can1[i];
}

void go(int v, int n) {
    if (v == n) {
        memset(can1, false, sizeof(bool) * n);
        memset(used, false, sizeof(bool) * n);
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (!check(i)) {
                ok = false;
                break;
            }
        }
        if (ok) {
            can++;
        }
        return;
    }
    for (int i = 0; i < n; i++) {
        if (v == 0 || i != v) {
            a[v] = i;
            go(v + 1, n);
        }
    }
}

const int mod = (int) 1e9 + 7;

int main() {
    sciid(n, k);
//    if (k == 1) {
//        cout << 0;
//        return 0;
//    }
    go(0, k);
    lint ans = can;
    for (int i = k + 1; i <= n; i++) {
        ans = ans * (n - k) % mod;
    }
    cout << ans;
    return 0;
}