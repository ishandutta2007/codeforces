#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector <char> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector <vector <int>> ans;
    int maxx = 0;
    while (true) {
        vector <int> tmp;
        for (int i = 0; i < n - 1; ++i) {
            if (a[i] == 'R' && a[i + 1] == 'L') {
                tmp.push_back(i);
                swap(a[i], a[i + 1]);
                ++i;
                ++maxx;
            }
        }
        if (tmp.empty()) break;
        ans.push_back(tmp);
    }
    if (k < ans.size() || k > maxx) {
        cout << -1;
        return 0;
    }
    for (int i = 0; i < ans.size(); ++i) {
        if (maxx - ans[i].size() >= k - 1) {
            cout << ans[i].size() << " ";
            for (int j : ans[i]) {
                cout << j + 1 << " ";
            }
            cout << "\n";
            maxx -= ans[i].size();
            --k;
            continue;
        }
        cout << 1 << " " << ans[i].back() + 1 << "\n";
        --k;
        --maxx;
        ans[i].pop_back();
        if (!ans.empty()) --i;
    }
    return 0;
}