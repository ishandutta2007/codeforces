#include <bits/stdc++.h>

using namespace std;

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x;
    cin >> n;
    vector < int > a;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    vector < int > ans;
    ans.push_back(a.back());
    if (a[n - 2] + a[n - 3] <= a[n - 1]) {
        cout << "NO" << '\n';
        return 0;
    }
    for (int i = n - 2; i >= 0; i -= 2) ans.push_back(a[i]);
    for (int i = (n - 3) % 2; i <= n - 3; i += 2) ans.push_back(a[i]);
    cout << "YES" << '\n';
    for (auto key : ans) cout << key << " ";
    return 0;
}