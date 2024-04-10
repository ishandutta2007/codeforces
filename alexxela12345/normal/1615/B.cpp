#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;

#define all(v) (v).begin(),(v).end()

int count(int n, int i) {
    // n not inclusive
    int k = 1 << (i + 1);
    int cnt1 = n / k * (k / 2);
    n %= k;
    cnt1 += max(0, n - k / 2);
    return cnt1;
}

void solve() {
    int l, r;
    cin >> l >> r;
    int n = r - l + 1;
    int min_ans = INT_MAX;
    for (int i = 0; i < 20; i++) {
        int cnt = count(r + 1, i) - count(l, i);
        min_ans = min(min_ans, n - cnt);
    }
    cout << min_ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}