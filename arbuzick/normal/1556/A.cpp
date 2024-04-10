#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <map>

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
//#define _USE_MATH_DEFINE
using namespace std;

void solve() {
    int c, d;
    cin >> c >> d;
    if (c % 2 != d % 2) {
        cout << -1 << '\n';
    } else if (c == 0 && d == 0) {
        cout << 0 << '\n';
    } else if (c == d) {
        cout << 1 << '\n';
    } else {
        cout << 2 << '\n';
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