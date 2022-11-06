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

int ys[1111];

bool one(int i, int j, int k) {
    return 1LL * (ys[j] - ys[i]) * (k - i) == 1LL * (ys[k] - ys[i]) * (j - i);
}

void solve(istream& cin, ostream& cout) {
    int n;
    cin >> n;
    rep(i, 0, n) {
        cin >> ys[i];
    }
    rep(f, 0, 3) {
        rep(s, f + 1, n) {
            vector<int> a, b;
            rep(i, 0, n) {
                if (one(f, s, i)) {
                    a.push_back(i);
                } else {
                    b.push_back(i);
                }
            }
            if (b.empty()) {
                continue;
            }
            if (b.size() == 1) {
                cout << "YES";
                return;
            }
            bool ok = true;
            for (int i : a) {
                if (one(b[0], b[1], i)) {
                    ok = false;
                    break;
                }
            }
            for (int i : b) {
                if (!one(b[0], b[1], i)) {
                    ok = false;
                    break;
                }
            }
            if (1LL * (ys[s] - ys[f]) * (b[1] - b[0]) != 1LL * (ys[b[1]] - ys[b[0]]) * (s - f)) {
                ok = false;
            }
            if (ok) {
                cout << "YES";
                return;
            }
        }
    }
    cout << "NO";
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