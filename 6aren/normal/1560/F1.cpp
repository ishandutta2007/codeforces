#include <bits/stdc++.h>

using namespace std;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int tt;
    cin >> tt;

    while (tt--) {
        int x, k;
        cin >> x >> k;
        vector<int> a;
        while (x) {
            a.push_back(x % 10);
            x /= 10;
        }
        reverse(a.begin(), a.end());
        vector<bool> can(a.size());
        set<int> cur;
        for (size_t i = 0; i < a.size(); i++) {
            cur.insert(a[i]);
            if (cur.size() < k) {
                can[i] = true;
                continue;
            }
            if (cur.size() > k) {
                continue;
            }
            int mx = *cur.rbegin();
            int val = 0, mx_val = 0;
            for (size_t j = i + 1; j < a.size(); j++) {
                val = val * 10 + a[j];
                mx_val = mx_val * 10 + mx;
            } 
            can[i] = mx_val >= val;
        }
        // for (int i = 0; i < a.size(); i++)
        //     cout << can[i] << ' ';
        // cout << endl; 
        int id = -1;
        for (int i = (int) a.size() - 1; i >= 0; i--) {
            if (can[i]) {
                id = i;
                break;
            }
        }
        cur.clear();
        for (int i = 0; i <= id; i++) {
            cur.insert(a[i]);
        }
        for (int i = 0; i <= id; i++) {
            cout << a[i];
        }
        if (cur.size() < k) {
            int val = (id + 1 < a.size() ? a[id + 1] + 1 : 0);
            cur.insert(val);
            if (id + 1 < a.size()) cout << val;
            for (int i = id + 2; i < a.size(); i++) {
                cout << (cur.size() < k ? 0 : *cur.begin());
            }
            cout << '\n';
        } else {
            int val = (id + 1 < a.size() ? *cur.upper_bound(a[id + 1]) : 0);
            if (id + 1 < a.size()) cout << val;
            for (int i = id + 2; i < a.size(); i++) {
                cout << *cur.begin();
            }
            cout << '\n';
        }

    }

    return 0;
}