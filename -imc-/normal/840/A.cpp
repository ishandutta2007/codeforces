#include <bits/stdc++.h>

#define all(v) (v).begin(), (v).end()

using namespace std;

using li = long long;

void solve() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i].first;
        b[i].second = i;
    }
    
    sort(all(a));
    sort(b.rbegin(), b.rend());
    
    vector<int> bInv(n);
    for (int i = 0; i < n; i++)
        bInv[b[i].second] = i;
    
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        ans[i] = a[bInv[i]].first;
        cout << ans[i] << " ";
    }
    cout << "\n";
}

int main() {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
    solve();
    
    return 0;
}