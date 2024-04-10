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

using namespace std;

int main() {
    sciid(n, m);
    for (int i = 0; i < n; i++) {
        sciiid(s, f, t);
        --s; --f;
        if (s == f) {
            cout << t << "\n";
            continue;
        }
        int cf = t % (2 * (m - 1));
        bool up = cf + 1 < m;
        if (cf >= m) {
            cf = 2 * m - cf - 2;
        }
        if (cf < s) {
            if (up) {
                t += s - cf;
            } else {
                t += s + cf;
                up = true;
            }
        } else if (cf > s) {
            if (up) {
                t += m - 1 - cf + m - 1 - s;
                up = false;
            } else {
                t += cf - s;
            }
        }
        if (s < f) {
            if (up) {
                t += f - s;
            } else {
                t += f + s;
            }
        } else if (s > f) {
            if (up) {
                t += m - 1 - s + m - 1 - f;
            } else {
                t += s - f;
            }
        }
        cout << t << "\n";
    }

    return 0;
}