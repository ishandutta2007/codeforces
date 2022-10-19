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
        vector <int> cnt(n), now(n);
        vector <int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i : a) {
            if (i < n) ++cnt[i];
        }
        vector <int> ans;
        for (int i = 0; i < n; ++i) {
            int mex = n;
            for (int j = 0; j < n; ++j) {
                if (cnt[j] == 0) {
                    mex = j;
                    break;
                }
            }
            ans.push_back(mex);
            if (mex == 0) {
                continue;
            }
            int cha = 0;
            for (; i < n; ++i) {
                if (a[i] >= n) continue;
                ++now[a[i]];
                --cnt[a[i]];
                if (now[a[i]] == 1 && a[i] < mex) ++cha;
                if (cha == mex) break;
            }
            for (int j = 0; j < mex; ++j) now[j] = 0;
        }
        cout << (int)ans.size() << "\n";
        for (int i : ans) cout << i << " ";
        cout << "\n";
    }
}