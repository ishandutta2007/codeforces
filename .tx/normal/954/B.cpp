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
    cin >> n;
    string ss;
    cin >> ss;
    const char* s = ss.c_str();
    vector<int> d(n, 1e9);
    vector<int> t(n, 1e9);
    d[0] = 1;
    rep(i, 1, n) {
        d[i] = min(d[i], d[i - 1] + 1);
        t[i] = min(t[i], t[i - 1] + 1);
        if (i * 2 <= n && memcmp(s, s + i, i) == 0) {
            t[i * 2 - 1] = min(t[i * 2 - 1], d[i - 1] + 1);
        }
    }
    cout << min(d[n - 1], t[n - 1]);
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