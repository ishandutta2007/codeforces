#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

using namespace std;
#define int long long

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int n, m, q;
    cin >> n >> m >> q;
    vector <pair <int, int>> all;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        all.emplace_back(x, 0);
    }
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        all.emplace_back(x, 1);
    }
    sort(all.begin(), all.end());
    int l = n + m;
    vector <int> psum(l + 1), cnt(l + 1);
    for (int i = 0; i < l; ++i) {
        psum[i + 1] = psum[i] + all[i].first;
        cnt[i + 1] = cnt[i] + !all[i].second;
    }
    vector <int> l_seg(l), r_seg(l);
    int ans = 0;
    vector <pair <int, int>> mrg;
    for (int i = 0; i < l; ++i) {
        l_seg[i] = i;
        r_seg[i] = i;
        if (all[i].second == 0) ans += all[i].first;
        if (i < l - 1) mrg.emplace_back(all[i + 1].first - all[i].first, i);
    }
    sort(mrg.begin(), mrg.end());
    vector <pair <int, int>> qu;
    for (int i = 0; i < q; ++i) {
        int x;
        cin >> x;
        qu.emplace_back(x, i);
    }
    sort(qu.begin(), qu.end());

    auto cost_seg = [&](int ll, int rr) {
        int c = cnt[rr + 1] - cnt[ll];
        return psum[rr + 1] - psum[rr - c + 1];
    };

    int cur_m = 0;
    vector <int> res(q);

    for (auto i : qu) {
        while (cur_m < (int)mrg.size() && mrg[cur_m].first <= i.first) {
            int j = mrg[cur_m].second;
            int new_l = r_seg[j];
            int new_r = l_seg[j + 1];
            ans -= cost_seg(new_l, j) + cost_seg(j + 1, new_r);
            l_seg[new_l] = new_r;
            r_seg[new_r] = new_l;
            ans += cost_seg(new_l, new_r);
            ++cur_m;
        }
        res[i.second] = ans;
    }
    for (int i : res) cout << i << "\n";
}