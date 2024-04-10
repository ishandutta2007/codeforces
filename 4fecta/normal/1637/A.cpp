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
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            pmax[i] = max(pmax[i - 1], a[i]);
        }
        bool ok = 0;
        int mn = 0x3f3f3f3f;
        for (int i = n; i > 1; i--) {
            mn = min(mn, a[i]);
            if (mn < pmax[i - 1]) ok = 1;
        }
        if (ok) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}