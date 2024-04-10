#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> a(n * k);
    for (int &e : a) cin >> e, e--;
    vector<vector<int>> pos(n);
    int len = n / (k - 1) + (n % (k - 1) > 0);
    for (int i = 0; i < n * k; i++) {
        pos[a[i]].push_back(i);
    }
    vector<pair<int, int>> res;
    while (pos.size() > 0) {
        sort(pos.begin(), pos.end(), [](vector<int> a, vector<int> b) {
            assert(a.size() > 1);
            assert(b.size() > 1);
            return a[1] < b[1];
        });
        vector<vector<int>> new_pos;
        for (int i = 0; i < min<int>(len, pos.size()); i++) {
            res.emplace_back(pos[i][0], pos[i][1]);
        }
        for (int i = len; i < pos.size(); i++) {
            vector<int> tmp;
            assert(pos[i].size() > 0);
            for (int j = 1; j < pos[i].size(); j++) tmp.push_back(pos[i][j]);
            new_pos.push_back(tmp);
        }
        pos = new_pos;
    }
    assert(res.size() == n);
    sort(res.begin(), res.end(), [&](auto x, auto y) {
        // cout << x.first << ' ' << y.first << ' ' << a[x.first - 1] << ' ' << a[y.first - 1] << endl;
        // cout << x.first << ' ' << x.second << endl;
        // cout << y.first << ' ' << y.second << endl;
        return a[x.first] < a[y.first];
    });
    for (auto e : res) {
        cout << e.first + 1 << ' ' << e.second + 1 << '\n';
    }

    return 0;
}