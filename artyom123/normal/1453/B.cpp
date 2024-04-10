#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define pii pair<int, int>
#define ld long double

const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &c : a) cin >> c;
        ll sum = 0;
        for (int i = 0; i + 1 < n; i++) sum += abs(a[i] - a[i + 1]);
        ll ans = min(sum - abs(a[n - 1] - a[n - 2]), sum - abs(a[0] - a[1]));
        for (int i = 1; i + 1 < n; i++) {
            if (a[i - 1] <= a[i] && a[i + 1] <= a[i]) {
                ans = min(ans, sum - 2 * (a[i] - max(a[i - 1], a[i + 1])));
            } else if (a[i - 1] >= a[i] && a[i + 1] >= a[i]) {
                ans = min(ans, sum - 2 * (min(a[i - 1], a[i + 1]) - a[i]));
            }
        }
        cout << ans << "\n";
    }
    return 0;
}