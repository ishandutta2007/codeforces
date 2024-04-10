#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, int>> res = {{0, 0}};
    for(int i = 1; i <= n + 1; ++i) {
        res.push_back({i, i});
        res.push_back({i, i-1});
        res.push_back({i-1, i});
    }
    cout << res.size() << '\n';
    for(auto p : res)
        cout << p.first << ' ' << p.second << '\n';
    return 0;
}