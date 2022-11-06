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
    double r, x1, y1, x2, y2;
    cin >> r >> x1 >> y1 >> x2 >> y2;
    double dist = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));

    if (dist >= r) {
        cout << setprecision(11) << fixed << x1 << " " << y1 << " " << r;
        return;
    }

    double dx = x1 - x2;
    double dy = y1 - y2;
    double dd = sqrt(dx * dx + dy * dy);

    if (abs(dd) < 1e-9) {
        cout << setprecision(11) << fixed << x1 << " " << y1 + r / 2 << " " << r / 2;
        return;
    }

    dx /= dd;
    dy /= dd;
    dx *= (dist + r) / 2;
    dy *= (dist + r) / 2;
    cout << setprecision(11) << fixed << x2 + dx << " " << y2 + dy << " " << (dist + r) / 2;
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