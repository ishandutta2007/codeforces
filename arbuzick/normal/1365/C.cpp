#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n), a1(n+1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a1[a[i]] = i;
    }
    vector<int> b(n), b1(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        b1[b[i]] = i;
    }
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) 
        ans[(i - b1[a[i]] + n) % n]++;
    int ans1 = 0;
    for (int i = 0; i < n; ++i)
        ans1 = max(ans1, ans[i]);
    cout << ans1;
    return 0;
}