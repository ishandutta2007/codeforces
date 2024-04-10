#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;

int ask(vector<int> a, vector<int> b) {
    cout << "? " << a.size() << " " << b.size() << endl;
    for (int el : a) {
        cout << el << " ";
    }
    cout << endl;
    for (int el : b) {
        cout << el << " ";
    }
    cout << endl;
    int x;
    cin >> x;
    return x;
}

void solve() {
    int n;
    cin >> n;
    vector<int> ans(n + 1, 1);
    ans[0] = 0;
    for (int i = 2; i <= n; i++) {
        vector<int> a1, a2;
        for (int j = 1; j < i; j++) {
            a1.push_back(j);
        }
        a2.push_back(i);
        if (ask(a1, a2)) {
            int l = 0;
            int r = i - 1;
            while (r - l > 1) {
                int m = (l + r) / 2;
                a1.clear();
                for (int j = 1; j <= m; j++) {
                    a1.push_back(j);
                }
                if (ask(a1, a2)) {
                    r = m;
                } else {
                    l = m;
                }
            }
            ans[r] = 0;
            ans[i] = 0;
            for (int j = i + 1; j <= n; j++) {
                if (ask({i}, {j})) {
                    ans[j] = 0;
                }
            }
            int sum = 0;
            for (int el : ans) {
                sum += el;
            }
            cout << "! " << sum << " ";
            for (int i = 0; i <= n; i++) {
                if (ans[i]) {
                    cout << i << " ";
                }
            }
            cout << endl;
            return;
        }
    }
    assert(false);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}