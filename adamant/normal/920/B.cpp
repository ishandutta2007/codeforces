#include <bits/stdc++.h>

using namespace std;

void solve() {
    const int maxn = 5e3 + 42;
    int n;
    cin >> n;
    int l[n], r[n];
    vector<int> in[maxn], out[maxn];
    for(int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
        in[l[i]].push_back(i);
        out[r[i]].push_back(i);
    }
    int ans[n];
    memset(ans, 0, sizeof(ans));
    set<pair<int, int>> student;
    for(int i = 0; i < maxn; i++) {
        for(auto it: in[i]) {
            student.insert({l[it], it});
        }
        if(student.size()) {
            int x = begin(student)->second;
            ans[x] = i;
            student.erase(begin(student));
        }
        for(auto it: out[i]) {
            student.erase({l[it], it});
        }
    }
    for(int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;
    
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
    return 0;
}