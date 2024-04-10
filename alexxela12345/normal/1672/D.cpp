#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    {
        auto aa = a;
        sort(aa.begin(), aa.end());
        auto bb = b;
        sort(bb.begin(), bb.end());
        if (aa != bb) {
            cout << "NO" << endl;
            return;
        }
    }
    map<int, int> cnt;
    int r = n - 1;
    vector<int> cnta(n), cntb(n);
    cnta[0] = cntb[0] = 1;
    for (int i = 1; i < n; i++) {
        cnta[i] = 1;
        cntb[i] = 1;
        if (a[i] == a[i - 1]) {
            cnta[i] = cnta[i - 1] + 1;
        } 
        if (b[i] == b[i - 1]) {
            cntb[i] = cntb[i - 1] + 1;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (r < 0 || a[i] != b[r]) {
            if (cnt[a[i]]) {
                cnt[a[i]] -= 1;
                continue;
            } else {
                cout << "NO" << endl;
                return;
            }
        } else {
            int ca = cnta[i];
            int cb = cntb[r];
            cnt[a[i]] += max(0, cb - ca);
            if (ca > cb) {
                i -= cb - 1;
                r -= cb;
                continue;
            }
            i -= ca - 1;
            r -= cb;
        }
    }
    cout << "YES" << endl;
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