#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

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
    string s, t;
    cin >> s >> t;
    vector <int> different;
    forn (i, 0, n)
        if (s[i] != t[i])
            different.pb(i);
    if (different.size() > 2 || different.size() == 1) {
        cout << "No";
    } else if (different.size() == 0) {
        cout << "Yes";
    } else {
        int i = different[0], j = different[1];
        if (s[i] == s[j] && t[i] == t[j])
            cout << "Yes";
        else
            cout << "No";
    }
    cout << "\n";

}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int k;
    cin >> k;
    while (k --> 0)
        solve();
    return 0;
}