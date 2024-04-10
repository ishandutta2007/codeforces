#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<pair<vector<int>, int>> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i].second = i;
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if (a > b) {
            swap(a, b);
        }
        arr[a].first.push_back(b - a);
        arr[b].first.push_back(n - (b - a));
    }
    for (int i = 0; i < n; i++) {
        sort(arr[i].first.begin(), arr[i].first.end());
    }
    sort(arr.begin(), arr.end());
    vector<int> classes(n);
    int cur_cl = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i].first != arr[i - 1].first) {
            cur_cl++;
        }
        classes[arr[i].second] = cur_cl;
    }
    vector<int> pref(n);
    for (int i = 1; i < n; i++) {
        int j = pref[i - 1];
        while (j > 0 && classes[i] != classes[j]) {
            j = pref[j - 1];
        }
        if (classes[j] == classes[i]) {
            j++;
        }
        pref[i] = j;
    }
    if (pref.back() * 2 >= n) {
        cout << "Yes" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}