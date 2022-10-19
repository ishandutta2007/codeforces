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
    int n, k;
    cin >> n >> k;
    vector<int> a1(n), a2(n);
    for (int i = 1; i < n; ++i) {
        cout << "and" << ' ' << 1 << ' ' << i + 1 << endl;
        cin >> a1[i];
        cout << "or" << ' ' << 1 << ' ' << i + 1 << endl;
        cin >> a2[i];
    }
    cout << "and" << ' ' << 2 << ' ' << 3 << endl;
    cin >> a1[0];
    cout << "or" << ' ' << 2 << ' ' << 3 << endl;
    cin >> a2[0];
    vector<int> a(n);
    for (int i = 0; i < 30; ++i) {
        bool ch = 1;
        for (int j = 1; j < n; ++j) {
            if (a1[j] & (1 << i)) {
                a[0] |= (1 << i);
                break;
            }
            if (!(a2[j] & (1 << i))) {
                ch = 0;
                break;
            }
        }
        if (ch && !(a[0] & (1 << i))) {
            if (!(a1[0] & (1 << i))) {
                a[0] |= (1 << i);
            }
        }
    }
    vector<int> b = {a[0]};
    for (int i = 1; i < n; ++i) {
        int val = a[0] ^ (a1[i] ^ a2[i]);
        b.push_back(val);
    }
    sort(all(b));
    cout << "finish" << ' ' << b[k - 1] << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}