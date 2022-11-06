#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <string>
#include <memory.h>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rvei(a, n) for (int i = 0; i < n; i++) sci(a[i])
#define rveid(a, n) vector<int> a(n); rvei(a, n)

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;

using namespace std;

lint calc(lint r) {
    if (r <= 9) {
        return r;
    }
    lint res = 9;
    unsigned long long p10 = 1;
    while (1ULL * p10 * 100ULL - 1ULL <= 1ULL * (unsigned long long) r) {
        res += 9 * p10;
        p10 *= 10;
    }
    lint i = 1;
    while ((i + 1) * p10 * 10 + (i + 1) <= r) {
        res += p10;
        i++;
    }
    res += max(0ULL, min(r / 10 - i * p10 + (r % 10 >= i ? 1 : 0), p10));
    return res;
}

int main() {
    lint l, r;
    cin >> l >> r;
    lint ans = calc(r);
    if (l > 1) {
        ans -= calc(l - 1);
    }
    cout << ans;

    return 0;
}