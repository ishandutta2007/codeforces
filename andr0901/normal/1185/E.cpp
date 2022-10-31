#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define x first
#define y second

void solve() {
    int n, m;
    cin >> n >> m;
    vector <vector <char>> a(n, vector <char> (m));
    vector <vector <pii>> b(26);
    char mx = 'a' - 1;
    forn (i, 0, n) {
        forn (j, 0, m) {
            cin >> a[i][j];
            if (a[i][j] != '.')
                mx = max(mx, a[i][j]), b[a[i][j] - 'a'].eb(i, j);
        }
    }
    vector <pair <pii, pii>> ans;
    for (char c = mx; c >= 'a'; c--) {  
        //cout << c << ":\n";
        if (sz(b[c - 'a']) == 0) {
            ans.pb(ans.back());
            continue;
        }
        int OK = 2;
        {
            bool ok = 1;
            forn (i, 0, sz(b[c - 'a'])) {
                if (b[c - 'a'][i].fs != b[c - 'a'][0].fs) {
                    ok = 0;
                    break;
                }
            }
            if (ok) {
                int l = 1e9, r = -1e9;
                for (auto i : b[c - 'a']) {
                    if (i.y < l)
                        l = i.y;
                    if (i.y > r)
                        r = i.y;
                }
                int i = b[c - 'a'][0].x;
                forn (j, l, r + 1) {
                    if (a[i][j] == '.' || a[i][j] < c) {
                        cout << "NO\n";
                        return;
                    }
                    a[i][j] = 'z' + 1;
                }
                //cout << i << " " << l << "  " << i << " " << r << "\n";
                ans.pb({{i, l}, {i, r}});
                continue;
            } else {
                OK--;
            }
        } 
        {
            bool ok = 1;
            forn (i, 0, sz(b[c - 'a'])) {
                if (b[c - 'a'][i].sc != b[c - 'a'][0].sc) {
                    ok = 0;
                    break;
                }
            }
            if (ok) {
                int l = 1e9, r = -1e9;
                for (auto i : b[c - 'a']) {
                    if (i.x < l)
                        l = i.x;
                    if (i.x > r)
                        r = i.x;
                }
                int j = b[c - 'a'][0].y;
                forn (i, l, r + 1) {
                    if (a[i][j] == '.' || a[i][j] < c) {
                        cout << "NO\n";
                        return;
                    }
                    a[i][j] = 'z' + 1;
                }
                //cout << l << " " << j << "  " << r << " " << j << "\n";
                ans.pb({{l, j}, {r, j}});
                continue;
            } else {
                OK--;
            }
        } 
        if (!OK) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n" << sz(ans) << "\n";
    reverse(all(ans));
    forn (i, 0, sz(ans))
        cout << ans[i].fs.x + 1 << " " << ans[i].fs.y + 1 << " " << ans[i].sc.x + 1 << " " << ans[i].sc.y + 1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}