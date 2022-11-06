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
    int n;
    string s;
    cin >> n >> s;
    rep(i, 1, n) {
        if (s[i] != '?' && s[i] == s[i - 1]) {
            cout << "No";
            return;
        }
    }
    int cb = 0;
    rep(i, 1, n - 1) {
        if (s[i] == '?' && s[i - 1] != '?' && s[i + 1] != '?' && s[i - 1] != s[i + 1]) {
            cb++;
        }
    }
    if (cb == count(s.begin(), s.end(), '?')) {
        cout << "No";
        return;
    }
    cout << "Yes";
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