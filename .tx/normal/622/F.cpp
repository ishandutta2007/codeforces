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

int mpow(lint a, int p, int mod) {
    lint res = 1;
    for (; p > 0; p >>= 1) {
        if (p & 1) {
            res = res * a % mod;
        }
        a = a * a % mod;
    }
    return res;
}

int back(int x) {
    return mpow(x, mod - 2, mod);
}

int y[1111111];

int fact[1111111];

int main() {
    sciid(n, k);
    lint s = 0;
    for (int i = 1; i <= k + 1; i++) {
        s = (s + mpow(i, k, mod)) % mod;
        y[i] = s;
    }
    if (n <= k + 1) {
        cout << y[n];
        return 0;
    }

    fact[0] = 1;
    for (int i = 1; i <= k + 1; i++) {
        fact[i] = 1LL * i * fact[i - 1] % mod;
    }

    lint ans = 0;

    lint t = 1;
    for (int i = 1; i <= k + 1; i++) {
        t = t * (n - i) % mod;
    }

    for (int i = 1; i <= k + 1; i++) {
        t = t * (n - i + 1) % mod * back(n - i) % mod;
        lint a = t * y[i] % mod * back(fact[i]) % mod;
        if (i <= k + 1) {
            if ((k + 1 - i) & 1) {
                a = a * -back(fact[k + 1 - i]) % mod;
                a = (a + mod) % mod;
            } else {
                a = a * back(fact[k + 1 - i]) % mod;
            }
        }
        ans = (ans + a) % mod;
    }

    cout << ans;

    return 0;
}