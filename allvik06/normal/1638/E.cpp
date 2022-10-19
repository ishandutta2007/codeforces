#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <cmath>
#include <cassert>
#include <array>

using namespace std;
#define int long long

struct Fenwick {
    int n;
    vector <int> f;

    Fenwick(int n) : n(n) {
        f.resize(n + 1);
    }

    inline void add_pref(int i, int x) {
        for (++i; i > 0; i -= (i & (-i))) f[i] += x;
    }

    inline void add_seg(int l, int r, int x) {
        add_pref(r, x);
        add_pref(l - 1, -x);
    }

    inline int get_point(int i) {
        int ans = 0;
        for (++i; i <= n; i += (i & (-i))) ans += f[i];
        return ans;
    }
};

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int n, q;
    cin >> n >> q;
    Fenwick t(n);
    map <int, int> cur;
    set <array <int, 3>> s;
    s.insert({0, n - 1, 1});
    while (q--) {
        string type;
        cin >> type;
        if (type == "Color") {
            int l, r, c;
            cin >> l >> r >> c; --l; --r;
            bool f = false;
            while (true) {
                auto it = s.lower_bound({l + 1, l + 1, 0});
                if (!f) {
                    it--;
                    f = true;
                }
                if (it == s.end() || (*it)[0] > r) break;
                array <int, 3> tmp = *it;
                if (tmp[1] < l) continue;
                s.erase(it);
                if (tmp[0] >= l && tmp[1] <= r) {
                    t.add_seg(tmp[0], tmp[1], cur[tmp[2]]);
                } else if (tmp[0] < l && tmp[1] > r) {
                    t.add_seg(l, r, cur[tmp[2]]);
                    s.insert({tmp[0], l - 1, tmp[2]});
                    s.insert({r + 1, tmp[1], tmp[2]});
                } else if (tmp[0] < l) {
                    t.add_seg(l, tmp[1], cur[tmp[2]]);
                    s.insert({tmp[0], l - 1, tmp[2]});
                } else {
                    t.add_seg(tmp[0], r, cur[tmp[2]]);
                    s.insert({r + 1, tmp[1], tmp[2]});
                }
            }
            s.insert({l, r, c});
            t.add_seg(l, r, -cur[c]);
        } else if (type == "Add") {
            int col, x;
            cin >> col >> x;
            cur[col] += x;
        } else if (type == "Query") {
            int i;
            cin >> i; --i;
            auto it = s.lower_bound({i + 1, i + 1, 0});
            it--;
            cout << t.get_point(i) + cur[(*it)[2]] << "\n";
        }
    }
}

/*

 */