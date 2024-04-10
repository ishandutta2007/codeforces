#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)

bool is_pal(string s) {
    return s == string(s.rbegin(), s.rend());
}

const int maxn = 1e5 + 42;

vector<int> g[maxn];
int up[maxn];

void dfs(int v, int p) {
    for(auto u: g[v]) {
        if(u != p) {
            up[u] = v;
            dfs(u, v);
        }
    }
}



signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n - 1], b[n - 1];
    for(int i = 0; i < n - 1; i++) {
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
    }
    int v = 0;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(g[i].size() > g[v].size()) {
            v = i;
        }
        if(g[i].size() > 2) {
            cnt++;
        }
    }
    dfs(v, v);
    if(cnt > 1) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
        vector<pair<int, int>> ans;
        for(int i = 0; i < n; i++) {
            if(g[i].size() == 1 && i != v) {
                ans.emplace_back(v, i);
            }
        }
        cout << ans.size() << endl;
        for(auto it: ans) {
            cout << it.first + 1 << ' ' << it.second + 1 << "\n";
        }
    }
    return 0;
}