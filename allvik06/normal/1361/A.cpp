#include <bits/stdc++.h>

using namespace std;

vector <int> col;

bool cmp(int a, int b) {
    return col[a] < col[b];
}

signed main() {
    int n, m;
    cin >> n >> m;
    vector <vector <int>> a(n);
    col.resize(n);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        a[x - 1].push_back(y - 1);
        a[y - 1].push_back(x - 1);
    }
    for (int i = 0; i < n; ++i) cin >> col[i];
    vector <int> ans(n);
    for (int i = 0; i < n; ++i) ans[i] = i;
    sort(ans.begin(), ans.end(), cmp);
    vector <bool> now(n, false);
    set <int> cha;
    for (int i = 0; i < n; ++i) cha.insert(i + 1);
    for (int i : ans) {
        for (int j : a[i]) {
            if (!now[j]) continue;
            if (col[j] == col[i]) {
                cout << -1;
                return 0;
            }
            cha.erase(col[j]);
        }
        if (*cha.begin() != col[i]) {
            cout << -1;
            return 0;
        }
        for (int j : a[i]) {
            if (!now[j]) continue;
            cha.insert(col[j]);
        }
        now[i] = true;
    }
    for (int i : ans) cout << i + 1 << " ";
}