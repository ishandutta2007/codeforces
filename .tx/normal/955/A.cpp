#include <bits/stdc++.h>
#ifdef JLOCAL
#include "stress.h"
#endif
using namespace std;

#define rep(i, z, n) for (int i = (z); i < int(n); ++i)
#define repr(i, n, z) for (int i = int(n) - 1; i >= (z); --i)
#define shl(n) (1 << (n))
#define hbit(n, i) (((n) >> (i)) & 1)
#define min mmin
#define max mmax

auto min = [](auto x, auto y) { return x < y ? x : y;};
auto max = [](auto x, auto y) { return x < y ? y : x;};

#define STRESS 0
using lint = long long;
template <typename T> using vc = std::vector<T>;

void solve(istream& cin, ostream& cout) {
    lint hh, m, h, d, c, n;
    cin >> hh >> m >> h >> d >> c >> n;
    m += hh * 60;
    lint k = (h + n - 1) / n;
    lint ans = k * c;

    lint x = max(0, 20 * 60 - m);
    lint k2 = (h + x * d + n - 1) / n;
    double ans2 = 0.8 * k2 * c;
    cout << fixed << setprecision(11) << min(ans2, ans);
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