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
#include <iomanip>

using namespace std;
#define int long long
const int INF = 1e9;

struct Fenwick {
    int n;
    vector <int> f;

    Fenwick(int n) : n(n) {
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
        int n, k;
        cin >> n >> k;
        map <int, int> d;
        map <int, int> cha;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            ++d[x];
        }
        Fenwick f1(n + 1), f2(n + 1);
        int ans = INF;
        int cur = 0;
        for (auto i : d) {
            ++cha[i.second];
            f1.add(i.second, i.second);
            f2.add(i.second, 1);
            ++cur;
        }
        int cur0 = 0;
        for (int i = 0; i <= n; ++i) {
            int e = d[i];
            if (e) {
                f1.add(e, -e);
                f2.add(e, -1);
                cha[e]--;
                cur--;
            }
            if (e <= k && cur0 <= k) {
                int ost_cnt = k - e;
                int l = 0, r = n + 1;
                while (r - l > 1) {
                    int m = (l + r) / 2;
                    if (f1.get_pref(m) >= ost_cnt) r = m;
                    else l = m;
                }
                int s = f1.get_pref(r - 1);
                int cnt = f2.get_pref(r - 1);
                ost_cnt -= s;
                cnt += min(ost_cnt / r, cha[r]);
                ans = min(ans, cur - cnt);
            }
            if (e == 0) ++cur0;
        }
        cout << ans << "\n";
    }
    return 0;
}