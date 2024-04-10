#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <string>
#include <bitset>
#include <chrono>

using namespace std;
#define int long long

signed main() {
    if (0) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int n, m;
    cin >> n >> m;
    vector <pair <int, int>> w;
    for (int i = 0; i < m; ++i) {
        cout << "? ";
        for (int j = 0; j < m; ++j) {
            if (i == j) cout << "1";
            else cout << "0";
        }
        cout << endl;
        int x;
        cin >> x;
        w.emplace_back(x, i);
    }
    sort(w.begin(), w.end());
    int prev = 0, ans = 0;
    vector <bool> used(m);
    for (int i = 0; i < m; ++i) {
        used[w[i].second] = true;
        cout << "? ";
        for (int j = 0; j < m; ++j) {
            if (used[j]) cout << "1";
            else cout << "0";
        }
        cout << endl;
        int x;
        cin >> x;
        if (prev + w[i].first == x) ans += w[i].first;
        prev = x;
    }
    cout << "! " << ans << endl;
}