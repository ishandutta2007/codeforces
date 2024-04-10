#include <bits/stdc++.h>

using namespace std;

const int INF = 2000000000;

int main() {
    ios_base::sync_with_stdio(false);

    vector<pair<int, int>> d;
    d.emplace_back(-INF, 0);

    int n;
    vector<pair<int, int>> q;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x, w;
        cin >> x >> w;
        q.emplace_back(x + w, x - w);
    }
    sort(q.begin(), q.end());

    for (auto x : q) {
        int r = x.first;
        int l = x.second;

        auto it = lower_bound(d.begin(), d.end(), make_pair(l + 1, -1));
        --it;

        //cerr << r << " - " << l << " from " << (it->first) << " " << (it->second) << "\n";
        auto to = make_pair(r, it->second + 1);
        if (d.back().second < to.second)
            d.push_back(to);
    }
    int ans = 0;
    for (auto x : d)
        ans = max(ans, x.second);
    cout << ans << "\n";
    return 0;
}