#include <bits/stdc++.h>

using namespace std;

#define int long long

int const maxn = 2e5 + 5;
int p[maxn];
int pref[maxn];

int gcd(int a, int b) {
    while (a > 0 && b > 0) {
        int x = a % b;
        a = b, b = x;
    }
    return a + b;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> p[i];
    sort(p + 1, p + n + 1);
    for (int i = 1; i <= n; ++i) pref[i] = pref[i - 1] + p[i];
    int x, a, y, b, k;
    cin >> x >> a >> y >> b >> k;
    int lef = 0, righ = n + 1;
    int f = a * b / gcd(a, b);
    while (righ - lef > 1) {
        int mid = (righ + lef) / 2;
        int cnt = mid / f;
        int sum = ((pref[n] - pref[n - cnt]) / 100) * (x + y);
        int tmp = mid - cnt;
        int f_a = mid / a - cnt, f_b = mid / b - cnt;
        //cout << righ << " " << lef << " " << mid << '\n';
        //cout << cnt << " " << f_a << " " << f_b << " " << sum << '\n';
        if (x > y) {
            sum += ((pref[n - cnt] - pref[n - cnt - f_a]) / 100) * x + ((pref[n - cnt - f_a] - pref[n - cnt - f_b - f_a]) / 100) * y;
        }
        else {
            sum += ((pref[n - cnt] - pref[n - cnt - f_b]) / 100) * y + ((pref[n - cnt - f_b] - pref[n - cnt - f_b - f_a]) / 100) * x;
        }
        //cout << mid << "   " << sum << '\n';
        if (sum >= k) {
            righ = mid;
        }
        else lef = mid;
    }
    if (righ == n + 1) cout << -1 << '\n';
    else cout << righ << '\n';
}

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) solve();
    return 0;
}