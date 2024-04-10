#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> children;
vector<int> op;

int dfs(int v) {
    vector<int> ans;
    for (int u : children[v]) {
        ans.push_back(dfs(u));
    }
    if (ans.size() == 0) {
        return 1;
    }
    if (op[v] == 0) {
        int anss = 0;
        for (int el : ans) {
            anss += el;
        }
        return anss;
    } else {
        int maxx = 1e9;
        for (int el : ans) {
            maxx = min(maxx, el);
        }
        if (children[v].size() == 0) {
            maxx = 1;
        }
        return maxx;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    children.resize(n);
    op.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> op[i];
    }
    for (int i = 1; i < n; i++) {
        int parent;
        cin >> parent;
        parent--;
        children[parent].push_back(i);
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (!children[i].size()) {
            cnt++;
        }
    }
    cout << 1 + cnt - dfs(0) << endl;
    return 0;
}