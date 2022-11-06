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
template <typename T> using vc = std::vector<T>;

void solve(istream& cin, ostream& cout) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    set<char> al;
    rep(i, 0, n) {
        al.insert(s[i]);
    }
    if (k > n) {
        cout << s;
        rep(i, 0, k - n) {
            cout << *al.begin();
        }
        return;
    }
    repr(i, k, 0) {
        if (s[i] != *al.rbegin()) {
            s[i] = *al.upper_bound(s[i]);
            rep(j, i + 1, k) {
                s[j] = *al.begin();
            }
            cout << s.substr(0, k);
            return;
        }
    }
    assert(false);
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