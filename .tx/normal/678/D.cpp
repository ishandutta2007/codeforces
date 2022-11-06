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

const lint mpow(lint a, lint p) {
    if (p == 0) {
        return 1;
    }
    lint t = mpow(a, p >> 1);
    t = t * t % mod;
    if (p & 1) {
        t = t * a % mod;
    }
    return t;
}

int main() {
    init_cin
    lint a, b, n, x;
    cin >> a >> b >> n >> x;
    if (a == 1) {
        cout << (n % mod * b + x) % mod;
        return 0;
    }

    lint i = mpow(a, n) * x;
    lint j = b * ((mpow(a, n) - 1 + mod) % mod) % mod * (mpow(a - 1, mod - 2)) % mod;
//    cerr << i << " " << j << endl;
    cout << (i + j) % mod;

    return 0;
}