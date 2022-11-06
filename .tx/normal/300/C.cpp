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

int mod = 1e9 + 7;

int mpow(int a, int p) {
    lint res = 1;
    for (; p > 0; p >>= 1) {
        if (p & 1) {
            res = res * a % mod;
        }
        a = 1LL * a * a % mod;
    }
    return res;
}

lint fc[1111111];
lint bfc[1111111];

bool isGood(int x, int a, int b) {
    while (x) {
        int c = x % 10;
        if (c != a && c != b) {
            return false;
        }
        x /= 10;
    }
    return true;
}

int main() {
    sciiid(a, b, n);
    fc[0] = 1;
    for (int i = 1; i <= n; i++) {
        fc[i] = fc[i - 1] * i % mod;
    }
//    for (int i = 0; i <= n; i++) {
//        bfc[i] = mpow(fc[i], mod - 2);
//    }

    lint ans = 0;
    for (int i = 0; i <= n; i++) {
        int s = i * a + (n - i) * b;
        if (isGood(s, a, b)) {
            ans += fc[n] * mpow(fc[i] * fc[n - i] % mod, mod - 2);
            ans %= mod;
        }
    }

    cout << ans;
    return 0;
}