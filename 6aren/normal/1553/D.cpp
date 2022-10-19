#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;
    while (tt--) {
        string s, t;
        cin >> s >> t;
        reverse(s.begin(), s.end());
        reverse(t.begin(), t.end());
        vector<vector<vector<int>>> pos(2, vector<vector<int>>(26));
        for (int i = 0; i < s.size(); i++) pos[i % 2][s[i] - 'a'].push_back(i);
        bool ok = false;
        int cur = -1;
        int cur_par = 0;
        bool found = true;
        for (int i = 0; i < t.size(); i++) {
            auto &ref = pos[cur_par][t[i] - 'a'];
            int k = lower_bound(ref.begin(), ref.end(), cur) - ref.begin();
            if (k == ref.size()) {
                found = false;
                break;
            } else {
                cur_par ^= 1;
                cur = ref[k];
            }
        }
        ok |= found;
        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}