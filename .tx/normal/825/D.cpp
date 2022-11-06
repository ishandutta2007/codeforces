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

int cnt[256];

void solve(istream& cin, ostream& cout) {
    string s, t;
    cin >> s >> t;
    rep(i, 0, s.size()) {
        cnt[s[i]]++;
    }
    vector<char> rp;
    while (true) {
        bool ok = true;
        rep(i, 0, t.size()) {
            if (cnt[t[i]]) {
//                cout << t[i];
                cnt[t[i]]--;
            } else if (cnt['?']) {
//                cout << t[i];
                rp.push_back(t[i]);
                cnt['?']--;
            } else {
                ok = false;
                break;
            }
        }
        if (!ok) {
            break;
        }
    }
    rep(i, 0, s.size()) {
        if (s[i] == '?') {
            cout << rp.back();
            rp.pop_back();
        } else {
            cout << s[i];
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
}//jdwfze