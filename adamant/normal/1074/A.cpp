#include <bits/stdc++.h>

using namespace std;
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define int int64_t

const int maxn = 2e5 + 42;
const int inf = 1e9;

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int x[n];
    for(int i = 0; i < n; i++) {
        cin >> x[i];
    }
    sort(x, x + n);
    int l[m], r[m], y[m];
    vector<int> pr;
    for(int i = 0; i < m; i++) {
        cin >> l[i] >> r[i] >> y[i];
        if(l[i] == 1) {
            pr.push_back(r[i]);
        }
    }
    sort(all(pr));
    int ans = n + m;
    for(int i = 0; i <= n; i++) {
        int lim = i == n ? inf : x[i];
        int need_del = end(pr) - lower_bound(all(pr), lim);
        ans = min(ans, need_del + i);
    }
    cout << ans << endl;
    return 0;
}