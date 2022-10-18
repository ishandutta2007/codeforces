#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int maxn = 1e5 + 42;
const int mod = 998244353;

void solve() {
    int n, m;
    cin >> n >> m;
    int a[m];
    for(int i = 0; i < m; i++) {
        cin >> a[i];
        a[i]--;
    }
    int ans = m;
    sort(a, a + m);
    int ints[m];
    for(int i = 0; i < m; i++) {
        int A = a[i], B = a[(i + 1) % m];
        ints[i] = B - A - 1;
        if(ints[i] < 0) {
            ints[i] += n;
        }
    }
    sort(ints, ints + m, greater<int>());
    int t = 0;
    for(int i = 0; i < m; i++) {
        int S = max<int>(0, ints[i] - 2 * t);
        if(S == 1 || S == 2) {
            t++;
            ans += ints[i] - 1;
        } else if(S > 2) {
            t += 2;
            ans += ints[i] - (S - 1);
        } else {
            ans += ints[i];
        }
    }
    cout << ans << "\n";
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}