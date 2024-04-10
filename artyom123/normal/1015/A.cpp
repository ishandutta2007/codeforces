#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector <pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    vector <int> ans;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= a[j].first && i <= a[j].second) {
                break;
            }
            if (j == n - 1) {
                ans.push_back(i);
            }
        }
    }
    cout << ans.size() << "\n";
    for (auto c : ans) {
        cout << c << " ";
    }
    return 0;
}