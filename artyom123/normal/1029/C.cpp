#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main() {
    int n;
    cin >> n;
    vector <pair<int, int>> a(n);
    int left = -INF, right = INF;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        left = max(left, a[i].first);
        right = min(right, a[i].second);
    }
    int max_l = -INF, min_r = INF;
    for (int i = 0; i < n; i++) {
        if (a[i].first == left) {
            max_l = i;
        }
        if (a[i].second == right) {
            min_r = i;
        }
        if (a[i].first == left && a[i].second == right) {
            break;
        }
    }
    left = -INF, right = INF;
    for (int i = 0; i < n; i++) {
        if (i == max_l) {
            continue;
        }
        left = max(left, a[i].first);
        right = min(right, a[i].second);
    }
    int ans1 = max(0, right - left);
    left = -INF, right = INF;
    for (int i = 0; i < n; i++) {
        if (i == min_r) {
            continue;
        }
        left = max(left, a[i].first);
        right = min(right, a[i].second);
    }
    int ans2 = max(0, right - left);
    cout << max(ans1, ans2);
    return 0;
}