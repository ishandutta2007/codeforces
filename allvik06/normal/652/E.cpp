#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> a;
vector<vector <int>> g;
vector<bool> used, s1;
vector<int> fup, tin, st, ans;
int tim = 0, k = 0;

void dfs(int v, int p) {
    st.push_back(v);
    used[v] = true;
    tin[v] = tim;
    ++tim;
    fup[v] = tin[v];
    for (int i : a[v]) {
        if (i == p) continue;
        if (!used[i]) {
            int lol = st.size();
            dfs(i, v);
            fup[v] = min(fup[v], fup[i]);
            if (fup[i] > tin[v]) {
                while (st.size() > lol) {
                    ans[st.back()] = k;
                    st.pop_back();
                }
                ++k;
            }
        } else {
            fup[v] = min(fup[v], tin[i]);
        }
    }
}

int flag = 0;
map <pair <int, int>, int> s2;
void dfs1(int v, int u) {
    used[v] = true;
    if (s1[v]) ++flag;
    if (v == u) {
        if (flag > 0) {
            cout << "YES";
        } else {
            cout << "NO";
        }
        exit(0);
    }
    for (int i : g[v]) {
        if (!used[i]) {
            if (s2[{i, v}] == 1 || s2[{v, i}] == 1) ++flag;
            dfs1(i, u);
            if (s2[{i, v}] == 1 || s2[{v, i}] == 1) --flag;
        }
    }
    if (s1[v]) --flag;
}

signed main() {
    int n, m;
    cin >> n >> m;
    a.resize(n);
    vector<pair<int, int>> lol;
    for (int i = 0; i < m; ++i) {
        int x, y, flag1;
        cin >> x >> y >> flag1;
        --x;
        --y;
        if (flag1 == 1) {
            lol.emplace_back(x, y);
        }
        a[x].push_back(y);
        a[y].push_back(x);
    }
    used.resize(n);
    ans.resize(n);
    tin.resize(n);
    ans.resize(n);
    fup.resize(n);
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    dfs(0, -1);
    while (!st.empty()) {
        ans[st.back()] = k;
        st.pop_back();
    }
    ++k;
    /*if (ans[u] == ans[v]) {
        for (pair <int, int> r : lol) {
            if (ans[r.first] == ans[r.second] && ans[r.first] == ans[u]) {
                cout << "YES";
                return 0;
            }
        }
        cout << "NO";
        return 0;
    }*/
    g.resize(k);
    for (int i = 0; i < n; ++i) {
        for (int j : a[i]) {
            g[ans[i]].push_back(ans[j]);
        }
    }
    s1.resize(k);
    for (pair <int, int> r : lol) {
        if (ans[r.first] == ans[r.second]) {
            s1[ans[r.first]] = true;
        }
    }
    //int cha = 0;
    for (pair <int, int> r : lol) {
        if (ans[r.first] != ans[r.second]) {
            s2[{ans[r.first], ans[r.second]}] = 1;
        }
    }
    used.assign(k, false);
    st.clear();
    dfs1(ans[u], ans[v]);
    cout << "NO";
    return 0;
}