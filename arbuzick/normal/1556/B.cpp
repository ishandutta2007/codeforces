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
    int n;
    cin >> n;
    vector<int> a(n);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] = a[i] % 2;
        if (a[i]) {
            cnt++;
        } else {
            cnt--;
        }
    }
    if (cnt < -1 || cnt > 1) {
        cout << -1 << '\n';
        return;
    }
    if (cnt != 0) {
        int pos = 0;
        if (cnt < 0) {
            pos = 1;
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i]) {
                ans += abs(pos - i);
                pos += 2;
            }
        }
        cout << ans << '\n';
    } else {
        int ans1 = 0, ans2 = 0;
        int pos1 = 0, pos2 = 1;
        for (int i = 0; i < n; ++i) {
            if (a[i]) {
                ans1 += abs(pos1 - i);
                ans2 += abs(pos2 - i);
                pos1 += 2;
                pos2 += 2;
            }
        }
        cout << min(ans1, ans2) << '\n';
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