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

const lint mod = (lint) 1e9 + 7;

lint mpow(lint a, lint p) {
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
    init_cin
    string s;
    cin >> s;
    int k;
    cin >> k;
    int a = s.length();
    lint q = mpow(2, a);
    lint sm = (mpow(q, k) + mod - 1) * mpow(q + mod - 1, mod - 2) % mod;
    lint ans = 0;
    for (int i = 0; i < a; i++) {
        if (s[i] == '5' || s[i] == '0') {
            ans = (ans + mpow(2, i) * sm) % mod;
        }
    }
    cout << ans;

    return 0;
}