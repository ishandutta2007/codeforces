#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 10;
ll a[MAXN];

void solve() {
    int n, k, b;
    ll s;
    cin >> n >> k >> b >> s;
    if (s < 1LL * k * b or s - 1LL * k * b > 1LL * n * (k - 1)) {
        cout << -1 << '\n';
        return;
    }
    a[1] = 1LL * k * b;
    s -= a[1];
    for (int i = 1; i <= n and s > 0; i++) {
        int t = min(1LL * k - 1, s);
        a[i] += t;
        s -= t;
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " \n"[i == n];
        a[i] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
}