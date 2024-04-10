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
    int n;
    cin >> n;
    vector <pii> a(n);
    forn (i, 0, n)
        cin >> a[i].fs >> a[i].sc;
    sort(all(a));
    pii cur = {0, 0};
    string ans = "YES\n";
    forn (i, 0, n) {
        if (cur.fs > a[i].fs) {
            ans = "NO";
            break;
        }
        while (cur.fs < a[i].fs) {
            ans += 'R';
            cur.fs++;
        }
        if (cur.sc > a[i].sc) {
            ans = "NO";
            break;
        }
        while (cur.sc < a[i].sc) {
            ans += 'U';
            cur.sc++;
        }
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