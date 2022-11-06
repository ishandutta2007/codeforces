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
    sciid(n, x);
    bool has_x = false;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        sci(a[i]);
        if (a[i] == x) {
            has_x = true;
        }
    }
    int ans = 0;
    if (!has_x) {
        a.push_back(x);
        n++;
        ans = 1;
    }
    sort(a.begin(), a.end());
    int l = n;
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            l = min(l, abs(i - (n - 1) / 2));
        }
    }
    if (l == 0) {
        cout << ans;
        return 0;
    }
    if (x > a[(n - 1) / 2]) {
        ans += l * 2 - 1 + n % 2;
    } else {
        ans += l * 2 - n % 2;
    }
    cout << ans;
    return 0;
}