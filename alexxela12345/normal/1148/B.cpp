#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 1e18;

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, ta, tb, k;
    cin >> n >> m >> ta >> tb >> k;
    vector<int> arr1(n);
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }
    vector<int> arr2(m);
    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }

    int l = 0;
    int r = 0;
    int max_time = -INF;
    if (k >= min(n, m)) {
        max_time = INF;
    }
    while (l < n && l <= k) {
        while (r < m && arr2[r] - arr1[l] < ta) {
            r++;
        }
        if (r + k - l >= m) {
            max_time = INF;
        } else {
            max_time = max(max_time, arr2[r + k - l] + tb);
        }
        l++;
    }
    if (max_time == INF) {
        max_time = -1;
    }
    cout << max_time << endl;
}