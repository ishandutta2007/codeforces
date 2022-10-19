#include <bits/stdc++.h>

#define int long long
#define double long double
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define eb emplace_back
#define pii pair<int, int>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    if (n % 2 == 0) {
        int ans = (k - 1) % n + 1;
        cout << ans << '\n';
        return;
    }
    int kek = (k - 1) / (n / 2);
    int pos = k % n;
    pos += kek;
    pos %= n;
    if (pos == 0) {
        pos = n;
    }
    cout << pos << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int q = 1;
    cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}