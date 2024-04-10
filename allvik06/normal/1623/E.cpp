#include <iostream>
#include <vector>

using namespace std;
int n, k, cur = 0;
string s, r;
vector <int> bl;
vector <pair <int, int>> g;
vector <bool> c;

void make_r(int v) {
    if (g[v].first != -1) make_r(g[v].first);
    r += s[v];
    if (c[v]) r += s[v];
    if (g[v].second != -1) make_r(g[v].second);
}

bool find_ans(int v, int cnt_l = 0, bool ok = true) {
    bool l = false;
    ++cnt_l;
    if (g[v].first != -1) {
        l = find_ans(g[v].first, cnt_l, ok);
    }
    if (((bl[cur] != n && r[bl[cur]] > r[cur] && k >= cnt_l) || l) && ok) {
        c[v] = true;
        k--;
        l = true;
    }
    ++cur;
    if (g[v].second != -1) {
        find_ans(g[v].second, cnt_l - 1, ok && c[v]);
    }
    return l;
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    cin >> n >> k >> s;
    g.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> g[i].first >> g[i].second; --g[i].first; --g[i].second;
    }
    c.resize(n);
    make_r(0);
    bl.resize(n, n);
    for (int i = n - 2; i >= 0; --i) {
        if (r[i + 1] == r[i]) bl[i] = bl[i + 1];
        else bl[i] = i + 1;
    }
    find_ans(0);
    r.clear();
    make_r(0);
    cout << r;
}