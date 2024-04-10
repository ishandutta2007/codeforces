#include <bits/stdc++.h>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rea(a, n) for (int i = 0; i < n; i++) sci(a[i])

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;
typedef long double ldouble;

using namespace std;

int a[111];

int main() {
    scid(n);
    for (int i = 1; i <= n; i++) {
        sci(a[i]);
    }
    if (n < 3 || n % 2 == 0 && a[n] > 0) {
        cout << -1;
        return 0;
    }
    if (n % 2 == 0) {
        --n;
    }
    int ans = 0;
    for (int i = n; i >= 3; i -= 2) {
        int t = max(a[i], a[i - 1]);
        a[i] = max(0, a[i] - t);
        a[i - 1] = max(0, a[i - 1] - t);
        a[(i - 1) / 2] = max(0, a[(i - 1) / 2] - t);
        ans += t;
    }

    ans += a[1];

    cout << ans;

    return 0;
}