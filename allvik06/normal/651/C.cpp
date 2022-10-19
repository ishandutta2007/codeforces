#include <bits/stdc++.h>

using namespace std;
#define int long long
const int INF = 1e9 + 7;


signed main() {
    int n;
    cin >> n;
    vector <pair <int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end());
    int tmp = 1, ans = 0;
    for (int i = n - 2; i >= 0; --i) {
        if (a[i].first == a[i + 1].first) {
            ++tmp;
        }
        else {
            ans += (tmp - 1) * tmp / 2;
            tmp = 1;
        }
    }
    ans += (tmp - 1) * tmp / 2;
    tmp = 1;
    for (int i = 0; i < n; ++i) {
        swap(a[i].first, a[i].second);
    }
    sort(a.begin(), a.end());
    for (int i = n - 2; i >= 0; --i) {
        if (a[i].first == a[i + 1].first) {
            ++tmp;
        }
        else {
            ans += (tmp - 1) * tmp / 2;
            tmp = 1;
        }
    }
    ans += tmp * (tmp - 1) / 2;
    tmp = 1;
    for (int i = n - 2; i >= 0; --i) {
        if (a[i].first == a[i + 1].first && a[i].second == a[i + 1].second) {
            ++tmp;
        }
        else {
            ans -= (tmp - 1) * tmp / 2;
            tmp = 1;
        }
    }
    ans -= tmp * (tmp - 1) / 2;
    cout << ans;
    return 0;
}