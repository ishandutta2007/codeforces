#include <bits/stdc++.h>

using namespace std;

#define int int64_t

void solve() {
    int n;
    cin >> n;
    int S[n];
    int ans = 0;
    int residual = 0;
    multiset<int> stops;
    for(int i = 0; i < n; i++) {
        cin >> S[i];
        int diff = S[i] - 1 - stops.size() - residual;
        ans += max<int>(0, diff);
        residual = max<int>(0, -diff);
        if(i > 0) {
            stops.insert(i - 1 + S[i - 1]);
        }
        stops.erase(i);
    }
    cout << ans << "\n";
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