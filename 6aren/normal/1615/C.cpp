#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;

    while (tt--) {
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        int cnt_s = 0;
        int cnt_t = 0;
        for (int i = 0; i < n; i++) {
            cnt_s += s[i] == '1';
            cnt_t += t[i] == '1';
        }
        int best = 1e9;
        if (cnt_s == cnt_t) {
            // check even
            vector<int> pos_s, pos_t;
            for (int i = 0; i < n; i++) {
                if (s[i] == '1') pos_s.push_back(i);
                if (t[i] == '1') pos_t.push_back(i);
            }
            int res = 0;
            for (int i = 0; i < n; i++) {
                res += s[i] != t[i];
            }
            best = min(best, res);
        }
        if (n - cnt_s + 1 == cnt_t) {
            bool has = false;
            for (int i = 0; i < n; i++) {
                if (s[i] == t[i] && s[i] == '1') {
                    has = true;
                }
            }
            int res = 0;
            for (int i = 0; i < n; i++) {
                res += s[i] == t[i];
            }
            if (has) res--;
            else res++;
            assert(res % 2 == 0);
            best = min(best, res + 1);
        }
        cout << (best == 1e9 ? -1 : best) << '\n';
    }

    return 0;
}