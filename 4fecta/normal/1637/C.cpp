#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 100005;

int a[MN];

int32_t main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        int sum = 0, mx = 0;
        bool ok = 1;
        if (n == 3 && a[2] % 2 == 1) ok = 0;
        for (int i = 2; i < n; i++) mx = max(mx, a[i]);
        if (mx == 1) ok = 0;
        if (!ok) {printf("-1\n"); continue;}
        for (int i = 2; i < n; i++) sum += (a[i] + 1) / 2;
        printf("%lld\n", sum);
    }

    return 0;
}