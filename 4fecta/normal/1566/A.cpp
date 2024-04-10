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
        int n, s;
        cin >> n >> s;
        int lo = n / 2;
        if (n % 2 == 0) lo--;
        int hi = n - lo;
        int ans = s / hi;
        printf("%lld\n", ans);
    }

    return 0;
}