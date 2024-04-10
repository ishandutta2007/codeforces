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
    int c1 = 0, c2 = 0;
    rep(i, 0, n) {
        string s, t;
        cin >> s >> t;
        if (t == "soft") {
            c1++;
        } else {
            c2++;
        }
    }
    rep(i, 1, 1000) {
        int k1 = (i * i + 1) / 2;
        int k2 = i * i - k1;
        if (k1 >= max(c1, c2) && k2 >= min(c1, c2)) {
            cout << i;
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