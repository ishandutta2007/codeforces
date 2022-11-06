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
typedef long double ldouble;

using namespace std;

char s[555555];
int t[555555];
int n, a, b, T;

int getAns() {
    for (int i = 0; i + 1 < n - 1 - i; i++) {
        swap(t[i + 1], t[n - 1 - i]);
    }
    if (t[0] > T) {
        return 0;
    }
    int ct = t[0];
    int ans = 1;
    for (int i = 1; i < n; i++) {
        ct += a + t[i];
        if (ct <= T) {
            ans = i + 1;
        }
    }
    if (ans == n) {
        return ans;
    }
    lint wt = t[0];
    int bi = n - 1;
    while (wt + a + t[bi] <= T) {
        wt += a + t[bi];
        bi--;
    }
    ans = max(ans, n - bi);
    for (int i = 1; i + 1 < n; i++) {
        wt += 2 * a + t[i];
        while (wt > T && bi + 1 < n) {
            bi++;
            wt -= a + t[bi];
        }
        if (wt > T) {
            break;
        }
        ans = max(ans, i + n - bi);
    }
    return ans;
}

int main() {
    sci(n);
    scii(a, b);
    sci(T);
    scanf("\n%s", s);
    for (int i = 0; i < n; i++) {
        t[i] = 1;
        if (s[i] == 'w') {
            t[i] += b;
        }
    }
    cout << max(getAns(), getAns());

    return 0;
}