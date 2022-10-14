#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb emplace_back
#define all(x) (x).begin(), (x).end()

const long long INF = 1e18 + 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    if (n == 1) {
        cout << 0;
        return 0;
    }
    long long a, R, m;
    cin >> a >> R >> m;
    vector<int> h(n);
    for (auto &c : h) cin >> c;
    sort(all(h));
    vector<long long> pr(n + 1);
    for (int i = 0; i < n; i++) pr[i + 1] = pr[i] + h[i];
    long long ans = INF;
    long long c = min(a + R, m);
    for (int i = 0; i < n - 1; i++) {
        long long l = h[i], r = h[i + 1];
        long long cnt1 = pr[i + 1], cnt2 = pr.back() - pr[i + 1], k1 = i + 1, k2 = n - i - 1;
        /// add >= del
        l = max(l, (cnt1 + cnt2 + k1 + k2 - 1) / (k1 + k2));
        if (l <= r) {
            long long H = ((k1 + k2) * a - k2 * c >= 0 ? l : r);
            ans = min(ans, (cnt2 - k2 * H) * c + (k1 * H - cnt1 - cnt2 + k2 * H) * a);
        }
        /// del >= add
        l = h[i];
        r = min(r, (cnt1 + cnt2) / (k1 + k2));
        if (l <= r) {
            long long H = (k1 * c - (k1 + k2) * R >= 0 ? l : r);
            ans = min(ans, (k1 * H - cnt1) * c + (cnt1 + cnt2 - k1 * H - k2 * H) * R);
        }
    }
    cout << ans;
    return 0;
}