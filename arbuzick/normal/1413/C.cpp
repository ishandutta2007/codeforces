#include <bits/stdc++.h>
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int m = 6;
    vector<int> a2(m);
    for (int i = 0; i < m; ++i)
        cin >> a2[i];
    int n;
    cin >> n;
    vector<int> b2(n);
    for (int i = 0; i < n; ++i)
        cin >> b2[i];
    vector<vector<int>> a(n, vector<int>(m));
    vector<int> b(n*m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            a[i][j] = b2[i]-a2[j], b[i*m+j] = a[i][j];
    sort(all(b));
    b.resize(unique(all(b))-b.begin());
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            a[i][j] = lower_bound(all(b), a[i][j])-b.begin();
        }
        sort(all(a[i]));
        a[i].resize(unique(all(a[i]))-a[i].begin());
    }
    vector<vector<int>> used(b.size());
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < a[i].size(); ++j)
            used[a[i][j]].pb(i);
    vector<int> c(n);
    int ans = b.back()-b[0], m3 = 0;
    int m1 = 0, m2 = 0;
    for (int i = 0; i < n; ++i)
        m2 = max(m2, a[i][0]);
    ans = min(ans, b[m2]-b[m1]);
    for (int i = 1; i < b.size(); ++i) {
        m1 = i;
        bool br = 0;
        for (auto j: used[i-1]) {
            if (c[j]+1 == a[j].size()) {
                br = 1;
                break;
            }
            c[j]++;
            m2 = max(m2, a[j][c[j]]);
        }
        if (br)
            break;
        if (b[m2]-b[m1] < ans)
            ans = b[m2]-b[m1], m3 = m1;
    }
    cout << ans;
    return 0;
}