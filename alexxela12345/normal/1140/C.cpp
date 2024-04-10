#include <bits/stdc++.h>
#define _ << " " <<
#define int long long

using namespace std;

main() {
    int k, n;
    cin >> n >> k;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].second >> arr[i].first;
    }
    sort(arr.begin(), arr.end());
    multiset<int> cur;
    int cur_s = 0;
    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (cur.size() < k) {
            cur.insert(arr[i].second);
            cur_s += arr[i].second;
        } else {
            cur_s -= *cur.begin();
            cur.erase(cur.begin());
            cur_s += arr[i].second;
            cur.insert(arr[i].second);
        }
        ans = max(ans, cur_s * arr[i].first);
    }
    cout << ans << endl;
}