#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> arr(k);
    for (int i = 0; i < k; i++) {
        cin >> arr[i];
        arr[i]--;
    }
    vector<int> first(n, INF), last(n, INF);
    for (int i = 0; i < k; i++) {
        if (first[arr[i]] == INF) {
            first[arr[i]] = i;
        }
        last[arr[i]] = k - 1 - i;
    }
    int cnt = 0;
    for (int a = 0; a < n; a++) {
        for (int b = max(0, a - 1); b <= min(a + 1, n - 1); b++) {
            if (first[a] + last[b] >= k) {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}