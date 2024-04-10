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

int n, x, y;

bool ask_1y(const vector<int>& a) {
    if (a.empty()) {
        return false;
    }
    cout << "? " << a.size();
    for (int i : a) {
        cout << " " << i + 1;
    }
    cout << endl;
    int r;
    cin >> r;
    return r == y || r == (x ^ y);
}

bool same[11];

void solve(istream& cin, ostream& cout) {
    cin >> n >> x >> y;
    int hb = -1;
    for (int i = 0; i < 10; i++) {
        vector<int> a;
        rep(j, 0, n) {
            if (hbit(j, i)) {
                a.push_back(j);
            }
        }
        if (ask_1y(a)) {
            hb = i;
        } else {
            same[i] = true;
        }
    }
    int a = 0;
    int b = 0;
    for (int i = 0; i < 10; i++) {
        if (i == hb) {
            b |= shl(hb);
            continue;
        }
        vector<int> v;
        rep(j, 0, n) {
            if (!hbit(j, i) && !hbit(j, hb)) {
                v.push_back(j);
            }
        }
        if (ask_1y(v)) {
            if (!same[i]) {
                b |= shl(i);
            }
        } else {
            a |= shl(i);
            if (same[i]) {
                b |= shl(i);
            }
        }
    }
    cout << "! " << a + 1 << " " << b + 1 << "\n";
}

int main() {
#if !defined(JLOCAL) || !STRESS
#ifdef JLOCAL
//    freopen("input.txt", "r", stdin);
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
}//kfotly