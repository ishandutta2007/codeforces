#include <bits/stdc++.h>

using namespace std;
//#define int long long
int ans = 0;
const int INF = 1e9;

void dfs(vector <int> &a, vector <bool> &used, vector <int> &res, int v) {
    used[v] = true;
    ++ans;
    if (!used[a[v]]) {
        dfs(a, used, res, a[v]);
    }
    res[v] = ans;
}

signed main() {
    int q;
    cin >> q;
    for (int w = 0; w < q; ++w) {
        int n;
        cin >> n;
        vector <int> a(n);
        vector <bool> used(n, false);
        vector <int> res(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            --a[i];
        }
        for (int i = 0; i < n; ++i) {
            ans = 0;
            if (!used[i]) {
                dfs(a, used, res, i);
            }
        }
        for (int i = 0; i < n; ++i) {
            cout << res[i] << " ";
        }
        cout << "\n";
    }
}