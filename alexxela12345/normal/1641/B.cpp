#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
// #define int ll

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        cnt[arr[i]]++;
    }
    for (auto el : cnt) {
        if (el.second % 2 == 1) {
            cout << -1 << endl;
            return;
        }
    }
    vector<pair<int, int>> ins;
    vector<int> ans1, ans2;
    int left = 0;
    while (!arr.empty()) {
        if (arr.back() == arr[arr.size() - 2]) {
            ans2.push_back(2);
            arr.pop_back();
            arr.pop_back();
            continue;
        }
        if (arr[0] != arr.back()) {
            int pos = 0;
            while (arr[pos] != arr.back()) {
                pos++;
            }
            assert(pos != (int) arr.size() - 1);
            for (int i = 0; i <= pos; i++) {
                ins.push_back({left + pos + 1 + i, arr[i]});
            }
            reverse(arr.begin(), arr.begin() + pos + 1);
            assert(arr[0] == arr.back());
            left += 2 * (pos + 1);
            ans1.push_back(2 * (pos + 1));
        }
        {
            int pos = arr.size() - 2;
            for (int i = 0; i <= pos; i++) {
                ins.push_back({left + pos + 1 + i, arr[i]});
            }
            reverse(arr.begin(), arr.begin() + pos + 1);
            left += 2 * (pos + 1);
            ans1.push_back(2 * (pos + 1));
            assert(arr.back() == arr[arr.size() - 2]);
            ans2.push_back(2);
            arr.pop_back();
            arr.pop_back();
        }
    }
    cout << ins.size() << endl;
    for (auto pp : ins) {
        cout << pp.first << " " << pp.second << endl;
    }
    reverse(ans2.begin(), ans2.end());
    for (int el : ans2) {
        ans1.push_back(el);
    }
    cout << ans1.size() << endl;
    for (int el : ans1) {
        cout << el << " ";
    }
    cout << endl;
}

// 1 3 1 3 | 3 1 1 2 2 3

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}