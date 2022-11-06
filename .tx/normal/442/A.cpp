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
int n;
pair<int, int> a[111];

int ucol[5];
int uval[5];
int uall = 0;

bool divs(int mc, int mv) {
    memset(ucol, 0, sizeof(ucol));
    memset(uval, 0, sizeof(uval));
    uall = 0;
    for (int id = 0; id < n; id++) {
        auto& i = a[id];
        int c = i.first;
        int v = i.second;
        bool knowc = mc & (1 << c);
        bool knowv = mv & (1 << v);
        if (knowc && knowv) {
            continue;
        } else if (knowc) {
            uval[c]++;
        } else if (knowv) {
            ucol[v]++;
        } else {
            uall++;
        }
    }
    for (int i = 0; i < 5; i++) {
        if (ucol[i] > 1) {
            return false;
        }
        if (uval[i] > 1) {
            return false;
        }
    }
    return uall <= 1;
}

int main() {
    init_cin
    cin >> n;
    int id[256];
    id['R'] = 0;
    id['G'] = 1;
    id['B'] = 2;
    id['Y'] = 3;
    id['W'] = 4;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        a[i] = {id[s[0]], s[1] - '1'};
    }
    sort(a, a + n);
    n = unique(a, a + n) - a;

    int ans = 10;

    for (int mc = 0; mc < (1 << 5); mc++) {
        for (int mv = 0; mv < (1 << 5); mv++) {
            if (divs(mc, mv)) {
                ans = min(ans, __builtin_popcount(mc) + __builtin_popcount(mv));
            }
        }
    }
    cout << ans;

    return 0;
}