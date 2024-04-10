#include <bits/stdc++.h>

using namespace std;
vector <vector <pair <int, int>>> a;
vector <int> ans;
vector <bool> used;
void dfs(int v) {
    used[v] = true;
    bool flag = true;
    for (auto i : a[v]) {
        if (!used[i.first]) {
            flag = false;
            dfs(i.first);
        }
    }
    if (flag) {
        ans.push_back(v);
    }
}

vector <int> st;
bool dfs1(int v, int u) {
    if (v == u) {
        return true;
    }
    used[v] = true;
    for (auto i : a[v]) {
        if (!used[i.first]) {
            st.push_back(i.second);
            if (dfs1(i.first, u)) {
                return true;
            }
            st.pop_back();
        }
    }
    return false;
}
signed main() {
    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        a[x - 1].emplace_back(y - 1, i);
        a[y - 1].emplace_back(x - 1, i);
    }
    used.resize(n);
    dfs(0);
    if (ans.size() < 2) {
        for (int i = 0; i < n - 1; ++i) {
            cout << i << "\n";
        }
        return 0;
    }
    vector <bool> now(n - 1);
    used.assign(n, false);
    dfs1(ans[0], ans[1]);
    for (int i : st) {
        now[i] = true;
    }
    vector <int> res(n - 1, -1);
    res[a[ans[0]][0].second] = 0;
    res[a[ans[1]][0].second] = 1;
    int l = 2;
    for (int i = 0; i < n - 1; ++i) {
        if (!now[i]) {
            res[i] = 2;
            l = 3;
            break;
        }
    }
    for (int i = 0; i < n - 1; ++i) {
        if (res[i] == -1) {
            cout << l << "\n";
            ++l;
        }
        else {
            cout << res[i] << "\n";
        }
    }
    return 0;
}