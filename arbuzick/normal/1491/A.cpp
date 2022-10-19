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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0) {
            cnt0++;
        } else {
            cnt1++;
        }
    }
    while (q--) {
        int t, x;
        cin >> t >> x;
        x--;
        if (t == 1) {
            if (a[x] == 0) {
                a[x] = 1;
                cnt0--;
                cnt1++;
            } else {
                a[x] = 0;
                cnt1--;
                cnt0++;
            }
        } else {
            x++;
            if (cnt1 >= x) {
                cout << 1 << '\n';
            } else {
                cout << 0 << '\n';
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}