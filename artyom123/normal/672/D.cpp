#include<bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    ll sum = 0;
    for (auto &c : a) {
        cin >> c;
        sum += c;
    }
    int L = 1, R = 1e9 + 1;
    while (R - L > 1) {
        int M = (L + R) / 2;
        ll res = 0;
        for (auto &c : a) {
            res += max(0, M - c);
        }
        if (res <= k) L = M;
        else R = M;
    }
    int mn = L;
    L = 0, R = 1e9;
    while (R - L > 1) {
        int M = (L + R) / 2;
        ll res = 0;
        for (auto &c : a) {
            res += max(0, c - M);
        }
        if (res <= k) R = M;
        else L = M;
    }
    int mx = R;
    int ans = max(0, mx - mn);
    if (sum % n != 0) ans = max(ans, 1);
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--) solve();
    return 0;
}