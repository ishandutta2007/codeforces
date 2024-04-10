#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
#include <chrono>
#include <set>
#include <map>
#include <cassert>
#include <string>
#include <iomanip>
#include <array>
#include <deque>
#include <cmath>
#include <complex>
#include <queue>
#include <iomanip>

using namespace std;
#define ll long long

struct Fenwick {
    int n;
    vector <ll> f;

    inline Fenwick(int n) : n(n) {
        f.resize(n + 1);
    }

    inline Fenwick() {}

    inline void update(int i, ll x) {
        for (++i; i <= n; i += (i & (-i))) f[i] += x;
    }

    inline ll get_pref(int i) {
        ll ans = 0;
        for (++i; i > 0; i -= (i & (-i))) ans += f[i];
        return ans;
    }

    inline int ll get_seg(int l, int r) {
        return get_pref(r) - get_pref(l - 1);
    }
};

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int n, q;
    string s;
    cin >> n >> q >> s;
    vector <int> tin(n + 1), tout(n + 1), ver(n), pr(n + 1), ind(n + 1), st;
    vector <vector <int>> g(n + 1);
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') st.push_back(i);
        else {
            if (st.empty()) s[i] = '.';
            else st.pop_back();
        }
    }
    for (int i : st) s[i] = '.';
    int cur_v = 0, last = 0, cur_time = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '.') continue;
        if (s[i] == '(') {
            ++last;
            ++cur_time;
            ind[last] = (int)g[cur_v].size();
            g[cur_v].push_back(last);
            tin[last] = cur_time;
            pr[last] = cur_v;
            ver[i] = last;
            cur_v = last;
        } else {
            ++cur_time;
            tout[cur_v] = cur_time;
            ver[i] = cur_v;
            cur_v = pr[cur_v];
        }
    }
    vector <Fenwick> all(n + 1);
    for (int i = 0; i <= n; ++i) {
        all[i] = Fenwick((int)g[i].size());
    }
    Fenwick glob(cur_time + 1);
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < (int)g[i].size(); ++j) {
            all[i].update(j, 1);
        }
        glob.update(tin[i], (ll)g[i].size() * ((ll)g[i].size() - 1) / 2 + (ll)g[i].size());
    }
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {

        } else {
            int l, r;
            cin >> l >> r; --l; --r;
            ll cnt = all[pr[ver[l]]].get_seg(ind[ver[l]], ind[ver[r]]);
            ll sum = glob.get_seg(tin[ver[l]], tout[ver[r]]) + cnt * (cnt - 1) / 2 + cnt;
            cout << sum << "\n";
        }
    }
}

/*

 */