#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int maxn = 1e5 + 42;
const int mod = 998244353;

void solve() {
    int n, m;
    cin >> n >> m;
    int c[n][m];
    map<int, vector<int>> cnt;
    for(int i = 0; i < n; i++) {
        int total = 0;
        for(int j = 0; j < m; j++) {
            cin >> c[i][j];
            total += c[i][j] * j;
        }
        cnt[total].push_back(i);
    }
    for(auto it: cnt) {
        for(auto jt: cnt) {
            if(it.second.size() == 1 && it != jt) {
                cout << it.second[0] + 1 << ' ' << it.first - jt.first << "\n";
            }
        }
    }
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}