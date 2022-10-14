#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector <pair<int, int>> a(n);
    vector <int> b(n);
    long long now = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        b[i] = a[i].first - a[i].second;
        now += a[i].first;
    }
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());
    int ans = 0;
    for (int i = 0; i < n && now > m; i++) {
        now -= b[i];
        ans++;
    }
    if (now > m) {
        cout << -1;
        return 0;
    }
    cout << ans;
    return 0;
}