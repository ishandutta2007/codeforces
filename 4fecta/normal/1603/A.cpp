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

int n, a[MN], bck[MN];

int32_t main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i], bck[i] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = max(i - 100, 1ll); j <= i; j++) if (a[i] % (j + 1)) bck[i] = j;
        }
        bool bad = 0;
        int rem = 0;
        for (int i = 1; i <= n; i++) {
            if (bck[i] == 0 || i - rem > bck[i]) bad = 1;
            rem++;
        }
        if (bad) printf("NO\n");
        else printf("YES\n");
    }

    return 0;
}