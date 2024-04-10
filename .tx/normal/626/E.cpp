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
typedef long double ldouble;

using namespace std;

int a[222222];
lint s[222222];

int n;

ldouble mid_val(int i, int k, int t) {
    lint res = s[i - 1] - s[i - 1 - k] + s[n] - s[n - k] + a[i];
    int len = 2 * k + 1;
    if (t == 2) {
        res += a[i + 1];
        len++;
    }
    return (ldouble) res / len;
}

int main() {
    sci(n);
    for (int i = 1; i <= n; i++) {
        sci(a[i]);
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        s[i] = a[i] + s[i - 1];
    }
    ldouble ans = -1e30;
    int ansType = -1;
    int ansI = -1, ansK = -1;
    for (int i = 1; i <= n; i++) {
        int l = 0, r = min(i - 1, n - i);
        while (l + 2 < r) {
            int m = (l + r) >> 1;
            ldouble s1 = mid_val(i, m, 1);
            ldouble s2 = mid_val(i, m + 1, 1);
            if (s1 < s2) {
                l = m;
            } else {
                r = m + 1;
            }
        }
        ldouble mx = 0;
        for (int j = l; j <= r; j++) {
            ldouble s = mid_val(i, j, 1);
            if (s > mx) {
                mx = s;
                l = j;
            }
        }
        mx -= a[i];
        if (mx > ans) {
            ans = mx;
            ansType = 1;
            ansI = i;
            ansK = l;
        }
    }

    for (int i = 1; i < n; i++) {
        int l = 0, r = min(i - 1, n - i - 1);
        while (l + 2 < r) {
            int m = (l + r) >> 1;
            ldouble s1 = mid_val(i, m, 2);
            ldouble s2 = mid_val(i, m + 1, 2);
            if (s1 < s2) {
                l = m;
            } else {
                r = m + 1;
            }
        }
        ldouble mx = 0;
        for (int j = l; j <= r; j++) {
            ldouble s = mid_val(i, j, 2);
            if (s > mx) {
                mx = s;
                l = j;
            }
        }
        mx -= a[i];
        mx -= a[i + 1];
        if (mx > ans) {
            ans = mx;
            ansType = 2;
            ansI = i;
            ansK = l;
        }
    }

    if (ansType == 1) {
        cout << 2 * ansK + 1 << "\n";
        for (int i = 1; i <= ansK; i++) {
            cout << a[ansI - i] << " ";
        }
        cout << a[ansI] << " ";
        for (int i = 0; i < ansK; i++) {
            cout << a[n - i] << " ";
        }
    } else {
        cout << 2 * ansK + 2 << "\n";
        for (int i = 1; i <= ansK; i++) {
            cout << a[ansI - i] << " ";
        }
        cout << a[ansI] << " " << a[ansI + 1] << " ";
        for (int i = 0; i < ansK; i++) {
            cout << a[n - i] << " ";
        }
    }


    return 0;
}