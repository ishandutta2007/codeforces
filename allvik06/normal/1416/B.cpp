#include <iostream>
#include <vector>
#include <cmath>
#include <array>
#include <set>

using namespace std;
#define int long long
const int INF = 1e9;

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> a(n + 1);
        for (int i = 1; i <= n; ++i) cin >> a[i];
        int x = 0;
        for (int i = 1; i <= n; ++i) x += a[i];
        if (x % n != 0) {
            cout << "-1\n";
            continue;
        }
        x /= n;
        vector <array <int, 3>> ans;
        for (int i = 2; i <= n; ++i) {
            int need = (i - a[i] % i) % i;
            ans.push_back({1, i, need});
            ans.push_back({i, 1, (a[i] + need) / i});
            a[1] += a[i];
            a[i] = 0;
        }
        for (int i = 2; i <= n; ++i) {
            ans.push_back({1, i, x});
        }
        cout << (int)ans.size() << "\n";
        for (auto i : ans) cout << i[0] << " " << i[1] << " " << i[2] << "\n";
    }
}