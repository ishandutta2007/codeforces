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

lint gcd(lint a, lint b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    scid(n);
    rveid(a, n);
    sort(a.begin(), a.end());
    vector<lint> d(n);
    lint s = a[0];
    for (int i = 1; i < n; i++) {
        d[i] = d[i - 1] + 1LL * (a[i] - a[i - 1]) * i;
        s += a[i] + d[i] * 2;
    }
    lint g = gcd(s, n);
    s /= g;
    n /= g;
    cout << s << " " << n;


    return 0;
}