#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    if (n % 2) {
        cout << -1 << '\n';
        return ;
    }

    vector<pair<int, int>> sol;
    for (int i =0; i < n; i += 2) {
        if (a[i] == a[i+1])
            sol.emplace_back(i, i+1);
        else {
            sol.emplace_back(i, i);
            sol.emplace_back(i+1, i+1);
        }
    }
    cout << sol.size() << '\n';
    for (auto [l, r] : sol)
        cout << l + 1 << ' ' << r + 1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}