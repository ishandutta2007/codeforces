#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n), x(m), y(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) cin >> x[i] >> y[i];
    vector<vector<int>> flex(n);
    set<pair<int, int>> s;
    vector<int> now(n);
    for (int i = 0; i < m; ++i) {
        --x[i];
        --y[i];
        ++now[x[i]];
        ++now[y[i]];
    }
    vector <int> cha(m);
    for (int i = 0; i < m; ++i) {
        int pl = 0;
        if (a[x[i]] >= now[x[i]]) {
            ++pl;
        }
        else {
            flex[x[i]].push_back(i);
        }
        if (a[y[i]] >= now[y[i]]) {
            ++pl;
        }
        else {
            flex[y[i]].push_back(i);
        }
        s.insert({pl, i});
        cha[i] = pl;
    }
    vector<int> ans;
    vector <bool> used(m);
    for (int i = 0; i < m; ++i) {
        if (s.rbegin()->first == 0) {
            cout << "DEAD";
            return 0;
        }
        int in = s.rbegin()->second;
        used[in] = true;
        ans.push_back(in + 1);
        s.erase({cha[in], in});
        --now[x[in]];
        if (now[x[in]] == a[x[in]]) {
            for (int j : flex[x[in]]) {
                if (used[j]) continue;
                s.erase({cha[j], j});
                ++cha[j];
                s.insert({cha[j], j});
            }
        }
        --now[y[in]];
        if (now[y[in]] == a[y[in]]) {
            for (int j : flex[y[in]]) {
                if (used[j]) continue;
                s.erase({cha[j], j});
                ++cha[j];
                s.insert({cha[j], j});
            }
        }
    }
    cout << "ALIVE\n";
    for (int i = m - 1; i >= 0; --i) cout << ans[i] << " ";
}