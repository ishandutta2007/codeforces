#include <bits/stdc++.h>

using namespace std;

#define int int64_t

void solve() {
    int n;
    cin >> n;
    int a[n + 1];
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    if(sum % n != 0) {
        cout << -1 << "\n";
    } else {
        int each = sum / n;
        vector<tuple<int, int, int>> ans;
        for(int i = 2; i <= n; i++) {
            int rem = (i - a[i] % i) % i;
            ans.emplace_back(1, i, rem);
            a[1] -= rem;
            //assert(a[1] >= 0);
            a[i] += rem;
            rem = a[i] / i;
            ans.emplace_back(i, 1, rem);
            //a[i] -= rem * i;
            //assert(a[i] == 0);
            //a[1] += rem * i;
        }
        //assert(a[1] == sum);
        for(int i = 2; i <= n; i++) {
            ans.emplace_back(1, i, each);
        }
        cout << ans.size() << "\n";
        for(auto it: ans) {
            int i, j, x;
            tie(i, j, x) = it;
            cout << i << ' ' << j << ' ' << x << "\n";
        }
    }
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