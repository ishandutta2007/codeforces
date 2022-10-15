#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 1005;

int n, t, a[MN];

int32_t main() {
    boost();

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        printf("%d\n", 3 * n);
        for (int i = 1; i <= n; i += 2) {
            printf("%d %d %d\n", 2, i, i + 1);
            printf("%d %d %d\n", 1, i, i + 1);
            printf("%d %d %d\n", 2, i, i + 1);
            printf("%d %d %d\n", 2, i, i + 1);
            printf("%d %d %d\n", 1, i, i + 1);
            printf("%d %d %d\n", 2, i, i + 1);
        }
    }

    return 0;
}