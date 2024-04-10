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
    int n;
    cin >> n;
    vector<int> a;
    set<int> used;
    vector<int> b;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (used.count(x)) {
            b.pb(x);
        } else {
            a.pb(x);
            used.insert(x);
        }
    }
    sort(all(a));
    for (auto i: a) {
        cout << i << ' ';
    }
    for (auto i: b) {
        cout << i << ' ';
    }
    cout << '\n';
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