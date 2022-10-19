#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int & i : a)
        cin >> i;
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++) {
            int cnt0 = count(a.begin() + i, a.begin() + j + 1, 0);
            ans += j - i + 1 + cnt0;
        }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}