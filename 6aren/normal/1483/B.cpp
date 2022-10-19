#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &e : a) {
            cin >> e;
        }
        vector<int> res;
        set<int> be_delete;
        set<int> current_id;
        for (int i = 0; i < n; i++) current_id.insert(i);
        auto nxt = [&](int id) {
            auto it = current_id.upper_bound(id);
            if (it == current_id.end()) return *current_id.begin();
            return *it;
        };
        // vector<bool> deleted(n, false);
        // for (int i = 0; i < n; i++) {
        //     cout << nxt(i) << endl;
        // }
        for (int i = 0; i < n; i++) {
            int foo = nxt(i);
            if (__gcd(a[i], a[foo]) == 1) {
                be_delete.insert(i);
                i++;
            }
        }
        // for (int e : be_delete) cout << e << endl;
        while (!be_delete.empty()) {
            set<int> new_delete;
            int prev = -1;
            for (int e : be_delete) {
                // cout << e << endl;
                // cout << e << ' ' << nxt(e) << endl;
                int foo = nxt(e);
                res.push_back(foo);
                current_id.erase(foo);
            }
            for (int e : be_delete) {
                if (current_id.count(e) == 0) continue;
                if (prev == e) continue;
                int foo = nxt(e);
                // cout << e << ' ' << nxt(e) << endl;
                if (__gcd(a[foo], a[e]) == 1) {
                    new_delete.insert(e);
                    prev = foo;
                }
            }
            be_delete = new_delete;
        }
        cout << res.size() << ' ';
        for (int e : res) cout << e + 1 << ' ';
        cout << '\n';
    }

    return 0;
}