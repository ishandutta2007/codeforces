#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define int long long

typedef long long ll;

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    const int MOD = 1e9 + 7;
    string s;
    cin >> s;
    vector <int> a;
    a.pb(0);
    bool f = 0;
    forn(i, 0, s.size()) {
        if (s[i] == 'a') {
            f = 1;
            a.back()++;
        }
        if (s[i] == 'b' && f) {
            a.pb(0);
            f = 0;
        }
    }
    int ans = 1;
    forn (i, 0, a.size())
        ans = (ans * (a[i] + 1)) % MOD;
    cout << ans - 1;
    return 0;
}