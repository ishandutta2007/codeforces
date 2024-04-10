#include <bits/stdc++.h>

using namespace std;
struct trio {
    int x, y, w;
};
bool flag = true;
vector <vector <pair <int, int>>> a;
vector <int> st;
vector <bool> used;
vector <int> ans;
void update(int w) {
    while (!st.empty()) {
        ans[st.back()] = max(ans[st.back()], w);
        st.pop_back();
    }
}
bool dfs(int v, int f, int w) {
    used[v] = true;
    if (v == f) {
        update(w);
        return true;
    }
    for (auto i : a[v]) {
        if (!used[i.first]) {
            st.push_back(i.second);
            if (dfs(i.first, f, w)) {
                return true;
            }
            st.pop_back();
        }
    }
    return false;
}

bool check(int w) {
    int minn = 1000001;
    bool fl = true;
    while (!st.empty()) {
        minn = min(ans[st.back()], minn);
        if (ans[st.back()] < w) {
            fl = false;
        }
        st.pop_back();
    }
    if (!fl) {
        return fl;
    }
    return minn == w;
}
bool dfs1(int v, int f, int w) {
    used[v] = true;
    if (v == f) {
        flag = check(w);
        return true;
    }
    for (auto i : a[v]) {
        if (!used[i.first]) {
            st.push_back(i.second);
            if (dfs1(i.first, f, w)) {
                return true;
            }
            st.pop_back();
        }
    }
    return false;
}
signed main() {
    int n, m;
    cin >> n;
    a.resize(n);
    used.resize(n, false);
    ans.resize(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y; --x; --y;
        a[x].emplace_back(y, i);
        a[y].emplace_back(x, i);
    }
    cin >> m;
    vector <trio> b;
    for (int i = 0; i < m; ++i) {
        int x, y, w;
        cin >> x >> y >> w;
        dfs(x - 1, y - 1, w);
        b.push_back({x - 1, y - 1, w});
        used.assign(n, false);
    }
    for (int i = 0; i < m; ++i) {
        dfs1(b[i].x, b[i].y, b[i].w);
        if (!flag) {
            cout << -1;
            return 0;
        }
        used.assign(n, false);
    }
    for (int i = 0; i < n - 1; ++i) {
        if (ans[i] == 0) {
            cout << 1 << " ";
            continue;
        }
        cout << ans[i] << " ";
    }
    return 0;
}