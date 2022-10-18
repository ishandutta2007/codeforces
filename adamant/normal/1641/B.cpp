#include <bits/stdc++.h>

using namespace std;

#define int int64_t

void solve() {
    int n;
    cin >> n;
    int a[n];
    map<int, vector<int>> pos;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }
    for(auto it: pos) {
        if(it.second.size() % 2) {
            cout << -1 << "\n";
            return;
        }
    }
    vector<pair<int, int>> pc;
    vector<int> t;
    for(int i = 0; i < n; i++) {
        int j = max_element(a + i, a + n) - a;
        for(int k = 0; k < n - j; k++) {
            pc.push_back({j + k, a[n - k - 1]});
        }
        reverse(a + j, a + n);
        t.push_back(2 * (n - j));
        for(int k = 0; k < n - i; k++) {
            pc.push_back({i + k, a[n - k - 1]});
        }
        reverse(a + i, a + n);
        t.push_back(2 * (n - i));
    }
    cout << pc.size() << "\n";
    for(auto [p, c]: pc) {
        cout << p << ' ' << c << "\n";
    }
    for(int i = 0; i < n; i += 2) {
        t.push_back(2);
    }
    reverse(begin(t), end(t));
    cout << t.size() << "\n";
    for(auto it: t) {
        cout << it << ' ';
    }
    cout << "\n";
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}