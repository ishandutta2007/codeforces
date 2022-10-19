#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

using namespace std;

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int sum = 0;
        for (char c : s) {
            if (c == '1') ++sum;
        }
        if (sum % 2 == 1) {
            cout << "NO\n";
            continue;
        }
        if (sum < 2) {
            cout << "NO\n";
            continue;
        }
        int root = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') root = i;
        }
        vector <bool> ed(n);
        for (int i = 0; i < n; ++i) ed[i] = true;
        ed[root - 1] = false;
        vector <pair <int, int>> edges;
        int cur0 = (root + 1) % n, cur1 = root - 1;
        while (true) {
            while (cur0 != cur1) {
                if (s[cur0] == '1') break;
                cur0 = (cur0 + 1) % n;
            }
            if (cur0 == cur1) break;
            while (cur0 != cur1) {
                if (s[cur1] == '0' && cur1 == root - 1) break;
                if (s[cur1] == '1' && cur1 != root - 1) break;
                cur1 = (cur1 + n - 1) % n;
            }
            ed[(cur0 + n - 1) % n] = false;
            edges.emplace_back((cur0 + n - 1) % n, cur1);
            cur1 = (cur1 + n - 1) % n;
            if (cur0 == cur1) break;
            cur0 = (cur0 + 1) % n;
            if (cur0 == cur1) break;
        }
        for (int i = 0; i < n; ++i) {
            if (ed[i]) edges.emplace_back(i, (i + 1) % n);
        }
        cout << "YES\n";
        for (auto i : edges) {
            cout << i.first + 1 << " " << i.second + 1 << "\n";
        }
    }
}