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

int main() {
    init_cin();
    int n;
    cin >> n;
    vector<double> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(rall(a));
    if (a[0] >= 0.5) {
        printf("%.11f", a[0]);
        return 0;
    }
    double a0 = 1;
    double a1 = 0;
    double ans = 0;
    for (int i = 0; i < n; i++) {
        a1 = a1 * (1 - a[i]) + a0 * a[i];
        a0 *= (1 - a[i]);
        ans = max(ans, a1);
    }
    printf("%.11f", ans);
    return 0;
}