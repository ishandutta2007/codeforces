#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<int> visited(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    set<int> cur;
    visited[0] = 1;
    int vis = 1;
    vector<int> ans(1, 1);
    for (int i : g[0]) {
        if (!visited[i]) {
        cur.insert(i);
        visited[i] = 1;
        }
    }
    while (cur.size()) {
        ans.push_back(*cur.begin() + 1);
        vis += 1;
        int xx = *cur.begin();
        cur.erase(cur.begin());
        
        for (int el : g[xx]) {
            if (!visited[el]) {
            cur.insert(el);
            visited[el] = 1;
            }
        }
    }
    for (int el : ans) {
        cout << el << " ";
    }
    cout << endl;
    return 0;
}