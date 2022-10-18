#include <bits/stdc++.h>

using namespace std;

#define int int64_t

int ask(int m, vector<int> e) {
    string ans(m, '0');
    for(auto it: e) {
        ans[it] = '1';
    }
    cout << "? " << ans << endl;
    int res;
    cin >> res;
    return res;
}

void solve() {
    int n, m;
    cin >> n >> m;
    int w[m];
    for(int i = 0; i < m; i++) {
        w[i] = ask(m, {i});
    }
    int p[m];
    iota(p, p + m, 0);
    sort(p, p + m, [&](int a, int b) {return w[a] < w[b];});
    vector<int> cur;
    int prev = 0;
    int ans = 0;
    for(int i = 0; i < m; i++) {
        cur.push_back(p[i]);
        int r = ask(m, cur);
        if(r - prev == w[p[i]]) {
            ans += w[p[i]];
            prev = r;
        } else {
            cur.pop_back();
        }
    }
    cout << "! " << ans << endl;
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }
}