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
        int a[105], b[105];
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) cin >> b[i];
        sort(a + 1, a + n + 1);
        sort(b + 1, b + n + 1);
        bool ok= 1;
        for (int i = 1; i <= n; i++) if (a[i] != b[i] - 1 && a[i] != b[i]) ok = 0;
        if (ok) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}