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

lint get_lca(lint a, lint b) {
    set<lint> ua;
    while (a) {
        ua.insert(a);
        a >>= 1;
    }

    while (b) {
        if (ua.find(b) != ua.end()) {
            return b;
        }
        b >>= 1;
    }
    return -1;
}

map<pair<lint, lint>, lint> w;

void upd_w(lint a, lint lc, int nw) {
    while (a != lc) {
        lint na = a >> 1;
        w[{a, na}] += nw;
        a = na;
    }
}

lint calc_w(lint a, lint lc) {
    lint res = 0;
    while (a != lc) {
        lint na = a >> 1;
        auto it = w.find({a, na});
        if (it != w.end()) {
            res += it->second;
        }
        a = na;
    }
    return res;
}

int main() {
    init_cin
    int q;
    cin >> q;
    while (q-- > 0) {
        lint t, x, y, z;
        cin >> t;
        if (t == 1) {
            cin >> x >> y >> z;
            lint lc = get_lca(x, y);
            upd_w(x, lc, z);
            upd_w(y, lc, z);
        } else {
            cin >> x >> y;
            lint lc = get_lca(x, y);
            cout << calc_w(x, lc) + calc_w(y, lc) << "\n";
        }
    }

    return 0;
}