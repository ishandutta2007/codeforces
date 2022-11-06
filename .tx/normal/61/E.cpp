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

int a[1111111];
int b[1111111];

struct Fenv {
    int* t = new int[1111111];

    void add(int i, int x) {
        for (; i < 1111111; i |= (i + 1)) {
            t[i] += x;
        }
    }

    int getS(int r) {
        int res = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) {
            res += t[r];
        }
        return res;
    }

    int getS(int l, int r) {
        return getS(r) - getS(l - 1);
    }
};

int main() {
    scid(n);
    for (int i = 0; i < n; i++) {
        sci(a[i]);
        b[i] = a[i];
    }
    sort(b, b + n);
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++) {
        if (i == 0 || b[i] != b[i - 1]) {
            int sz = m.size();
            m[b[i]] = sz;
        }
    }
    for (int i = 0; i < n; i++) {
        a[i] = m[a[i]];
    }

    Fenv l, r;
    for (int i = 0; i < n; i++) {
        r.add(a[i], 1);
    }
    lint ans = 0;
    for (int i = 0; i < n; i++) {
        r.add(a[i], -1);
        lint ll = l.getS(a[i] + 1, n);
        lint rr = r.getS(a[i] - 1);
        ans += ll * rr;
        l.add(a[i], 1);
    }

    cout << ans;

    return 0;
}