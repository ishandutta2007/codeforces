#include <bits/stdc++.h>

using namespace std;
int bin(vector <int> &a, int x) {
    int l = -1, r = a.size();
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (a[m] <= x) {
            r = m;
        }
        else {
            l = m;
        }
    }
    return r;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector <int> a(n), c(k);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }
    for (int i = 0; i < k; ++i) {
        cin >> c[i];
    }
    sort(a.begin(), a.end());
    vector <int> kol(n);
    vector <vector <int>> ans(n);
    int maxx = 0;
    for (int i = n - 1; i >= 0; --i) {
        int cha = bin(kol, c[a[i]] - 1);
        ++kol[cha];
        ans[cha].push_back(a[i] + 1);
        maxx = max(maxx, cha + 1);
    }
    cout << maxx << "\n";
    for (int i = 0; i < maxx; ++i) {
        cout << ans[i].size() << " ";
        for (int j : ans[i]) {
            cout << j << " ";
        }
        cout << "\n";
    }
    return 0;
}