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
        int a[4], b[4];
        for (int i = 0; i < 4; i++) {
            cin >> a[i];
            b[i] = a[i];
        }
        sort(b, b + 4);
        int x = max(a[0], a[1]), y = max(a[2], a[3]);
        if (x > y) swap(x, y);
        if (x == b[2] && y == b[3]) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}