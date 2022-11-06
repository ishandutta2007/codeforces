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

lint a[555555];
lint sa[555555];
lint s[555555];

string p;

int main() {
    init_cin
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> p;
    for (int i = 0; i < n; i++) {
        s[i] = a[i];
        if (p[i] == 'A') {
            sa[i] = a[i];
        }
        if (i) {
            s[i] += s[i - 1];
            sa[i] += sa[i - 1];
        }
    }
    lint mx = s[n - 1] - sa[n - 1];
    lint is = mx;
    for (int i = 0; i < n; i++) {
        lint ca = sa[i];
        lint cb = s[i] - ca;
        mx = max(mx, is - cb + ca);
    }
    for (int i = 0; i < n; i++) {
        lint ca = sa[n - 1] - (i == 0 ? 0 : sa[i - 1]);
        lint cb = s[n - 1] - (i == 0 ? 0 : s[i - 1]) - ca;
        mx = max(mx, is - cb + ca);
    }
    cout << mx;


    return 0;
}