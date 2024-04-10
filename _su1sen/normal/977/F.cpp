#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    map<int, int> last;
    vector<int> prv(n);
    vector<int> dp(n);
    for (int i = n - 1; i >= 0; --i) {
        int v = a[i] + 1;
        if (last.count(v) == 0) {
            dp[i] = 1;
            prv[i] = n;
        } else {
            dp[i] = dp[last[v]] + 1;
            prv[i] = last[v];
        }
        last[v - 1] = i;
    }
    int mx = 0;
    int argmax = 0;
    for (int i = 0; i < n; ++i) {
        if (dp[i] > mx) {
            mx = dp[i];
            argmax = i;
        }
    }
    cout << mx << '\n';
    cout << argmax + 1;
    int cur = prv[argmax];
    while (cur != n) {
        cout << ' ' << cur + 1;
        cur = prv[cur];
    }
    cout << '\n';
    return 0;
}