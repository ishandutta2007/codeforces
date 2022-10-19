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
#define int long long
const int INF = 4e18;
int len;
vector <int> t;

inline void update(int i, int x) {
    i += len;
    t[i] = min(t[i], x);
    i >>= 1;
    while (i > 0) {
        t[i] = min(t[2 * i], t[2 * i + 1]);
        i >>= 1;
    }
}

inline int get_min(int l, int r) {
    l += len;
    r += len;
    int ans = INF;
    while (l <= r) {
        if (l & 1) {
            ans = min(ans, t[l]);
            ++l;
        }
        if (!(r & 1)) {
            ans = min(ans, t[r]);
            --r;
        }
        l >>= 1;
        r >>= 1;
    }
    return ans;
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int n, q;
    cin >> n >> q;
    vector <pair <int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    vector <int> bll(n, -1), blr(n, -1), st;
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && a[st.back()].second >= a[i].second) {
            blr[st.back()] = i;
            st.pop_back();
        }
        st.push_back(i);
    }
    st.clear();
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && a[st.back()].second >= a[i].second) {
            bll[st.back()] = i;
            st.pop_back();
        }
        st.push_back(i);
    }
    len = 1 << (int)ceil(log2(n));
    t.resize(2 * len, INF);
    vector <vector <int>> all(n);
    for (int i = 0; i < n; ++i) {
        if (bll[i] != -1) {
            all[i].push_back(bll[i]);
        }
        if (blr[i] != -1) {
            all[blr[i]].push_back(i);
        }
    }
    vector <int> ans(q);
    vector <vector <pair <int, int>>> all_q(n);
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r; --l; --r;
        all_q[r].emplace_back(l, i);
    }
    for (int i = 0; i < n; ++i) {
        for (auto j : all[i]) {
            update(j, (a[i].first - a[j].first) * (a[i].second + a[j].second));
        }
        for (auto j : all_q[i]) {
            ans[j.second] = get_min(j.first, i);
        }
    }
    for (int i : ans) cout << i << "\n";
}

/*


 */