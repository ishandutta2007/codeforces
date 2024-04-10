#include <iostream>
#include <vector>
#include <set>
#include <chrono>
#include <map>
#include <algorithm>

using namespace std;

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        set <string> all;
        vector <string> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        bool ok = false;
        for (int i = 0; i < n; ++i) {
            string s = a[i];
            string rev_s = s;
            reverse(rev_s.begin(), rev_s.end());
            if (s == rev_s) ok = true;
            if (all.count(rev_s)) ok = true;
            all.insert(s);
            if ((int)s.size() == 3) {
                rev_s.pop_back();
                if (all.count(rev_s)) ok = true;
            }
        }
        all.clear();
        for (int i = n - 1; i >= 0; --i) {
            string s = a[i];
            string rev_s = s;
            reverse(rev_s.begin(), rev_s.end());
            if (s == rev_s) ok = true;
            if (all.count(rev_s)) ok = true;
            all.insert(s);
            if ((int)s.size() == 3) {
                s.pop_back();
                rev_s = s;
                reverse(rev_s.begin(), rev_s.end());
                if (all.count(rev_s)) ok = true;
            }
        }
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
}