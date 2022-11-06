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

const int mod = 1e9 + 7;

int mpow(lint a, int p) {
    lint res = 1;
    for (; p > 0; p >>= 1) {
        if (p & 1) {
            res = res * a % mod;
        }
        a = a * a % mod;
    }
    return res;
}

int main() {
    sciiid(n, m, k);
    if (k > n || k == 1) {
        cout << mpow(m, n);
    } else if (k == n) {
        cout << mpow(m, (n + 1) / 2);
    } else if (k % 2 == 0) {
        cout << m;
    } else {
        cout << m * m;
    }

    return 0;
}