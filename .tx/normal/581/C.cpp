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
#define rall(a) (a).rbegin(), (a).rend()

typedef long long lint;

using namespace std;

void init_cin() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

lint ans = -1;

int main() {
    sciid(n, k);
    rveid(a, n);
    int ans = 0;
    int k100 = 0;
    for (int i = 0; i < n; i++) {
        ans += a[i] / 10;
        k100 += 10 - (a[i] + 9) / 10;
        a[i] %= 10;
    }
    sort(rall(a));
    for (int i = 0; i < n && a[i] > 0; i++) {
        if (k >= 10 - a[i]) {
            k -= 10 - a[i];
            ans++;
        }
    }
    ans += min(k / 10, k100);
    cout << ans;
    return 0;
}