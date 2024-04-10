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
    vector <pii> ans;
    forn (i, 0, n - 1) {
        //cout << i << " ";
        if (s[i] != t[i]) {
            bool found = false;
            forn (j, i + 1, n) {
                if (t[j] == t[i]) {
                    found = true;
                    ans.eb(i, j);
                    swap(s[i], t[j]);
                    break;
                }
            }
            if (found)
                continue;
            forn (j, i + 1, n) {
                if (s[j] == s[i]) {
                    found = true;
                    ans.eb(j, i);
                    swap(s[j], t[i]);
                    break;
                }
            }
            if (found)
                continue;
            forn (j, i + 1, n) {
                if (t[j] == s[i]) {
                    found = true;
                    ans.eb(n - 1, j);
                    swap(s[n - 1], t[j]);
                    ans.eb(n - 1, i);
                    swap(s[n - 1], t[i]);
                    break;
                }
            }
            if (found)
                continue;
            forn (j, i + 1, n) {
                if (s[i] == t[j]) {
                    found = true;
                    ans.eb(j, n - 1);
                    swap(s[j], t[n - 1]);
                    ans.eb(i, n - 1);
                    swap(s[i], t[n - 1]);
                    break;
                }
            }
            if (found)
                continue;
            cout << "No\n";
            return;
        }
    }
    if (s != t) {
        cout << "No\n";
        return;
    }
    cout << "Yes\n" << ans.size() << "\n";;
    for (auto i : ans)
        cout << i.fs + 1 << " " << i.sc + 1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int k;
    cin >> k;
    while (k --> 0)
        solve();
    return 0;
}