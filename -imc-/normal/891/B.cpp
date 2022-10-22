#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;
using ld = long double;

vector<pair<int, int>> a;

void solve(bool /*read*/) {
    int n;
    cin >> n;
    
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    
    sort(all(a));
    auto a_sorted = a;
    
    rotate(a.begin(), a.begin() + 1, a.end());
    
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
        ans[a_sorted[i].second] = a[i].first;
    
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int nt = 1;
    //cin >> nt;
    for (int i = 0; i < nt; i++)
        solve(true);
    
    return 0;
}