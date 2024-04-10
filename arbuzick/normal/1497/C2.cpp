#include <bits/stdc++.h>

using namespace std;

#define int long long
//#define double long double
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define eb emplace_back
#define pii pair<int, int>

void solve() {
    int n, k;
    cin >> n >> k;
    while (k > 3) {
        k--;
        n--;
        cout << 1 << ' ';
    }
    if (n % 2 == 1) {
        cout << n / 2 << ' ' << n / 2 << ' ' << 1 << '\n';
    } else if (n % 4 == 0) {
        cout << n / 2 << ' ' << n /4 << ' ' << n / 4 << '\n';
    } else {
        cout << n / 2 - 1 << ' ' << n / 2 - 1 << ' ' << 2 << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}