#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

int32_t main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        int n, a[20];
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        sort(a + 1, a + n + 1);
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            while (a[i] % 2 == 0) a[i] /= 2, cnt++;
        }
        sort(a + 1, a + n + 1);
        for (int i = 0; i < cnt; i++) a[n] *= 2;
        int sum =0;
        for (int i = 1; i <= n; i++) sum += a[i];
        printf("%lld\n", sum);
    }

    return 0;
}