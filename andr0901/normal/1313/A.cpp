#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

//vector string deque break continue
#define forn(i, s, f) for (int i = (int)s; i < (int)f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pf push_front
#define pb push_back
#define pop_f pop_front
#define pop_b pop_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

void solve() {
    vector <int> a(3);
    forn (i, 0, 3)
        cin >> a[i];
    vector <vector <int>> types = {{0}, {1}, {2}, {0, 1}, {0, 2}, {1, 2}, {0, 1, 2}};
    int ans = 0;
    forn (mask, 0, 1 << 7) {
        vector <int> needed(3);
        int cnt = 0;
        forn (i, 0, 7)
            if ((mask >> i) & 1) {
                for (int j : types[i])
                    needed[j]++;
                cnt++;
            }
        bool ok = true;
        forn (i, 0, 3)
            if (needed[i] > a[i])
                ok = false;
        if (ok)
            ans = max(ans, cnt);
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}