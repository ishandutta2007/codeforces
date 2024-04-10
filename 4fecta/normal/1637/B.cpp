#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

int a[10005], pmax[10005];

int32_t main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int zr = 0;
            for (int j = i; j <= n; j++) {
                if (a[j] == 0) zr++;
                ans += j - i + 1 + zr;
            }
        }
        printf("%lld\n", ans);
    }

    return 0;
}