#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 2);
    for (int i = 1; i <= n; i++) cin >> a[i];
    int mn = 1e9;
    for (int i = 1; i <= n; i++) mn = min(mn, a[i]);
    bool ok = 1;
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] % mn) {
            if (a[i] < mx) {
                ok = 0;
                break;
            }
            mx = max(a[i], mn);
        }
    }
    vector<int> pref(n + 2, 0);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1];
        if (a[i] % mn == 0) pref[i]++;
    }
    map<int, int> mp;
    vector<int> b(n + 2);
    for (int i = 0; i < b.size(); i++) b[i] = a[i];
    sort(a.begin() + 1, a.begin() + n + 1);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] % mn == 0) cnt++;
        mp[a[i]] = cnt;
    }

    for (int i = 1; i <= n; i++) {
        if (b[i] % mn) if (pref[i] != mp[b[i]]) ok = 0;
    }

    cout << (ok ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}