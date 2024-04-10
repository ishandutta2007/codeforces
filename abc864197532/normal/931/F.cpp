#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, l, r;
    cin >> n >> m;
    vector <int> pre(m + 1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> l >> r;
        pre[l - 1]++;
        pre[r]--;
    }
    for (int i = 1; i <= m; ++i) pre[i] += pre[i - 1];
    pre.pop_back();
    vector <int> lis;
    vector <int> lf(m, 0), rf(m, 0);
    for (int i = 0; i < m; ++i) {
        if (lis.empty() || lis.back() <= pre[i]) {
            lis.push_back(pre[i]);
            lf[i] = lis.size();
        } else {
            auto it = upper_bound(lis.begin(), lis.end(), pre[i]);
            *it = pre[i];
            lf[i] = it - lis.begin() + 1;
        }
    }
    lis.clear();
    for (int i = m - 1; i >= 0; --i) {
        if (lis.empty() || lis.back() <= pre[i]) {
            lis.push_back(pre[i]);
            rf[i] = lis.size();
        } else {
            auto it = upper_bound(lis.begin(), lis.end(), pre[i]);
            *it = pre[i];
            rf[i] = it - lis.begin() + 1;
        }
    }
    int ans = 0;
    for (int i = 0; i < m; ++i) ans = max(ans, lf[i] + rf[i] - 1);
    cout << ans;
}