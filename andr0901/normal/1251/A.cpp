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

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0) {
        string s;
        cin >> s;
        vector <bool> correct(26, false);
        int idx = -1;
        s += '#';
        forn (i, 0, sz(s)) {
            if (idx == -1)
                idx = i;
            if (i && s[i] != s[i - 1]) {
                if ((i - idx) % 2)
                    correct[s[i - 1] - 'a'] = true;
                idx = i;
            }
        }
        forn (i, 0, sz(correct))
            if (correct[i])
                cout << static_cast<char>(i + 'a');
        cout << "\n";
    }
    return 0;
}