#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0) {
        int n, x, y, d;
        cin >> n >> x >> y >> d;
        int ans = INT_MAX;
        if (y % d == x % d)
            ans = min(ans, abs((x - y) / d));
        if (y % d == 1)
            ans = min(ans, (int)ceil(1.0 * (x - 1) / d) + (y - 1) / d);
        if (y % d == n % d)
            ans = min(ans, (int)ceil(1.0 * (n - x) / d) + (n - y) / d);
        if (ans == INT_MAX)
            cout << -1;
        else
            cout << ans;
        cout << "\n";
    }
    return 0;
}