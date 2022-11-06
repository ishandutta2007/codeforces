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

lint h[111111];
lint p[111111];


int main() {
    init_cin
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> p[i];
    }
    lint l = -1, r = 1e11;
    while (l + 1 < r) {
        lint t = (l + r) >> 1;
        int ch = 0, cp = 0;
        int fp = 0;
        while (ch < n && cp < m) {
            lint nt = p[cp] - p[fp] + min(abs(p[cp] - h[ch]), abs(p[fp] - h[ch]));
            if (nt > t) {
                fp = cp;
                ch++;
            } else {
                cp++;
            }
        }
        if (cp < m) {
            l = t;
        } else {
            r = t;
        }
    }

    cout << r;

    return 0;
}