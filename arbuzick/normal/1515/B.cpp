#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pii pair<int, int>

void solve() {
    int n;
    cin >> n;
    if (n % 4 == 0) {
        int c = sqrt(n / 4);
        if (c * c == n / 4 || (c - 1) * (c - 1) == n / 4 || (c + 1) * (c + 1) == n / 4) {
            cout << "YES\n";
            return;
        }
    }
    if (n % 2 == 0) {
        int c = sqrt(n / 2);
        if (c * c == n / 2 || (c - 1) * (c - 1) == n / 2 || (c + 1) * (c + 1) == n / 2) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}