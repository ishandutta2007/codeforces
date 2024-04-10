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
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    int s = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        s += a[i];
    }
    sort(rall(a));
    if (s == x) {
        cout << "NO\n";
        return;
    }
    s = 0;
    for (int i = 0; i < n; ++i) {
        s += a[i];
        if (s == x) {
            if (a[i + 1] == a[0]) {
                cout << "NO\n";
                return;
            }
            cout << "YES\n";
            swap(a[0], a[i + 1]);
            for (int j = 0; j < n; ++j) {
                cout << a[j] << ' ';
            }
            cout << '\n';
            return;
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        cout << a[i] << ' ';
    }
    cout << '\n';
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