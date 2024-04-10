#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define pii pair<int, int>
#define ld long double

const int INF = 2e9 + 1;
const ll INFLL = 1e18 + 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll a, b, x, y, n;
        cin >> a >> b >> x >> y >> n;
        ll a1 = a, b1 = b, n1 = n;
        ll p = min(b - y, n);
        b -= p;
        n -= p;
        p = min(a - x, n);
        a -= p;
        ll ans = a * b;
        a = a1; b = b1; n = n1;
        p = min(a - x, n);
        a -= p;
        n -= p;
        p = min(b - y, n);
        b -= p;
        ans = min(ans, a * b);
        cout << ans << "\n";
    }
    return 0;
}