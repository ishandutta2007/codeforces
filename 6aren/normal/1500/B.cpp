#include<bits/stdc++.h>
using namespace std;

#define int int64_t

#define ll int64_t
 
ll euclid(ll a, ll b, ll &x, ll &y) {
	if (!b) return x = 1, y = 0, a;
	ll d = euclid(b, a % b, y, x);
	return y -= a/b * x, d;
}
 
 
ll crt(ll a, ll m, ll b, ll n) {
	if (n > m) swap(a, b), swap(m, n);
	ll x, y, g = euclid(m, n, x, y);
    if ((a - b) % g != 0) return -1;
	x = (b - a) % n * x % n / g * m + a;
	return x < 0 ? x + m*n/g : x;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    int64_t k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m), pos_a(2 * max(n, m), -1), pos_b(2 * max(n, m), -1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        pos_a[a[i]] = i;
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        b[i]--;
        pos_b[b[i]] = i;
    }

    vector<int64_t> CRT(2 * max(n, m), -1);
    int LCM = 1LL * n * m / __gcd((long long) n, (long long) m);
    for (int i = 0; i < 2 * max(n, m); i++) {
        if (pos_a[i] == -1 || pos_b[i] == -1) continue;
        CRT[i] = crt(pos_a[i], n, pos_b[i], m);
    }

    int64_t l = 1, r = 1e18;
    int64_t ans = -1;

    while (r >= l) {
        int64_t mid = (l + r) / 2;
        int64_t calc = mid;
        for (int i = 0; i < 2 * max(n, m); i++) {
            if (CRT[i] == -1) continue;
            if (mid - 1 < CRT[i]) continue;
            calc -= (mid - 1 - CRT[i]) / LCM + 1;
        }
        if (calc >= k) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
        // cout << mid << ' ' << calc << '\n';
    }
    // cout << CRT[0] << ' ' << CRT[1] << endl;
    cout << ans << '\n';

    return 0;
}