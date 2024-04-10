#include <bits/stdc++.h>

using namespace std;
#define int long long
const int INF = 1e11;
signed main() {
    int n, a, b, k;
    cin >> n >> a >> b >> k;
    vector <int> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    vector <int> ans(n, INF);
    for (int i = 0; i < n; ++i) {
        int tmp = h[i] / (a + b);
        int tmp1 = (a + b) * tmp;
        if (tmp1 == h[i]) {
            ans[i] = (b + a - 1) / a;
            continue;
        }
        ans[i] = (h[i] - tmp1 + a - 1) / a - 1;
    }
    sort(ans.begin(), ans.end());
    int now = 0, i = 0;
    while (i < n) {
        if (ans[i] <= k) {
            ++now;
            k -= ans[i];
            ++i;
        }
        else {
            break;
        }
    }
    cout << now;
    return 0;
}