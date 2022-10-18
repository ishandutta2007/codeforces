#include <bits/stdc++.h>

using namespace std;

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    map<int, int, greater<int>> a, b;
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        a[t]++;
        b[t];
    }
    for(int i = 0; i < m; i++) {
        int t;
        cin >> t;
        a[t];
        b[t]++;
    }
    int bal = 0;
    for(auto it: a) {
        int x = it.first;
        bal += a[x] - b[x];
        if(bal > 0) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}