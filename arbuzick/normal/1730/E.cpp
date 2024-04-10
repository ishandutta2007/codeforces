#include <bits/stdc++.h>

using namespace std;

const int maxm = 1e6 + 6;

vector<int> d[maxm];

vector<int> pos[maxm];

int pos_nw[maxm];

void precalc() {
    for (int i = 1; i < maxm; ++i) {
        for (int j = i; j < maxm; j += i) {
            d[j].push_back(i);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> ll(n, -1), lg(n, -1), rl(n, n), rg(n, n);
    vector<int> st;
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && a[i] < a[st.back()]) {
            rl[st.back()] = i;
            st.pop_back();
        }
        st.push_back(i);
    }
    st.clear();
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && a[i] > a[st.back()]) {
            rg[st.back()] = i;
            st.pop_back();
        }
        st.push_back(i);
    }
    st.clear();
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && a[i] < a[st.back()]) {
            ll[st.back()] = i;
            st.pop_back();
        }
        st.push_back(i);
    }
    st.clear();
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && a[i] >= a[st.back()]) {
            lg[st.back()] = i;
            st.pop_back();
        }
        st.push_back(i);
    }
    for (int i = 0; i < n; ++i) {
        pos[a[i]].push_back(i);
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        for (auto mn : d[a[i]]) {
            int &ps = pos_nw[mn];
            while (ps < pos[mn].size() && pos[mn][ps] <= i) {
                ps++;
            }
            int l = lg[i], r = rg[i];
            if (ps > 0 && rl[pos[mn][ps - 1]] > i && l < pos[mn][ps - 1]) {
                l = max(l, ll[pos[mn][ps - 1]]);
                r = min(r, rl[pos[mn][ps - 1]]);
                ans += (pos[mn][ps - 1] - l) * 1LL * (r - i);
            }
            if (ps < pos[mn].size() && ll[pos[mn][ps]] < i && pos[mn][ps] < r) {
                l = max(l, ll[pos[mn][ps]]);
                r = min(r, rl[pos[mn][ps]]);
                ans += (i - l) * 1LL * (r - pos[mn][ps]);
            }
            if (ps > 0 && rl[pos[mn][ps - 1]] > i && ps < pos[mn].size() && ll[pos[mn][ps]] < i && l < pos[mn][ps - 1] && pos[mn][ps] < r) {
                ans -= (pos[mn][ps - 1] - l) * 1LL * (r - pos[mn][ps]);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        pos[a[i]].clear();
        pos_nw[a[i]] = 0;
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    precalc();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}