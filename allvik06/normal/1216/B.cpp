#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double

signed main() {
    int n, x = 0, ans = 0;
    cin >> n;
    vector <pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a.rbegin(), a.rend());
    for (int i = 0; i < n; i++) {
        ans += x * a[i].first + 1;
        x++;
    }
    cout << ans << "\n";
    for (int i = 0; i < n; i++) {
        cout << a[i].second << " ";
    }
}