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

int cnt[11111111];
int cpr[11111111];
bool pr[11111111];

int main() {
    scid(n);
    for (int i = 0; i < n; i++) {
        scid(x);
        cnt[x]++;
    }
    for (int i = 2; i <= 1e7; i++) {
        if (!pr[i]) {
            for (int j = i; j <= 1e7; j += i) {
                pr[j] = true;
                cpr[i] += cnt[j];
            }
        }
    }
    for (int i = 1; i <= 1e7; i++) {
        cpr[i] += cpr[i - 1];
    }
    scid(m);
    for (; m-- > 0; ) {
        sciid(l, r);
        l = min(l, (int) 1e7);
        r = min(r, (int) 1e7);
        printf("%d\n", cpr[r] - cpr[l - 1]);
    }
    return 0;
}