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

int n, q, a[MN], t;
char c;

int32_t main() {
    boost();

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> c;
        a[i] = c - 'a';
    }
    int ans = 0;
    for (int i = 1; i <= n - 2; i++) if (a[i] == 0 && a[i + 1] == 1 && a[i + 2] == 2) ans++;
    while (q--) {
        cin >> t >> c;
        for (int i = t - 2; i <= t; i++) {
            if (i < 1 || i + 2 > n) continue;
            if (a[i] == 0 && a[i + 1] == 1 && a[i + 2] == 2) ans--;
        }
        a[t] = c - 'a';
        for (int i = t - 2; i <= t; i++) {
            if (i < 1 || i + 2 > n) continue;
            if (a[i] == 0 && a[i + 1] == 1 && a[i + 2] == 2) ans++;
        }
        printf("%lld\n", ans);
    }

    return 0;
}