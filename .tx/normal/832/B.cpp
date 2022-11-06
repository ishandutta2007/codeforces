#include <bits/stdc++.h>
#ifdef JLOCAL
#include "stress.h"
#endif
using namespace std;

#define rep(i, z, n) for (int i = (z); i < int(n); ++i)
#define repr(i, n, z) for (int i = int(n) - 1; i >= (z); --i)
#define shl(n) (1 << (n))
#define hbit(n, i) (((n) >> (i)) & 1)

#define STRESS 0
using lint = long long;

bool good[333];

void solve(istream& cin, ostream& cout) {
    string s;
    cin >> s;
    for (char c : s) {
        good[c] = true;
    }

    string t;
    cin >> t;
    int ml = t.size();
    if (t.find('*') != string::npos) {
        ml--;
    }
    int n;
    cin >> n;
    rep(in, 0, n) {
        cout << "\n";
        cin >> s;
        if (s.size() < ml) {
            cout << "NO";
            continue;
        }
        int l = 0;
        while (l < t.size() && t[l] != '*') {
            if (s[l] == t[l] || t[l] == '?' && good[s[l]]) {
                l++;
            } else {
                break;
            }
        }
        if (l < t.size() && t[l] != '*') {
            cout << "NO";
            continue;
        }
        if (l == t.size() && l != s.size()) {
            cout << "NO";
            continue;
        }
        if (l == t.size() && l == s.size()) {
            cout << "YES";
            continue;
        }
        int r = t.size() - 1;
        while (r >= 0 && t[r] != '*') {
            int is = s.size() - (t.size() - r);
            if (s[is] == t[r] || t[r] == '?' && good[s[is]]) {
                r--;
            } else {
                break;
            }
        }
        if (r >= 0 && t[r] != '*') {
            cout << "NO";
            continue;
        }
        bool ok = true;
        for (int i = l; i <= (int)s.size() - ((int)t.size() - r); i++) {
            if (good[s[i]]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << "YES";
        } else {
            cout << "NO";
        }
    }
}

int main() {
#if !defined(JLOCAL) || !STRESS
#ifdef JLOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve(cin, cout);
#else
    srand();
    for (int ti = 0; ti < 100; ti++) {
        stress::gen();
        stress::stupid();
        ifstream in("input.txt");
        ofstream out("output.txt");
        solve(in, out);
        out.flush();
        stress::check();
    }
    cout << "ok" << endl;
#endif
    return 0;
}