#include <bits/stdc++.h>

using namespace std;

signed main() {
    int k;
    cin >> k;
    vector <pair <int, pair <int, int>>> a;
    for (int i = 0; i < k; ++i) {
        int n, sum = 0;
        cin >> n;
        vector <int> b(n);
        for (int j = 0; j < n; ++j) {
            cin >> b[j];
            sum += b[j];
        }
        for (int j = 0; j < n; ++j) {
            a.push_back({sum - b[j], {i + 1, j + 1}});
        }
    }
    sort(a.begin(), a.end());
    for (int i = 1; i < a.size(); ++i) {
        if (a[i].first == a[i - 1].first && a[i].second.first != a[i - 1].second.first) {
            cout << "YES\n" << a[i - 1].second.first << " " << a[i - 1].second.second << "\n" << a[i].second.first << " " <<
            a[i].second.second;
            return 0;
        }
    }
    cout << "NO";
}