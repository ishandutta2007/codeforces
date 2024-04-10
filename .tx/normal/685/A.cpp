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

int cr(int x) {
    if (x == 0) {
        return 1;
    }
    int res = 0;
    while (x != 0) {
        res++;
        x /= 7;
    }
    return res;
}

int p[11];
int n, m;
int ans = 0;
int all;
int p10[9];
bool was[7];
int nr, nm;

void calc() {
    int cn = 0;
    int cm = 0;
    for (int i = 0; i < nr; i++) {
        cn = cn * 7 + p[i];
    }
    for (int i = nr; i < all; i++) {
        cm = cm * 7 + p[i];
    }

    if (cn < n && cm < m) {
        ans++;
    }
}

void go(int i) {
    if (i == all) {
        calc();
    }
    for (int j = 0; j < 7; j++) {
        if (was[j]) {
            continue;
        }
        p[i] = j;
        was[j] = true;
        go(i + 1);
        was[j] = false;
    }
}

int main() {
    scii(n, m);
    nr = cr(n - 1);
    nm = cr(m - 1);

    all = nr + nm;

    if (all > 7) {
        cout << 0;
        return 0;
    }


    p10[0] = 1;
    for (int i = 1; i < 9; i++) {
        p10[i] = p10[i - 1] * 10;
    }

    go(0);

    cout << ans;

    return 0;
}