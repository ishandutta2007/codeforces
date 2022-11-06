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

int main() {
    sciid(n, k);
    rveid(a, n);
    int ans = 1e9;
    int ai = -1;
    for (int i = 0; i < n; i++) {
        int t = 0;
        for (int j = 0; j < n; j++) {
            int x = a[i] + (j - i) * k;
            if (x <= 0) {
                t = 1e9;
                break;
            }
            if (x != a[j]) {
                t++;
            }
        }
        if (t < ans) {
            ans = t;
            ai = i;
        }
    }
    cout << ans << "\n";
    for (int j = 0; j < n; j++) {
        int x = a[ai] + (j - ai) * k;
        if (x < a[j]) {
            printf("- %d %d\n", j + 1, a[j] - x);
        } else if (x > a[j]) {
            printf("+ %d %d\n", j + 1, x - a[j]);
        }
    }
    return 0;
}