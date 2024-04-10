#include <bits/stdc++.h>

using namespace std;

//#define int long long
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
    vector<int> ans;
    for (int i = 1; i < n; ++i) {
        cout << '?' << ' ' << i << ' ' << 1 << endl;
        for (int j = 0; j < i; ++j) {
            cout << j + 1 << ' ';
        }
        cout << endl;
        cout << i + 1 << endl;
        int a;
        cin >> a;
        if (a) {
            ans.pb(i + 1);
            int l = 0, r = i;
            while (l < r - 1) {
                int m = (l + r) / 2;
                cout << '?' << ' ' << m << ' ' << 1 << endl;
                for (int i = 0; i < m; ++i) {
                    cout << i + 1 << ' ';
                }
                cout << endl;
                cout << i + 1 << endl;
                int a;
                cin >> a;
                if (a) {
                    r = m;
                } else {
                    l = m;
                }
            }
            ans.pb(r);
            for (int j = i + 1; j < n; ++j) {
                cout << '?' << ' ' <<  1 << ' ' << 1 << endl;
                cout << i + 1 << ' ' << j + 1 << endl;
                int a;
                cin >> a;
                if (a) {
                    ans.pb(j + 1);
                }
            }
            int p = 0;
            cout << '!' << ' ' << n - ans.size() << ' ';
            vector<int> used(n + 1);
            for (auto j: ans) {
                used[j] = 1;
            }
            for (int j = 1; j <= n; ++j) {
                if (!used[j]) {
                    cout << j << ' ';
                }
            }
            cout << endl;
            return;
        }
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