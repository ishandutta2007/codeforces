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

const int mod = 1e6 + 3;

lint mpow(lint a, lint p) {
    lint res = 1;
    a %= mod;
    for (; p > 0; p >>= 1) {
        if (p & 1) {
            res = res * a % mod;
        }
        a = a * a % mod;
    }
    return res;
}

int main() {
    init_cin
    lint n, k;
    cin >> n >> k;
    if (n < 63 && k > (1LL << n)) {
        cout << 1 << " " << 1;
        return 0;
    }

    if (k > mod + 31) {
        lint k2 = 0;
        for (int i = 1; i < 63; i++) {
            k2 += (k - 1) / (1LL << i);
        }
        lint x = mpow(mpow(2, n), k - 1) * mpow(mpow(2, k2), mod - 2) % mod;
        cout << x << " " << x << endl; //
//        int mod1 = mod - 1;
//        for (int i = max(-10000LL, -k2); i <= 10000; i++) {
//            x = mpow(2, ((n % mod1 * ((k - 1) % mod1) % mod1 - k2 + i) % mod1 + mod1) % mod1);
//            x = mpow(mpow(2, n), k - 1) * mpow(mpow(2, k2 + i), mod - 2) % mod;
//            cout << x << " " << x << endl;
//            if (x == 906300) {
//            if (x == 365451) {
//            if (x == 56848) {
//                cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << " " << i << endl;
//            }
//        }
        return 0;
    }


    lint n2 = mpow(2, n);
    lint a = 1;
    lint b = 1;
    for (int i = 1; i <= k - 1; i++) {
        lint k2 = 0;
        int x = i;
        while ((x & 1) == 0) {
            k2++;
            x >>= 1;
        }
        k2 = min(k2, n);
        b = b * mpow(2, n - k2) % mod;
        a = a * (mpow(2, n - k2) - x + 10 * mod) % mod;
    }

//    cout << a << " " << b << endl;
    cout << (((b - a) % mod) + mod) % mod << " " << b;




    return 0;
}