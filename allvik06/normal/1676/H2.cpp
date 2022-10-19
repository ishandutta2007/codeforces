#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <array>
#include <map>
#include <utility>
#include <set>
#include <cassert>

using namespace std;

inline void add(int i, int n, vector <int>& f) {
    for (++i; i <= n; i += (i & (-i))) f[i]++;
}

inline int get_pref(int i, vector <int>& f) {
    int ans = 0;
    for (++i; i > 0; i -= (i & (-i))) ans += f[i];
    return ans;
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> f(n + 1);
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x; --x;
            ans += i - get_pref(x - 1, f);
            add(x, n, f);
        }
        cout << ans << "\n";
    }
    return 0;
}