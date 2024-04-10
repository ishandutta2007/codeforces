#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cassert>
#include <map>

using namespace std;
#define int long long

signed main() {
    if (0) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int l = 0, r = n - 1;
        while (l != r) {
            int m = (l + r) / 2;
            cout << "? " << l + 1 << " " << m + 1 << endl;
            int len = m - l + 1;
            vector<int> ans(len);
            for (int i = 0; i < len; ++i) cin >> ans[i];
            int cnt = 0;
            for (int &i: ans) {
                i--;
                if (i < l || i > m) ++cnt;
            }
            if ((len - cnt) % 2 == 1) r = m;
            else l = m + 1;
        }
        cout << "! " << l + 1 << endl;
    }
}

/*

 */