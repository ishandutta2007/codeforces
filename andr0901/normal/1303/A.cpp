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
    string s;
    cin >> s;
    int l = sz(s), r = 0;
    forn (i, 0, sz(s)) {
        if (s[i] == '1') {
            l = i;
            break;
        }
    }
    if (l == sz(s)) {
        cout << "0\n";
        return;
    }
    for (int i = sz(s) - 1; i >= 0; --i) {
        if (s[i] == '1') {
            r = i;
            break;
        }
    }
    int cnt = 0;
    forn (i, l, r + 1)
        if (s[i] == '0')
            cnt++;
    cout << cnt << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}