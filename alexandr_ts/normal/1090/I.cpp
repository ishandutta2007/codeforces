#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll INF = 4e18 + 10;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1);
const int M = 1e3 + 10;
const int N = 2e7 + 10;

ll a[N];
ull b[N];

void solve() {
    ll n, l, r;
    ull x, y, z;
    cin >> n >> l >> r >> x >> y >> z >> b[1] >> b[2];
    for (int i = 3; i <= n; i++) {
        b[i] = (b[i - 2] * x % (1ull << 32) + b[i - 1] * y % (1ull << 32) + z) % (1ull << 32);
        assert(b[i] >= 0);
    }
    fr(i, n) {
        a[i] = ((ll)b[i + 1]) % (r - l + 1) + l;
    }

    ll ans = INF;

    ll mn = INF;
    fr(i, n) {
        if (mn != INF && mn < a[i])
            ans = min(ans, mn * a[i]);
        mn = min(mn, a[i]);
    }

    int firstNeg = -1;
    fr(i, n)
        if (a[i] < 0) {
            firstNeg = i;
            break;
        }

    if (firstNeg != -1) {
        frab(i, firstNeg, n)
            a[i] *= -1;
        ll mn = INF;
        for (int i = n - 1; i >= firstNeg; i--) {
            if (mn != INF && mn < a[i])
                ans = min(ans, mn * a[i]);
            mn = min(mn, a[i]);
        }
    }

    if (ans == INF)
        cout << "IMPOSSIBLE\n";
    else
        cout << ans << "\n";
}

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--)
        solve();


}