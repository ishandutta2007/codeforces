#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define pb emplace_back
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> col(n);
    map<int, vector<int>> ma;
    for (int i = 0; i < n; i++) {
        cin >> col[i];
        ma[col[i]].pb(i);
    }
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b; a--; b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    int ans = -1, ansc = -1;
    for (auto &c : ma) {
        int nowc = c.first;
        set<int> s;
        for (auto &v : c.second) {
            for (auto &to : g[v]) {
                if (col[to] != nowc) s.insert(col[to]);
            }
        }
        if ((int)s.size() > ans) {
            ans = s.size();
            ansc = nowc;
        }
    }
    cout << ansc;
    return 0;
}