#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(all(a));
    vector<int> ans(n);
    int j = 0;
    for (int i = 1; i < n; i += 2)
        ans[i] = a[j], j++;
    for (int i = 0; i < n; i += 2)
        ans[i] = a[j], j++;
    int ans2 = 0;
    for (int i = 1; i+1 < n; i += 2)
        if (ans[i] < ans[i-1] && ans[i] < ans[i+1])
            ans2++;
    cout << ans2 << '\n';
    for (int i = 0; i < n; ++i)
        cout << ans[i] << ' ';
    return 0;
}