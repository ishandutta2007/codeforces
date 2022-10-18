#include <bits/stdc++.h>

using namespace std;

#define int int64_t

int get(int *a, int n, int k) {
    if(k >= n) {
        int ans = accumulate(a, a + n, (int)0);
        ans += n * (k - n) + n * (n - 1) / 2;
        return ans;
    } else {
        int ans = k * (k - 1) / 2;
        int cur = accumulate(a, a + k, (int)0);
        int best = cur;
        for(int i = k; i < n; i++) {
            cur += a[i] - a[i - k];
            best = max(best, cur);
        }
        return ans + best;
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << get(a, n, k) << "\n";
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}