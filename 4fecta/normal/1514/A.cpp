#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

int sq[10005];

int32_t main() {
    boost();

    for (int i = 1; i <= 100; i++) sq[i * i] = 1;
    int t;
    cin >> t;
    while (t--) {
        int n, a;
        bool ok = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a;
            if (!sq[a]) ok = 1;
        }
        if (ok) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}