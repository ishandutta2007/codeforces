#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> ans(n, -1);
    vector<int> l(m), r(m), c(m);
    vector<vector<int>> events(n);
    for (int i = 0; i < m; ++i) {
        cin >> l[i] >> r[i] >> c[i];
        --l[i], --r[i];
        events[l[i]].push_back(i);
        ans[r[i]] = m + 1;
    }
    map<int, vector<int>> mp;
    for (int i = 0; i < n; ++i) {
        for (int j : events[i]) {
            mp[r[j]].push_back(j);
        }
        if (ans[i] >= 0) continue;
        if (mp.empty()) {
            ans[i] = 0;
            continue;
        }
        auto iter = mp.begin();
        int rj = iter->first;
        if (rj <= i) {
            cout << -1 << '\n';
            return 0;
        }
        vector<int> js = iter->second;
        int j = js.back();
        ans[i] = j + 1;
        if (--c[j] == 0) {
            js.pop_back();
            if (js.empty()) {
                mp.erase(rj);
            }
        }
    }
    if (not mp.empty()) {
        cout << -1 << '\n';
    } else {
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " \n"[i == n - 1];
        }
    }
    return 0;
}