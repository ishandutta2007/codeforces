#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        s[i]--;
    }
    vector<int> iz(n);
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        iz[x - 1] = 1;
    }
    vector<vector<pair<int, int>>> sch(m);
    for (int i = 0; i < n; i++) {
        sch[s[i]].push_back({-p[i], i});
    }
    for (int i = 0; i < m; i++) {
        sort(sch[i].begin(), sch[i].end());
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 1; j < sch[i].size(); j++) {
            if (iz[sch[i][j].second]) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}