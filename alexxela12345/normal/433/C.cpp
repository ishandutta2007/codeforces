#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(m);
    int best_ans = 0;
    for (int i = 0; i < m; i++) {
        cin >> arr[i];
        arr[i]--;
        if (i)
            best_ans += abs(arr[i] - arr[i - 1]);
    }
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        a = b = c = arr[i];
        if (i != 0) {
            a = arr[i - 1];
        }
        if (i != m - 1) {
            c = arr[i + 1];
        }
        if (a != b) {
            g[b].push_back(a);
        }
        if (b != c) {
            g[b].push_back(c);
        }
    }
    int was_ans = best_ans;
    for (int i = 0; i < n; i++) {
        if (g[i].empty())
            continue;
        sort(g[i].begin(), g[i].end());
        int was = 0;
        int nw = 0;
        int x = g[i][g[i].size() / 2];
        for (int j : g[i]) {
            was += abs(j - i);
            nw += abs(x - j);
        }
        best_ans = min(best_ans, was_ans - was + nw);
    }
    cout << best_ans << endl;
}