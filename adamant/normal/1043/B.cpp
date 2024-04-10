#include <bits/stdc++.h>

using namespace std;
#define link alflak
#define fpos ladla
#define all(x) begin(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define int int64_t

const int maxn = 1e5 + 42;

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n + 1];
    a[0] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> ans;
    for(int k = 1; k <= n; k++) {
        int x[k];
        bool ok = true;
        for(int i = 1; i <= n; i++) {
            if(i - 1 < k) {
                x[(i - 1) % k] = a[i] - a[i - 1];
            } else {
                ok &= x[(i - 1) % k] == a[i] - a[i - 1];
            }
        }
        if(ok) {
            ans.push_back(k);
        }
    }
    cout << ans.size() << endl;
    for(auto it: ans) {
        cout << it << ' ';
    }
    return 0;
}