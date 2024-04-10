#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> t(k);
    for (int i = 0; i < k; ++i)
        cin >> t[i].first >> t[i].second;
    vector<int> pos;
    for (int i = 1; i <= 150; ++i) {
        bool pass = true;
        for (auto j : t) {
            if ((j.first + i - 1) / i != j.second) {
                pass = false;
                break;
            }
        }
        if (pass) pos.push_back(i);
    }
    int ans = -1;
    for (int i : pos) {
        int cur = (n + i - 1) / i;
        if (ans == -1 || cur == ans)
            ans = cur;
        else {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
}