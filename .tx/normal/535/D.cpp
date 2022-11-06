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

char s[1111111];
int z[1111111];
int p;

void calcZ() {
    int l = 0, r = 0;
    for (int i = 1; i < p; i++) {
        if (i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while (i + z[i] < p && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] > r) {
            r = i + z[i];
            l = i;
        }
    }
}

int y[1111111];
int mod = 1e9 + 7;

lint pow(int a, int p) {
    if (p == 0) {
        return 1;
    }
    lint t = pow(a, p / 2);
    t = t * t % mod;
    if (p & 1) {
        t = t * a % mod;
    }
    return t;
}

int main() {
    int n, m;
    scanf("%d %d\n", &n, &m);
    if (m == 0) {
        cout << pow(26, n) % mod;
        return 0;
    }
    scanf("%s", s);
    p = strlen(s);
    calcZ();
    for (int i = 0; i < m; i++) {
        sci(y[i]);
        --y[i];
    }
    lint ans = pow(26, y[0]);
    for (int i = 1; i < m; i++ ) {
        if (y[i] - y[i - 1] >= p) {
            ans = ans * pow(26, y[i] - y[i - 1] - p) % mod;
        } else {
            int k = y[i] - y[i - 1];
            if (z[k] != p - k) {
                cout << 0;
                return 0;
            }
        }
    }
    ans = ans * pow(26, n - y[m - 1] - p) % mod;
    cout << ans;

    return 0;
}