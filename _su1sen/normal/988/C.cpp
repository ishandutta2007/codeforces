#include<bits/stdc++.h>

using namespace std;

int main() {
    int k;
    cin >> k;
    vector<vector<int>> a(k);
    vector<int> s(k, 0);
    map<int, int> mp;
    for (int i = 0; i < k; ++i) {
        int n;
        cin >> n;
        a[i].reserve(n);
        for (int j = 0; j < n; ++j) {
            int v;
            cin >> v;
            a[i].push_back(v);
            s[i] += a[i][j];
        }
        for (int t = 0; t < n; ++t) {
            int v = s[i] - a[i][t];
            if (mp.count(v)) {
                int j = mp[v];
                for (int u = 0; u < a[j].size(); ++u) {
                    if (s[j] - a[j][u] == v) {
                        cout << "YES\n";
                        cout << i + 1 << ' ' << t + 1 << '\n';
                        cout << j + 1 << ' ' << u + 1 << '\n';
                        return 0;
                    }
                }
            }
        }
        for (int t = 0; t < n; ++t) {
            int v = s[i] - a[i][t];
            mp[v] = i;
        }
    }
    cout << "NO\n";
    return 0;
}