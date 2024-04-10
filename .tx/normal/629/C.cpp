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

void add(int& a, int x) {
    a += x;
    if (a >= mod) {
        a -= mod;
    }
}

int d[2222][2222];
char s[111111];

int main() {
    d[0][0] = 1;
    for (int i = 1; i <= 2000; i++) {
        d[i][0] = d[i - 1][1];
        for (int j = 1; j <= 2000; j++) {
            add(d[i][j], d[i - 1][j - 1]);
            add(d[i][j], d[i - 1][j + 1]);
        }
    }

    sciid(n, m);
    scanf("\n%s", s);
    int b = 0, mb = 0;
    for (int i = 0; i < m; i++) {
        if (s[i] == '(') {
            b++;
        } else {
            b--;
        }
        mb = min(mb, b);
    }

    int ans = 0;
    for (int i = 0; i <= n - m; i++) {
        for (int j = 0; j <= i; j++) {
            if (j + mb >= 0 && j + b >= 0 && j + b <= 2000) {
                add(ans, 1LL * d[i][j] * d[n - m - i][j + b] % mod);
            }
        }
    }
    cout << ans;

    return 0;
}