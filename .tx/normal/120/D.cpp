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

int a[55][55];
int b[55][55];
int n, m;
int ns[3];
int cs[3];

int s[55];

int gets(int l, int r) {
    int res = s[r];
    if (l) {
        res -= s[l - 1];
    }
    return res;
}

int solve() {
    if (n < 3) {
        return 0;
    }
    for (int i = 0; i < n; i++) {
        s[i] = 0;
        for (int j = 0; j < m; j++) {
            s[i] += a[i][j];
        }
        if (i) {
            s[i] += s[i - 1];
        }
    }
    int res = 0;
    for (int i1 = 0; i1 < n; i1++) {
        for (int i2 = i1 + 1; i2 + 1 < n; i2++) {
            cs[0] = gets(0, i1);
            cs[1] = gets(i1 + 1, i2);
            cs[2] = gets(i2 + 1, n - 1);
            sort(cs, cs + 3);
            if (cs[0] == ns[0] && cs[1] == ns[1] && cs[2] == ns[2]) {
                res++;
            }
        }
    }
    return res;
}


int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scii(n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            sci(a[i][j]);
            b[j][i] = a[i][j];
        }
    }
    sciii(ns[0], ns[1], ns[2]);
    sort(ns, ns + 3);
    int ans = solve();
    memcpy(a, b, sizeof(int) * 55 * 55);
    swap(n, m);
    ans += solve();
    cout << ans;

    return 0;
}