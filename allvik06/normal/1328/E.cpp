#include <bits/stdc++.h>

using namespace std;
vector <vector <int>> a;
vector <int> p, h, tin, tout;
vector <bool> used;
int cha = 0;

void dfs(int v) {
    used[v] = true;
    tin[v] = cha;
    ++cha;
    for (int i : a[v]) {
        if (!used[i]) {
            p[i] = v;
            h[i] = h[v] + 1;
            dfs(i);
        }
    }
    tout[v] = cha;
    ++cha;
}

bool cmp(int x, int y) {
    return h[x] < h[y];
}
signed main() {
    int n, m;
    cin >> n >> m;
    a.resize(n);
    p.resize(n);
    h.resize(n);
    used.resize(n);
    tin.resize(n);
    tout.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        a[x - 1].push_back(y - 1);
        a[y - 1].push_back(x - 1);
    }
    dfs(0);
    while (m--) {
        if (m == 1) {
            int lol = 1;
        }
        int k;
        cin >> k;
        vector <int> b(k);
        for (int i = 0; i < k; ++i) {
            int x;
            cin >> x;
            b[i] = p[x - 1];
        }
        sort(b.begin(), b.end(), cmp);
        bool flag = true;
        for (int i = 0; i < k - 1; ++i) {
            if (tin[b[i]] <= tin[b[i + 1]] && tout[b[i]] >= tout[b[i + 1]]) {
                continue;
            }
            flag = false;
            break;
        }
        if (flag) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    return 0;
}