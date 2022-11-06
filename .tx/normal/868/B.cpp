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

double hh;
double mm;
double ss;

bool btw(int t1, double x, int t2) {
    return t1 < x - 1e-9 && x < t2 - 1e-9;
}

bool can_move(int t1, int t2) {
    return !btw(t1, hh, t2) && !btw(t1, mm, t2) && !btw(t1, ss, t2);
}

double a[5];

void solve(istream& cin, ostream& cout) {
    int h, m, s, t1, t2;
    cin >> h >> m >> s >> t1 >> t2;
    h %= 12;
    s += m * 60 + h * 3600;
    t1 %= 12;
    t2 %= 12;

    a[0] = s / 3600.0;
    a[1] = (s % 3600) / 60.0 / 5.0;
    a[2] = (s % 60) / 5.0;
    a[3] = t1;
    a[4] = t2;
    sort(a, a + 5);
    rep(i, 0, 5) {
        if (a[i] == t1 || a[i] == t2) {
            if (a[(i + 1) % 5] == t1 || a[(i + 1) % 5] == t2) {
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