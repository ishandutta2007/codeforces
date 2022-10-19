#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int ans = 0;
    int cur = 1;
    for (int i = 0; i < n; i++) {
        if (arr[i] >= cur) {
            ans++;
            cur++;
        }
    }
    cout << ans << endl;
    return 0;
}