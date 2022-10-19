#include <bits/stdc++.h>

using namespace std;
vector <bool> used;
vector <vector <int>> a;

int minn = 1, maxx;
struct trio {
    bool nec, c, l;
};
trio dfs(int v) {
    used[v] = true;
    int now = 0;
    bool nec = false, c = false;
    for (int i : a[v]) {
        if (used[i]) continue;
        trio tmp = dfs(i);
        if (tmp.l) ++now;
        if (tmp.nec) c = true;
        if (tmp.c) nec = true;
    }
    if (nec && c) minn = 3;
    maxx -= max(now - 1, 0);
    if (a[v].size() == 1) return {false, true, true};
    else return {nec, c, false};
}

signed main() {
    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        a[x - 1].push_back(y - 1);
        a[y - 1].push_back(x - 1);
    }
    used.resize(n);
    maxx = n - 1;
    int st = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i].size() != 1) {
            st = i;
            break;
        }
    }
    trio cha = dfs(st);
    cout << minn << " " << maxx;
    return 0;
}