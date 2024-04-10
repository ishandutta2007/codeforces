#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (c * b - a < 0) {
        cout << "-1\n";
        return;
    }
    if (d >= c + 1) {
        cout << a << "\n";
        return;
    }
    int k = (a - 1) / (d * b);
    cout << (k + 1) * a - (((k + 1) * k) / 2) * d * b << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}