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

int c[111111];
lint d[111111][2];
string a[111111];
string ra[111111];

int main() {
    init_cin
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ra[i] = a[i];
        reverse(ra[i].begin(), ra[i].end());
    }

    for (int i = 1; i < n; i++) {
        d[i][0] = d[i][1] = 1e18;
    }

    d[0][1] = c[0];

    for (int i = 1; i < n; i++) {
        if (a[i] >= a[i - 1]) {
            d[i][0] = min(d[i][0], d[i - 1][0]);
        }
        if (a[i] >= ra[i - 1]) {
            d[i][0] = min(d[i][0], d[i - 1][1]);
        }

        if (ra[i] >= a[i - 1]) {
            d[i][1] = min(d[i][1], d[i - 1][0] + c[i]);
        }
        if (ra[i] >= ra[i - 1]) {
            d[i][1] = min(d[i][1], d[i - 1][1] + c[i]);
        }
    }

    lint ans = min(d[n - 1][0], d[n - 1][1]);
    if (ans == 1e18) {
        cout << -1;
    } else {
        cout << ans;
    }


    return 0;
}