#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define pii pair<int, int>
#define ld long double

const ll INF = 2e18 + 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &c : a) cin >> c;
    vector<int> sum;
    for (int mask = 0; mask < (1 << (n / 2)); mask++) {
        int now = 0;
        for (int i = 0; i < n / 2; i++) {
            if (mask & (1 << i)) {
                now += a[i];
                now %= m;
            }
        }
        sum.pb(now);
    }
    int ans = 0;
    sort(all(sum));
    for (int mask = 0; mask < (1 << ((n + 1) / 2)); mask++) {
        int now = 0;
        for (int i = 0; i < (n + 1) / 2; i++) {
            if (mask & (1 << i)) {
                now += a[i + n / 2];
                now %= m;
            }
        }
        auto it = lower_bound(all(sum), m - now);
        if (it != sum.begin()) {
            it--;
            ans = max(ans, now + *it);
        }
        ans = max(ans, (sum.size() ? sum.back() : 0));
    }
    cout << ans;
    return 0;
}