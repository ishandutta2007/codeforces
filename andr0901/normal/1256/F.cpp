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

ll inv(const string& s) {
    ll ans = 0;
    vector <int> a(26);
    forn (i, 0, s.size()) {
        forn (j, s[i] - 'a' + 1, 26)
            ans += a[j];
        a[s[i] - 'a']++;
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    string _s = s, _t = t;
    sort(all(_s)), sort(all(_t));
    if (_s != _t) {
        cout << "NO\n";
        return;
    }
    forn (i, 0, sz(_s) - 1) {
        if (_s[i] == _s[i + 1]) {
            cout << "YES\n";
            return;
        }
    }
    //cout << inv(s) << " " << inv(t) << "\n";
    if (inv(s) % 2 == inv(t) % 2)
        cout << "YES";
    else
        cout << "NO";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}