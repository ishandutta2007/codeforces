#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <string>
#include <memory.h>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rvei(a, n) for (int i = 0; i < n; i++) sci(a[i])
#define rveid(a, n) vector<int> a(n); rvei(a, n)

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;

using namespace std;

const int mod = (int) 1e9 + 7;

lint powPref[222222];
lint powSuf[222222];

int a[222222];
int b[222222];

lint mpow(lint a, lint p, lint mod) {
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
    scid(n);
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        scid(x);
        cnt[x]++;
    }
    n = 0;
    for (auto& i : cnt) {
        b[n] = i.first;
        a[n++] = i.second;
    }

    powPref[0] = a[0] + 1;
    powSuf[n - 1] = a[n - 1] + 1;
    for (int i = 1; i < n; i++) {
        powPref[i] = powPref[i - 1] * (a[i] + 1) % (mod - 1);
        powSuf[n - i - 1] = powSuf[n - i] * (a[n - i - 1] + 1) % (mod - 1);
    }

    lint ans = 1;
    for (int i = 0; i < n; i++) {
        lint pp = 1;
        if (i > 0) {
            pp = pp * powPref[i - 1] % (mod - 1);
        }
        if (i + 1 < n) {
            pp = pp * powSuf[i + 1] % (mod - 1);
        }
        lint cp = 1;
        for (int j = 0; j < a[i]; j++) {
            cp = cp * b[i] % mod;
            ans = ans * mpow(cp, pp, mod) % mod;
        }
    }

    cout << ans;

    return 0;
}