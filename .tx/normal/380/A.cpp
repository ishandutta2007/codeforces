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

lint len[111111];
int t[111111];
int x[111111], y[111111];

int main() {
    scid(n);
    vector<int> pc;
    for (int i = 0; i < n; i++) {
        scid(tt);
        if (tt == 1) {
            scid(p);
            len[i] = 1;
            x[i] = p;
            t[i] = 1;
            if (pc.size() < 1e5) {
                pc.push_back(p);
            }
        } else {
            sciid(a, b);
            t[i] = 2;
            len[i] = a * b;
            x[i] = a;
            y[i] = b;
            for (int i = 0; pc.size() < 1e5 && i < b; i++) {
                for (int j = 0; pc.size() < 1e5 && j < a; j++) {
                    pc.push_back(pc[j]);
                }
            }
        }
        if (i > 0) {
            len[i] += len[i - 1];
        }
    }

    scid(m);
    while (m-- > 0) {
        lint p;
//        scanf("%lld", &p);
        scanf("%I64d", &p);
        --p;
        int l = -1, r = n - 1;
        while (l + 1 < r) {
            int m = (l + r) >> 1;
            if (len[m] > p) {
                r = m;
            } else {
                l = m;
            }

        }
        if (t[r] == 1) {
            cout << x[r] << " ";
        } else {
            if (r > 0) {
                p -= len[r - 1];
            }
            p %= x[r];
            cout << pc[p] << " ";
        }
    }


    return 0;
}