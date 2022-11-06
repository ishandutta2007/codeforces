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

int x[1111111];
set<int> ps;

void fill_p(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            ps.insert(i);
            do {
                x /= i;
            } while (x % i == 0);
        }
    }
    if (x != 1) {
        ps.insert(x);
    }
}

const lint inf = 1e18;

lint d[2][3];

int main() {
    sciiid(n, a, b);
    rea(x, n);
    fill_p(x[0]);
    fill_p(x[0] - 1);
    fill_p(x[0] + 1);
    fill_p(x[n - 1]);
    fill_p(x[n - 1] - 1);
    fill_p(x[n - 1] + 1);

    lint ans = inf;

    for (int t = 0; t < 1; t++) {
        if (t) {
            reverse(x, x + n);
        }
        for (int p : ps) {
            d[0][0] = d[0][1] = d[0][2] = d[1][0] = d[1][1] = d[1][2] = inf;
            d[0][0] = 0;
            for (int i = 0; i < n; i++) {
                int c = i & 1;
                int nx = 1 - c;
//                if (i != 0) {
                    d[nx][1] = min(d[c][0] + a, d[c][1] + a);
                    d[nx][2] = min(d[c][0] + a, d[c][1] + a);
//                }
                if (x[i] % p == 0) {
                    d[nx][0] = d[c][0];
                    d[nx][2] = min(d[nx][2], d[c][2]);
                } else if ((x[i] - 1) % p == 0 || (x[i] + 1) % p == 0) {
                    d[nx][0] = d[c][0] + b;
                    d[nx][2] = min(d[nx][2], d[c][2] + b);
                }
                d[c][0] = d[c][1] = d[c][2] = inf;
            }
            ans = min(ans, min(d[n & 1][0], d[n & 1][2]));
        }
    }

    cout << ans;

    return 0;
}