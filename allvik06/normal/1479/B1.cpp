#include <bits/stdc++.h>

using namespace std;
#define int long long
const int INF = 1e9;

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int last1 = 0, last2 = 0;
    int ans = 0;
    vector <vector <int>> all(n + 1);
    for (int i = 0; i < n; ++i) {
        all[a[i]].push_back(i);
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] == last1) {
            if (a[i] != last2) ++ans;
            last2 = a[i];
        } else if (a[i] == last2) {
            ++ans;
            last1 = a[i];
        } else {
            auto one = lower_bound(all[last1].begin(), all[last1].end(), i);
            auto two = lower_bound(all[last2].begin(), all[last2].end(), i);
            ++ans;
            if (one == all[last1].end()) {
                last2 = a[i];
            } else if (two == all[last2].end()) {
                last1 = a[i];
            } else {
                if (*one < *two) {
                    last1 = a[i];
                } else {
                    last2 = a[i];
                }
            }
        }
    }
    cout << ans;
    return 0;
}