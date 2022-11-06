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

typedef long long lint;

using namespace std;

void init_cin() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

int a[111111];
bool bad[1 << 22];
int cnt[22];

int main() {
    sciiid(n, m, d);
    for (int i = 0; i < m; i++) {
        scid(x);
        for (int j = 0; j < x; j++) {
            scid(y);
            a[--y] = i;
        }
    }
    int mask = 0;
    for (int i = 0; i < d; i++) {
        cnt[a[i]]++;
        mask |= 1 << a[i];
    }
    int all = (1 << m) - 1;
    bad[(~mask) & all] = true;
    for (int i = d; i < n; i++) {
        cnt[a[i - d]]--;
        if (cnt[a[i - d]] == 0) {
            mask ^= 1 << a[i - d];
        }
        cnt[a[i]]++;
        mask |= 1 << a[i];
        bad[(~mask) & all] = true;
    }
    int ans = m;
    for (int i = all; i >= 1; i--) {
        if (bad[i]) {
            for (int j = 0; j < m; j++) {
                if (i & (1 << j)) {
                    bad[i ^ (1 << j)] = true;
                }
            }
        } else {
            int t = 0;
            for (int j = 0; j < m; j++) {
                if (i & (1 << j)) {
                    t++;
                }
            }
            ans = min(ans, t);
        }
    }
    cout << ans;



    return 0;
}