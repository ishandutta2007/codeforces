#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#include <memory.h>
#include <bitset>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rea(a, n) for (int i = 0; i < n; i++) sci(a[i])

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;
typedef long double ldouble;

using namespace std;

const int mod = 1e9 + 7;

int pow(int a, int p) {
    int r = 1;
    for (; p; p >>= 1) {
        if (p & 1) {
            r = 1LL * r * a % mod;
        }
        a = 1LL * a * a % mod;
    }
    return r;
}

int main() {
    scid(n);
    lint ans = 1;
    for (int i = 0; i < n; i++) {
        ans = 2 * ans + 1;
        ans %= mod;
    }
    lint c = 1;
    int lst = pow(2, n);
    for (int i = 0; i < n; i++) {
        int nx = ((lst * 2 - 2 * c) % mod + mod) % mod;
//        cerr << c << " " << nx << endl;
        c = c * (n + i + 1) % mod * pow(i + 1, mod - 2) % mod;
        ans = (ans + nx) % mod;
        lst = nx;
    }
    cout << ans;

    return 0;
}