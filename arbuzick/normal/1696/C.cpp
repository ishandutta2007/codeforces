#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    long long sum_a = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum_a += a[i];
    }
    int k;
    cin >> k;
    vector<int> b(k);
    long long sum_b = 0;
    for (int i = 0; i < k; ++i) {
        cin >> b[i];
        sum_b += b[i];
    }
    if (sum_a != sum_b) {
        cout << "No\n";
        return;
    }
    deque<pair<int, int>> q;
    for (int i = 0; i < k; ++i) {
        int val = b[i], cnt = 1;
        while (val % m == 0) {
            val /= m;
            cnt *= m;
        }
        if (i > 0 && val == q.back().first) {
            q.back().second += cnt;
        } else {
            q.push_back({val, cnt});
        }
    }
    auto check = [&](int a) {
        while (a % m == 0) {
            a /= m;
        }
        return a == 1;
    };
    for (int i = 0; i < n; ++i) {
        if (a[i] % q.front().first != 0 || a[i] > q.front().first * q.front().second || !check(a[i] / q.front().first)) {
            cout << "No\n";
            return;
        }
        q.front().second -= a[i] / q.front().first;
        if (q.front().second == 0) {
            q.pop_front();
        }
    }
    cout << "Yes\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}