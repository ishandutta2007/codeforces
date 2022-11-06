#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define DBG(v) cerr << #v << " = " << (v) << endl;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    ll n, d, m;
    cin >> n >> d >> m;
    vector<ll> a(n);
    for (ll &x:a)
        cin >> x;
    sort(a.begin(), a.end());

    const int mid = upper_bound(a.begin(), a.end(), m) - a.begin();


    vector<ll> ps(n);
    partial_sum(a.begin(), a.end(), ps.begin());

    ll ans = 0;
    for (int c = 0; c <= n - mid; ++c) {
        const int k = c == 0 ? 0 : 1 + (c - 1) * (d + 1);
        if (k > n)
            break;
        const int j = mid - (n - k);
        ll res1 = (mid - 1 < 0 ? 0 : ps[mid - 1]) - (j - 1 < 0 ? 0 : ps[j - 1]);
        ll res2 = ps[n - 1] - (n - 1 - c < 0 ? 0 : ps[n - 1 - c]);
        ans = max(ans, res1 + res2);
    }
    cout << ans;
    return 0;
}