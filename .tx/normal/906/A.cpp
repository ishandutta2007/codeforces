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

bool cant[26];
bool cur[26];

void solve(istream &cin, ostream &cout) {
    int n;
    cin >> n;
    string s, t;
    bool done = false;
    int ans = 0;
    rep(in, 0, n - 1) {
        cin >> s >> t;
        fill(cur, cur + 26, false);
        for (char c : t) {
            cur[c - 'a'] = true;
        }
        if (s == "!") {
            for (int i = 0; i < 26; i++) {
                if (!cur[i]) {
                    cant[i] = true;
                }
            }
            if (done) {
                ans++;
            }
        } else if (s == ".") {
            for (int i = 0; i < 26; i++) {
                if (cur[i]) {
                    cant[i] = true;
                }
            }
        } else {
            cant[t[0] - 'a'] = true;
            if (done) {
                ans++;
            }
        }
        int cc = 0;
        for (int i = 0; i < 26; i++) {
            if (cant[i]) {
                cc++;
            }
        }
        if (cc == 25) {

            done = true;
        }
    }
    cout << ans;
}

int main() {
#if !defined(JLOCAL) || !STRESS
#ifdef JLOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
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