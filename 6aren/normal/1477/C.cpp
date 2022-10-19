#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (auto &e : a) cin >> e.first >> e.second;

    vector<int> res;
    vector<bool> done(n, 0);
    res.push_back(0);
    int cur = 0;
    done[0] = 1;
    
    for (int i = 1; i < n; i++) {
        int id = cur;
        long long mx = 0;
        for (int j = 0; j < n; j++) {
            if (done[j]) continue;
            long long dis = 1LL * (a[j].first - a[cur].first) * (a[j].first - a[cur].first)
                                + 1LL * (a[j].second - a[cur].second) * (a[j].second - a[cur].second);
            // if (cur == 2) cout << dis << ' ' << i << '\n';
            if (dis > mx) {
                id = j;
                mx = dis;
            }
        }
        res.push_back(id);
        done[id] = 1;
        cur = id;
    }

    for (int e : res) cout << e + 1 << ' ';
    cout << '\n';

    return 0;
}