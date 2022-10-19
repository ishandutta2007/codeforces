#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <array>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;
const int MAXN = 4e5;
const int MAXL = MAXN * 4;
vector <int> g[MAXL];
vector <int> gg[MAXL];
int used[MAXL];
int pr[MAXN];
int tin[MAXN];
int tout[MAXN];
vector <int> st;

void init(int v, int& cur) {
    tin[v] = cur;
    ++cur;
    for (int i : g[v]) {
        if (i == pr[v]) continue;
        pr[i] = v;
        init(i, cur);
    }
    tout[v] = cur;
    ++cur;
}

void dfs(int x, int y) {
    while (true) {
        st.push_back(x);
        if (tin[x] <= tin[y] && tin[y] <= tout[x]) break;
        x = pr[x];
    }
    vector <int> tmp;
    while (y != x) {
        tmp.push_back(y);
        y = pr[y];
    }
    while (!tmp.empty()) {
        st.push_back(tmp.back());
        tmp.pop_back();
    }
}

void top_sort(int v) {
    used[v] = 1;
    for (int i : gg[v]) {
        if (used[i]) continue;
        top_sort(i);
    }
    st.push_back(v);
}

void dfs1(int v, int cur) {
    used[v] = cur;
    for (int i : g[v]) {
        if (used[i] == -1) {
            dfs1(i, cur);
        }
    }
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int n, q;
    cin >> n >> q;
    string s;
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y; --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    pr[0] = -1;
    int now = 0;
    init(0, now);
    vector <pair <char, char>> sym(n, make_pair('a' - 1, 'a' - 1));
    vector <pair <int, int>> all(q);
    vector <string> all_s(q);
    for (int i = 0; i < q; ++i) {
        int x, y;
        cin >> x >> y; --x; --y;
        cin >> s;
        all[i] = make_pair(x, y);
        all_s[i] = s;
        dfs(x, y);
        for (int j = 0; j < (int)s.size(); ++j) {
            sym[st[j]].first = s[j];
        }
        reverse(st.begin(), st.end());
        for (int j = 0; j < (int)s.size(); ++j) {
            sym[st[j]].second = s[j];
        }
        st.clear();
    }
    int m = n * 2 + q * 2;
    for (int i = 0; i < q; ++i) {
        int x = all[i].first, y = all[i].second;
        s = all_s[i];
        dfs(x, y);
        for (int j = 0; j < (int)s.size(); ++j) {
            int v = st[j];
            if (sym[v].first != s[j]) {
                gg[n * 2 + 2 * i + 1].push_back(v * 2);
                gg[v * 2 + 1].push_back(n * 2 + 2 * i);
            }
            if (sym[v].second != s[j]) {
                gg[n * 2 + 2 * i + 1].push_back(v * 2 + 1);
                gg[v * 2].push_back(n * 2 + 2 * i);
            }
        }
        reverse(st.begin(), st.end());
        for (int j = 0; j < (int)s.size(); ++j) {
            int v = st[j];
            if (sym[v].first != s[j]) {
                gg[n * 2 + 2 * i].push_back(v * 2);
                gg[v * 2 + 1].push_back(n * 2 + 2 * i + 1);
            }
            if (sym[v].second != s[j]) {
                gg[n * 2 + 2 * i].push_back(v * 2 + 1);
                gg[v * 2].push_back(n * 2 + 2 * i + 1);
            }
        }
        st.clear();
    }
    for (int i = 0; i < n; ++i) g[i].clear();
    for (int i = 0; i < m; ++i) {
        for (int j : gg[i]) {
            g[j].push_back(i);
        }
    }
    for (int i = 0; i < m; ++i) {
        if (used[i] == 0) top_sort(i);
    }
    reverse(st.begin(), st.end());
    for (int i = 0; i < m; ++i) used[i] = -1;
    int cur = 0;
    for (int i : st) {
        if (used[i] == -1) {
            dfs1(i, cur);
            ++cur;
        }
    }
    vector <char> ans(n);
    for (int i = 0; i < m; i += 2) {
        if (used[i] == used[i + 1]) {
            cout << "NO";
            return 0;
        }
        if (i < n * 2 && used[i] < used[i + 1]) {
            ans[i / 2] = sym[i / 2].first;
        } else if (i < n * 2) {
            ans[i / 2] = sym[i / 2].second;
        }
        if (i < n * 2) ans[i / 2] = max(ans[i / 2], 'a');
    }
    cout << "YES\n";
    for (char i : ans) {
        cout << i;
    }
}