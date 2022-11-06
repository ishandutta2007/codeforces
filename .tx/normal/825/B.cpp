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

string a[11];
int n = 10;

bool check(int x, int y) {
    return !(x < 0 || x >= n || y < 0 || y >= n);
}

bool xrow(int x, int y, int dx, int dy) {
    for (int i = 0; i < 5; i++) {
        if (!check(x + dx * i, y + dy * i) || a[x + dx * i][y + dy * i] != 'X') {
            return false;
        }
    }
    return true;
}

bool xwin() {
    rep(i, 0, n) {
        rep(j, 0, n) {
            if (xrow(i, j, 0, 1) || xrow(i, j, 1, 0) || xrow(i, j, 1, 1) || xrow(i, j, -1, 1)) {
                return true;
            }
        }
    }
    return false;
}

void solve(istream& cin, ostream& cout) {
    rep(i, 0, n) {
        cin >> a[i];
    }

    rep(i, 0, n) {
        rep(j, 0, n) {
            if (a[i][j] == '.') {
                a[i][j] = 'X';
                if (xwin()) {
                    cout << "YES";
                    return;
                }
                a[i][j] = '.';
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
}//pek