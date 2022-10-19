#include <bits/stdc++.h>

using namespace std;
#define ll long long

const ll mod = 1e9 + 7;
signed main() {
    srand(time(0));
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    if (1) {
        int n, d, m;
        cin >> n >> d >> m;
        vector <int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int end = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] <= m) end++;
        }
        ll cur = 0, ans = 0;
        vector <ll> ssum(n + 1);
        ssum[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            ssum[i] = ssum[i + 1] + a[i];
        }
        for (int kol = end - 1; kol >= 0; --kol) {
            cur += a[kol];
            int kol1 = (n - (end - kol) + d) / (d + 1);
            ll tmp = ssum[n - kol1];
            if (end + kol1 > n) {
                tmp = ssum[end] + ssum[kol - (kol1 - (n - end))] - ssum[kol];
            }
            ans = max(ans, cur + tmp);
        }
        cout << max(ans, ssum[n - (n + d) / (d + 1)]);
    }
    else {
        int t;
        cin >> t;
        while (t--) {
            if (t % 100 == 0) cout << t << "\n";

        }
    }
}