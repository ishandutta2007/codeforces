#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = (int)2e5 + 100;
int n, m;
void solve() {
    cin >> n >> m;
    vector<int> cnt(n + m);
    vector<int> cnt2(n + m);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int x;
            cin >> x;
            cnt[i + j] += x;
            cnt2[i + j] += 1 - x;
        }
    }
    int en = n - 1 + m - 1;
    int ans = 0;
    for(int i = 0; i < en - i; i++) {
        ans += min(cnt[i] + cnt[en - i], cnt2[i] + cnt2[en - i]);
    }
    cout << ans << "\n";
}
int main() {
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}