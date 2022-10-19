#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cassert>
#include <map>

using namespace std;
#define ll long long
const ll INF = 1e15;

struct Fenwick {
    int n;
    vector <int> f;

    Fenwick(int n) : n(n) {
        f.resize(n + 1);
    }

    inline void add(int i) {
        for (++i; i <= n; i += (i & (-i))) f[i]++;
    }

    inline int get_pref(int i) {
        int ans = 0;
        for (++i; i > 0; i -= (i & (-i))) ans += f[i];
        return ans;
    }

    inline int get_seg(int l, int r) {
        return get_pref(r) - get_pref(l - 1);
    }
};

signed main() {
    if (0) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        vector <vector <int>> all(26);
        for (int i = 0; i < n; ++i) {
            all[s[i] - 'a'].push_back(i);
        }
        for (int i = 0; i < 26; ++i) {
            reverse(all[i].begin(), all[i].end());
        }
        Fenwick f(n);
        ll cur = 0, ans = INF;
        for (int i = 0; i < n; ++i) {
            for (int c = 0; c < t[i] - 'a'; ++c) {
                if (all[c].empty()) continue;
                int pos = all[c].back();
                pos += f.get_seg(pos + 1, n - 1);
                ans = min(ans, cur + pos - i);
            }
            int c = t[i] - 'a';
            if (all[c].empty()) break;
            int pos = all[c].back();
            pos += f.get_seg(pos + 1, n - 1);
            cur += pos - i;
            f.add(all[c].back());
            all[c].pop_back();
        }
        if (ans == INF) cout << "-1\n";
        else cout << ans << "\n";
    }
}

/*

 */