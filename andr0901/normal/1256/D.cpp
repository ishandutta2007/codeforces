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
#define int long long

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int pref = 0;
    int cnt = 0;
    forn (i, 0, n) {
        if (s[i] == '1')
            cnt++;
        else {
            if (k < cnt) {
                forn (j, 0, pref)
                    cout << '0';
                forn (j, 0, cnt - k)
                    cout << '1';
                cout << '0';
                forn (j, cnt - k, cnt)
                    cout << '1';
                forn (j, i + 1, n)
                    cout << s[j];
                cout << "\n";
                return;
            } else {
                k -= cnt;
                ++pref;
            }
        }
    }
    forn (i, 0, pref)
        cout << '0';
    forn (i, pref, n)
        cout << '1';
    cout << "\n";
}

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}