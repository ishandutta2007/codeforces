#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

using namespace std;
#define int long long

inline int solve(int n, vector <int> a, vector <bool> ch, int k) {
    vector <int> ca = a;
    vector <int> v(n);
    int ans = 1;
    for (int i = 0; i < n - 1; ++i) {
        a = ca;
        int cur1 = 0, cur2 = i + 1;
        while (true) {
            if (cur1 > i) break;
            if (cur2 == n) break;
            if (!ch[cur1] || a[cur1] == k) {
                ++cur1;
                continue;
            }
            if (!ch[cur2] || a[cur2] == -k) {
                ++cur2;
                continue;
            }
            int cnt1 = k - a[cur1];
            int cnt2 = a[cur2] + k;
            int val = min(cnt1, cnt2);
            a[cur1] += val;
            a[cur2] -= val;
        }
        cur1 = n - 1;
        while (cur2 < cur1) {
            if (!ch[cur2] || a[cur2] == -k) {
                ++cur2;
                continue;
            }
            if (!ch[cur1] || a[cur1] == k) {
                --cur1;
                continue;
            }
            int cnt1 = k - a[cur1];
            int cnt2 = a[cur2] + k;
            int val = min(cnt1, cnt2);
            a[cur1] += val;
            a[cur2] -= val;
        }
        v[0] = a[0];
        for (int j = 1; j < n; ++j) v[j] = v[j - 1] + a[j];
        ans = max(ans, *max_element(v.begin(), v.end()) - *min_element(v.begin(), v.end()) + 1);
    }
    return ans;
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int n, k;
    cin >> n >> k;
    vector <int> a(n);
    vector <bool> ch(n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 0) ch[i] = true;
        sum += a[i];
    }
    for (int i = 0; i < n && sum != 0; ++i) {
        if (!ch[i]) continue;
        if (sum > 0) {
            a[i] = max(-k, -sum);
        } else {
            a[i] = min(k, -sum);
        }
        sum += a[i];
    }
    if (sum != 0) {
        cout << -1;
        return 0;
    }
    vector <int> ca = a;
    for (int i = 0; i < n; ++i) ca[i] *= -1;
    cout << max(solve(n, a, ch, k), solve(n, ca, ch, k));
}