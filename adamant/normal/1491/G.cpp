#include <bits/stdc++.h>

using namespace std;

#define int int64_t

void solve() {
    int n;
    cin >> n;
    int p[n];
    for(int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }
    vector<vector<int>> cycs;
    int used[n] = {0};
    for(int i = 0; i < n; i++) {
        if(!used[i]) {
            vector<int> cyc;
            while(!used[i]) {
                used[i] = true;
                cyc.push_back(i);
                i = p[i];
            }
            cycs.push_back(cyc);
        }
    }
    vector<pair<int, int>> ans;
    auto resolve_cycs = [&](vector<int> cyca, vector<int> cycb) {
        ans.emplace_back(cyca[0], cycb[0]);
        for(int j = 1; j < cyca.size(); j++) {
            ans.emplace_back(cyca[j], cycb[0]);
        }
        for(int j = 1; j < cycb.size(); j++) {
            ans.emplace_back(cyca[0], cycb[j]);
        }
        ans.emplace_back(cyca[0], cycb[0]);
    };
    for(int i = 1; i < cycs.size(); i += 2) {
        resolve_cycs(cycs[i - 1], cycs[i]);
    }
    if(cycs.size() % 2 == 1) {
        if(cycs.size() > 1) {
            resolve_cycs({cycs[0][0]}, cycs.back());
        } else {
            auto cyc = cycs.back();
            ans.emplace_back(cyc[0], cyc[1]);
            for(int i = 2; i < cyc.size() - 1; i++) {
                ans.emplace_back(cyc[0], cyc[i]);
            }
            ans.emplace_back(cyc[1], cyc.back());
            ans.emplace_back(cyc[0], cyc.back());
            ans.emplace_back(cyc[0], cyc[1]);
        }
    }
    cout << ans.size() << endl;
    for(auto it: ans) {
        swap(p[it.first], p[it.second]);
        cout << it.first + 1 << ' ' << it.second + 1 << "\n";
    }
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }
}