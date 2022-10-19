#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<vector<int>> a;
vector<int> d;
void dfs(int v) {
    for(int u: a[v])
        if (d[u] == -1) {
            d[u] = d[v] + 1;
            dfs(u);
        }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        a.assign(n, vector<int>(0));
        d.assign(n, -1);
        for (int i = 0; i < n - 1; ++i) {
            int v1, v2;
            cin >> v1 >> v2;
            a[v1 - 1].push_back(v2 - 1);
            a[v2 - 1].push_back(v1 - 1);
        }
        cout << "? " << n << ' ';
        for (int i = 1; i <= n; ++i)
            cout << i << ' ';
        cout << endl;
        int x, d1;
        cin >> x >> d1;
        d[x - 1] = 0;
        dfs(x - 1);
        int l = d1 / 2 - 1, r = n;
        int d2;
        int x2 = x;
        while (l < r - 1) {
            int m = (l + r) / 2;
            int k = 0;
            for (int i = 0; i < n; ++i)
                if (d[i] == m)
                    k++;
            if (k == 0) {
                r = m;
                continue;
            }
            cout << "? " << k << ' ';
            for (int i = 0; i < n; ++i)
                if (d[i] == m)
                    cout << i + 1 << ' ';
            cout << endl;
            cin >> x >> d2;
            if (d2 == d1) {
                l = m;
                x2 = x;
            }
            else
                r = m;
        }
        int k = 0;
        d.assign(n, -1);
        d[x2 - 1] = 0;
        dfs(x2 - 1);
        for (int i = 0; i < n; ++i)
            if (d[i] == d1)
                k++;
        cout << "? " << k << ' ';
        for (int i = 0; i < n; ++i)
            if (d[i] == d1)
                cout << i + 1 << ' ';
        cout << endl;
        int x3, d3;
        cin >> x3 >> d3;
        cout << "! " << x2 << ' ' << x3 << endl;
        string s;
        cin >> s;
        if (s == "Incorrect")
            return 0;
    }
    return 0;
}