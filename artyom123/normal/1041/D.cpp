#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, h;
    cin >> n >> h;
    vector <pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end());
    vector <int> b(n);
    int sum = 0;
    for (int i = 1; i < n; i++) {
        b[i] = sum + a[i].first - a[i - 1].second;
        sum += a[i].first - a[i - 1].second;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int it = (int)(lower_bound(b.begin(), b.end(), h + b[i]) - b.begin());
        it--;
        ans = max(ans, a[it].second + h - (b[it] - b[i]) - a[i].first);
    }
    cout << ans;
    return 0;
}