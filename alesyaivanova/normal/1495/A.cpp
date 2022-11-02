#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())

using namespace std;

const int maxn = 2e5 + 9;
int x[maxn];
int y[maxn];
int n, m;

void solve() {
    int cnt;
    cin >> cnt;
    n = 0, m = 0;
    for (int i = 0; i < 2 * cnt; i++) {
        int a, b;
        cin >> a >> b;
        if (a == 0) {
            y[m] = abs(b);
            m++;
        } else {
            x[n] = abs(a);
            n++;
        }
    }
    ld ans = 0;
    sort(x, x + n);
    sort(y, y + m);
    for (int i = 0; i < n; i++) {
        ans += hypot(x[i], y[i]);
    }
    cout.precision(20);
    cout << fixed << ans << "\n";
}


signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}