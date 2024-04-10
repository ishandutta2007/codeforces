#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int &e : a) cin >> e;
    vector<vector<int>> segs;
    vector<int> cur = {a[0]};
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1]) {
            segs.push_back(cur);
            cur.clear();
            cur.push_back(a[i]);
        } else cur.push_back(a[i]);
    }
    segs.push_back(cur);   

    vector<vector<int>> pos(n + 1);
    for (int i = 0; i < segs.size(); i++) {
        pos[segs[i][0]].push_back(i + 1);
    }

    vector<pair<int, int>> d;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < pos[i].size(); j++) {
            d.push_back({pos[i][j - 1], pos[i][j]});
        }
    }

    sort(d.begin(), d.end(), [](pair<int, int> x, pair<int, int> y) {
        return x.second < y.second;
    });
    vector<int> dp(n + 1, 0);
    int id = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];
        while (id < d.size() && d[id].second <= i) {
            dp[i] = max(dp[i], dp[d[id].first + 1] + 1);
            id++;
        }
    }

    cout << segs.size() - dp[n] << endl;

    return 0;
}