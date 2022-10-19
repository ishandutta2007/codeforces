#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cassert>
#include <map>

using namespace std;
#define int long long

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
        vector<int> a(n);
        int cnt1 = 0, cnt2 = 0;
        map<int, int> d;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (a[i] > 0) ++cnt1;
            else if (a[i] < 0) ++cnt2;
            ++d[a[i]];
        }
        if (cnt1 > 2 || cnt2 > 2) {
            cout << "NO\n";
            continue;
        }
        vector <int> all;
        for (auto i : d) {
            for (int j = 0; j < min(3LL, i.second); ++j) all.push_back(i.first);
        }
        bool ok = true;
        int l = (int)all.size();
        for (int i = 0; i < l; ++i) {
            for (int j = i + 1; j < l; ++j) {
                for (int k = j + 1; k < l; ++k) {
                    if (!d.count(all[i] + all[j] + all[k])) {
                        ok = false;
                        break;
                    }
                }
                if (!ok) break;
            }
            if (!ok) break;
        }
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
}

/*

 */