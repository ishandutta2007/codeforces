#include <iostream>
#include <vector>
#include <map>

using namespace std;
#define int long long
const int INF = 1e18;

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int n, ans = INF;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) {
        int last = 0, cur = 0;
        for (int j = i + 1; j < n; ++j) {
            int cnt = (last + a[j]) / a[j];
            cur += cnt;
            last = a[j] * cnt;
        }
        last = 0;
        for (int j = i - 1; j >= 0; --j) {
            int cnt = (last + a[j]) / a[j];
            cur += cnt;
            last = a[j] * cnt;
        }
        ans = min(ans, cur);
    }
    cout << ans;
}