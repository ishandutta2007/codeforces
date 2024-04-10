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
    int u, v;
    cin >> u >> v;
    if (u > v) {
        cout << "NO\n";
        return;
    }
    if (u == v) {
        cout << "YES\n";
        return;
    }
    vector<int> b;
    for (int i = 0; i < 30; ++i) {
        if (u & (1 << i)) {
            b.pb(i);
        }
    }
    vector<int> c;
    for (int i = 0; i < 30; ++i) {
        if (v & (1 << i)) {
            c.pb(i);
        }
    }
    if (c.size() > b.size()) {
        cout << "NO\n";
        return;
    }
    reverse(all(b));
    reverse(all(c));
    int p = 0;
    for (int i = 0; i < c.size(); ++i) {
        while (p < b.size() && b[p] > c[i]) {
            p++;
        }
        if (p == b.size()) {
            cout << "NO\n";
            return;
        }
        p++;
    }
    cout << "YES\n";
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