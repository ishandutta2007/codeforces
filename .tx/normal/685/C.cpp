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

lint x[111111];
lint y[111111];
lint z[111111];

lint mx[4];
lint mn[4];

lint aa, ab, ac;

bool check(lint A) {
    lint cmn[4];
    lint cmx[4];
    for (int m2 = 0; m2 < 2; m2++) {
        bool ok = true;
        for (int i = 0; i < 4; i++) {
            lint v = mx[i] - A;
            if ((v & 1) != m2) {
                v++;
            }
            cmn[i] = v;
            v = mn[i] + A;
            if ((v & 1) != m2) {
                v--;
            }
            cmx[i] = v;
            if (cmn[i] > cmx[i]) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            continue;
        }
        lint mnD = cmn[1] + cmn[2] - cmx[0];
        lint mxD = cmx[1] + cmx[2] - cmn[0];
        if (mxD < cmn[3] || cmx[3] < mnD) {
            continue;
        }
        ab = cmn[1];
        ac = cmn[2];
        aa = cmx[0];
        if (mnD < cmn[3]) {
            lint d = cmn[3] - mnD;
            lint t = min(d, aa - cmn[0]);
            aa -= t;
            d -= t;
            t = min(d, cmx[1] - ab);
            ab += t;
            d -= t;
            t = min(d, cmx[2] - ac);
            ac += t;
            d -= t;
            if (d != 0) {
                cerr << ":(" << "\n";
            }
        }
        return true;
    }

    return false;
}

int main() {
    init_cin
    int t;
    cin >> t;

    int coef[4][3] = {{1, 1, 1}, {1, 1, -1}, {1, -1, 1}, {1, -1, -1}};

    while (t-- > 0) {
        int n;
        cin >> n;
        for (int i = 0; i < 4; i++) {
            mx[i] = -5e18;
            mn[i] = 5e18;
        }
        for (int i = 0; i < n; i++) {
            cin >> x[i] >> y[i] >> z[i];

            for (int j = 0; j < 4; j++) {
                lint v = x[i] * coef[j][0] + y[i] * coef[j][1] + z[i] * coef[j][2];
                mx[j] = max(mx[j], v);
                mn[j] = min(mn[j], v);
            }
        }

        lint l = -1, r = 3e18;

        while (l + 1 < r) {
            lint m = (l + r) >> 1;
            if (check(m)) {
                r = m;
            } else {
                l = m;
            }
        }
//        cerr << r << endl;
        check(r);
        lint ax = (ab + ac) / 2;
        lint ay = (aa - ac) / 2;
        lint az = (aa - ab) / 2;
        cout << ax << " " << ay << " " << az << "\n";
    }

    return 0;
}