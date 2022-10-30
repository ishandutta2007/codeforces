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

void reverse(int l, int r, string& s, vector <pii>& ans) {
    for (int i = l, j = r; i < j; ++i, --j)
        swap(s[i], s[j]);
    ans.eb(l, r);
}

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector <pii> ans;
    int cur = 0;
    forn (i, 0, k - 1) {
        forn (j, 2 * i, n) {
            if (s[j] == '(') {
                reverse(cur++, j, s, ans);
                break;
            }
        }
        forn (j, 2 * i + 1, n) {
            if (s[j] == ')') {
                reverse(cur++, j, s, ans);
                break;
            }
        }
    }
    while (true) {
        bool found = false;
        forn (i, cur, n) {
            if (s[i] == '(') {
                reverse(cur++, i, s, ans);
                found = true;
                break;
            }
        }
        if (!found)
            break;
    }
    //cout << s << " ";
    cout << ans.size() << "\n";
    for (auto i : ans)
        cout << i.fs + 1 << " " << i.sc + 1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}