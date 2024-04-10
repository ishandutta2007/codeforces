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
    string s;
    cin >> s;
    forn (i, '0', '9' + 1) {
        char last = '0';
        int left_to_right = 0, right_to_left = sz(s) - 1;
        bool ok = true;
        forn (j, 0, n) {
            if (s[j] < i) {
                if (s[j] < last)
                    ok = false;
                left_to_right = j;
                last = s[j];
            }
        }
        if (!ok)
            continue;
        ok = true;
        last = '0';
        forn (j, 0, n) {
            if (s[j] > i) {
                if (s[j] < last)
                    ok = false;
                right_to_left = min(right_to_left, j);
                last = s[j];
            }
        }
        if (!ok)
            continue;
        ok = true;
        forn (j, right_to_left, left_to_right + 1)
            if (s[j] == i)
                ok = false;
        if (ok) {
            //cout << (char)i << ":\n";
            //cout << left_to_right << " " << right_to_left << "\n";
            forn (j, 0, n) {
                if (s[j] < i || (s[j] == i && j > left_to_right))
                    cout << '1';
                else 
                    cout << '2';
            }
            cout << "\n";
            return;
        }
    }
    cout << "-\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int q;
    cin >> q;
    while (q --> 0)
        solve();
    return 0;
}