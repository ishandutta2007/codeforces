#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <memory.h>

#define scid(a) int a; scanf("%d", &a)
#define sciid(a, b) int a, b; scanf("%d%d", &a, &b)
#define sciiid(a, b, c) int a, b, c; scanf("%d%d%d", &a, &b, &c)

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define rveid(a, n) vector<int> a(n); for (int i = 0; i < n; i++) sci(a[i])
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).end()

typedef long long lint;

using namespace std;

void init_cin() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

int c[111111];
int a[111111];
int w[111111];

int main() {
    scid(n);
    for (int i = 0; i < n; ++i) {
        sci(a[i]);
    }
//    int n = 100000;
//    for (int i = 0; i < n; i++) {
//        a[i] = 100000 - i / 2;
//    }
    int mx = *max_element(a, a + n);
//    vector<set<int> > d(n);

    for (int i = 0; i < n; i++) {
        int y = a[i];
        int ww = 0;
        while (y > 0) {
            int x = y;
            int wc = 0;
            while (x <= mx) {
                w[x] += ww + wc;
                c[x]++;
                wc++;
                x *= 2;
            }
            while ((y & 1) == 0) {
                y >>= 1;
                ww++;
                w[y] += ww;
                c[y]++;
            }
            y >>= 1;
            ww++;
        }
    }

    int ans = 1e9;
    for (int i = 1; i <= mx; i++) {
        if (c[i] == n) {
            ans = min(ans, w[i]);
        }
    }
    cout << ans;

    return 0;
}