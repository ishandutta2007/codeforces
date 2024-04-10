#include <bits/stdc++.h>

using namespace std;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int tt;
    cin >> tt;
    while (tt--) {
        string t;
        cin >> t;
        string order;
        int n = (int) t.size();
        vector<int> app(26, 0);
        vector<vector<int>> pos(26);
        for (int i = n - 1; i >= 0; i--) {
            if (!app[t[i] - 'a']) order.push_back(t[i]); 
            app[t[i] - 'a'] = true;
        }
        for (int i = 0; i < n; i++) {
            pos[t[i] - 'a'].push_back(i);
        }
        reverse(order.begin(), order.end());
        int mx = -1;
        for (size_t i = 0; i < order.size(); i++) {
            int first_end = pos[order[i] - 'a'][(int) pos[order[i] - 'a'].size() / (i + 1) - 1];
            mx = max(mx, first_end);
        }
        if (mx > (int) t.size()) {
            cout << -1 << '\n';
            continue;
        }
        string res = t.substr(0, mx + 1);
        vector<int> del(26);
        string ti;
        for (char ch : order) {
            for (char c : res)
                if (!del[c - 'a']) ti.push_back(c);
            del[ch - 'a'] = true;
        }
        if (ti != t) {
            cout << -1 << '\n';
            continue;
        }
        cout << res << ' ' << order << '\n';
    }

    return 0;
}