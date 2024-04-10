//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,abm,mmx,avx,avx2,popcnt,tune=native")
//#pragma GCC optimize("fast-math")

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) (x).begin(), (x).end()
//#define int ll
//#define double ld

signed main() {
    int n, m;
    cin >> n >> m;
    vector<int> deg(n);
    vector<vector<int>> grev(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        deg[a]++;
        grev[b].push_back(a);
    }
    set<int> s;
    for (int i = 0; i < n; i++) {
        if (deg[i] == 0)
            s.insert(i);
    }
    int cur = n;
    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++) {
        int b = *s.rbegin();
        s.erase(b);
        ans[b] = cur--;
        for (int a : grev[b]) {
            deg[a]--;
            if (deg[a] == 0)
                s.insert(a);
        }
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << ' ';
    cout << endl;
}