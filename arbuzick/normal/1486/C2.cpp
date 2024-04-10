#include <bits/stdc++.h>

#define int long long
#define double long double
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define eb emplace_back
#define pii pair<int, int>
using namespace std;
int ask(int l, int r) {
    l++;
    cout << "? " << l << ' ' << r << endl;
    int p;
    cin >> p;
    return p - 1;
}
void solve() {
    int n;
    cin >> n;
    int pos = ask(0, n);
    if (n == 2) {
        if (pos == 0) {
            cout << "! " << 2 << endl;
        } else {
            cout << "! " << 1 << endl;
        }
    }
    if (pos < n - 1 && ask(pos, n) == pos) {
        int l = pos, r = n - 1;
        while (l < r - 1) {
            int m = (l + r) / 2;
            if (ask(pos, m + 1) == pos) {
                r = m;
            } else {
                l = m;
            }
        }
        cout << "! " << r + 1 << endl;
    } else {
        int l = 0, r = pos;
        while (l < r - 1) {
            int m = (l + r) / 2;
            if (ask(m, pos + 1) == pos) {
                l = m;
            } else {
                r = m;
            }
        }
        cout << "! " << l + 1 << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int q = 1;
    //cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}