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

int n, a[MN], b[MN];
char c;

int32_t main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> c;
            a[i] = c - '0';
        }
        for (int i = 1; i <= n; i++) {
            cin >> c;
            b[i] = c - '0';
        }
        int ans = 0x3f3f3f3f;
        int c1 = 0, c2 = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] == 1 && b[i] == 0) c1++;
            if (a[i] == 0 && b[i] == 1) c2++;
        }
        if (c1 == c2) ans = min(ans, c1 + c2);
        for (int i = 1; i <= n; i++) b[i] ^= 1;
        c1 = c2 = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] == 1 && b[i] == 0) c1++;
            if (a[i] == 0 && b[i] == 1) c2++;
        }
        if (c1 == c2 + 1) ans = min(ans, c1 + c2);
        if (ans == 0x3f3f3f3f) printf("-1\n");
        else printf("%lld\n", ans);
    }

    return 0;
}