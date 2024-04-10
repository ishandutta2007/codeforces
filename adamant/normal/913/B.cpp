#include <bits/stdc++.h>

using namespace std;

#define int int64_t

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> g[n];
    for(int i = 1; i < n; i++) {
        int p;
        cin >> p;
        g[p - 1].push_back(i);
    }
    
    for(int i = 0; i < n; i++) {
        if(g[i].size() == 0) {
            continue;
        }
        int cnt = 0;
        for(auto u: g[i]) {
            cnt += g[u].size() == 0;
        }
        if(cnt < 3) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    
    return 0;
}