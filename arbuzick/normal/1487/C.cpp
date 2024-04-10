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
    int n;
    cin >> n;
    if (n % 2 == 1) {
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (i % 2 == j % 2) {
                    cout << 1 << ' ';
                } else {
                    cout << -1 << ' ';
                }
            }
        }
        cout << '\n';
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            cout << 0 << ' ';
        }
        for (int j = i + 2 - i % 2; j < n; ++j) {
            if (i % 2 == j % 2) {
                cout << 1 << ' ';
            } else {
                cout << -1 << ' ';
            }
        }
    }
    cout << '\n';
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