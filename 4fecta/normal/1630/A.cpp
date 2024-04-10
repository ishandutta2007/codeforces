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
        int n, k;
        cin >> n >> k;
        if (n == 4 && k == n - 1) {printf("-1\n"); continue;}
        vector<int> vis(n, 0);
        if (k != n - 1) {
            printf("%lld %lld\n", n - 1, k);
            vis[n - 1] = vis[k] = 1;
            int full = n - 1;
            if (k) {
                printf("%lld %lld\n", 0, k ^ full);
                vis[0] = vis[k ^ full] = 1;
            }
            for (int i = 1; i < n; i++) {
                if (vis[i]) continue;
                printf("%lld %lld\n", i, i ^ full);
                vis[i] = vis[i ^ full] = 1;
            }
        } else {
            printf("%lld %lld\n", n - 1, (n - 1) / 2);
            vis[n - 1] = vis[(n - 1) / 2] = 1;
            printf("%lld %lld\n", n - 2, n / 2);
            vis[n - 2] = vis[n / 2] = 1;
            printf("%lld %lld\n", 0, 1);
            vis[0] = vis[1] = 1;
            int full = n - 1;
            for (int i = 1; i < n; i++) {
                if (vis[i]) continue;
                printf("%lld %lld\n", i, i ^ full);
                vis[i] = vis[i ^ full] = 1;
            }
        }
    }

    return 0;
}