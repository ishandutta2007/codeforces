#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    int a[n], k[q];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int p[n];
    partial_sum(a, a + n, p);
    int sum = p[n - 1];
    int cur = 0;
    for(int i = 0; i < q; i++ ){
        cin >> k[i];
        if(cur + k[i] >= sum) {
            cout << n << endl;
            cur = 0;
        } else {
            cur += k[i];
            cout << n - (upper_bound(p, p + n, cur) - p) << endl;
        }
    }
    return 0;
}