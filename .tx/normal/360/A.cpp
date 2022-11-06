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

lint a[5555];
bool st[5555];
lint b[5555];

int qt[5555];
int ql[5555];
int qr[5555];
int qx[5555];

int main() {
    sciid(n, m);
    for (int i = 0; i < m; i++) {
        sci(qt[i]);
        sciii(ql[i], qr[i], qx[i]);
    }

    for (int i = m - 1; i >= 0; i--) {
        int t = qt[i];
        int l = ql[i];
        int r = qr[i];
        int x = qx[i];
        --l;
        if (t == 1) {
            for (int j = l; j < r; j++) {
                if (st[j]) {
                    a[j] -= x;
                }
            }
        } else {
            for (int j = l; j < r; j++) {
                if (st[j]) {
                    a[j] = min<lint>(a[j], x);
                } else {
                    st[j] = true;
                    a[j] = x;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        b[i] = a[i];
        if (abs(b[i]) > 1e9) {
            cout << "NO";
            return 0;
        }
    }

    for (int i = 0; i < m; i++) {
        int t = qt[i];
        int l = ql[i];
        int r = qr[i];
        int x = qx[i];
        --l;
        if (t == 1) {
            for (int j = l; j < r; j++) {
                b[j] += x;
            }
        } else {
            lint mx = b[l];
            for (int i = l + 1; i < r; i++) {
                mx = max(mx, b[i]);
            }
            if (mx != x) {
                cout << "NO";
                return 0;
            }
        }
    }

    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }


    return 0;
}