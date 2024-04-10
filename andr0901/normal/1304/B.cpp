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

bool is_palindrome(const string& s) {
    forn (i, 0, sz(s) / 2)
        if (s[i] != s[sz(s) - 1 - i])
            return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    map <string, bool> a;
    forn (i, 0, n) {
        string t;
        cin >> t;
        a[t] = false;
    }
    string ans = "";
    for (auto& [s, used] : a) {
        if (used)
            continue;
        string t = s;
        reverse(all(t));
        if (s == t)
            continue;
        if (a.find(t) != a.end() && !a[t]) {
            a[t] = a[s] = true;
            ans += s;
        }
        //cout << ans << "\n";
    }
    for (auto& [s, used] : a) {
        if (is_palindrome(s) && !used) {
            cout << 2 * sz(ans) + sz(s) << "\n";
            cout << ans << s;
            reverse(all(ans));
            cout << ans;
            return 0;
        }
    }
    cout << 2 * sz(ans) << "\n";
    cout << ans;
    reverse(all(ans));
    cout << ans;
    return 0;
}