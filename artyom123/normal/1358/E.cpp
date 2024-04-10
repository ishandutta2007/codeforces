#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a((n + 1) / 2);
    for (auto &c : a) cin >> c;
    int x; cin >> x;
    for (int i = 0; i < n / 2; i++) a.pb(x);
    vector<long long> pr_sum(n + 1);
    for (int i = 0; i < n; i++) pr_sum[i + 1] = pr_sum[i] + a[i];
    if (x >= 0) {
        cout << (pr_sum[n] > 0 ? n : -1);
        return 0;
    }
    int k = n / 2 + 1;
    vector<int> len((n + 1) / 2);
    for (int i = 0; i < (n + 1) / 2; i++) {
        if (pr_sum[i + k] - pr_sum[i] <= 0) {
            len[i] = 0; continue;
        }
        int left = k, right = n - i + 1;
        while (right - left > 1) {
            int mid = (left + right) / 2;
            if (pr_sum[i + mid] - pr_sum[i] > 0) left = mid;
            else right = mid;
        }
        len[i] = left;
    }
    vector<int> mn((n + 1) / 2);
    mn[0] = len[0];
    for (int i = 1; i < (n + 1) / 2; i++) mn[i] = min(mn[i - 1], len[i]);
    for (int k = n; k >= n / 2 + 1; k--) {
        if (mn[n - k] >= k) {
            cout << k;
            return 0;
        }
    }
    cout << -1;
    return 0;
}