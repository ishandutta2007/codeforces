#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cassert>
#include <map>
#include <set>
#include <cmath>

using namespace std;
#define int long long
const int maxl = 32;
const int INF = 1e15;

struct fenwick {
    int n;
    vector <int> f;

    fenwick(int n) : n(n) {
        f.resize(n + 1);
    }

    inline void add(int i, int x) {
        for (++i; i <= n; i += (i & (-i))) f[i] += x;
    }

    inline int get_pref(int i) {
        int ans = 0;
        for (++i; i > 0; i -= (i & (-i))) ans += f[i];
        return ans;
    }
};

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
        vector <int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        int ans = 0;
        fenwick f(n);
        for (int i = n - 1; i >= 0; --i) {
            if (a[i] < i + 1) ans += f.get_pref(n - 1) - f.get_pref(min(i + 1, n - 1));
            if (a[i] < i + 1) f.add(a[i], 1);
        }
        cout << ans << "\n";
    }
}

/*

 */