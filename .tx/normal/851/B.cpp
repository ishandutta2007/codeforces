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

struct point {
    lint x, y;
};

lint operator*(const point& a, const point& b) {
    return a.x * b.y - a.y * b.x;
}

point operator-(const point& a, const point& b) {
    return point{a.x - b.x, a.y - b.y};
}

lint sq_dist(const point& a, const point& b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

bool can(const point& a, const point& b, const point& c) {
    if ((a - b) * (c - b) != 0 && sq_dist(a, b) == sq_dist(b, c)) {
//        cout << a.x << " " << a.y << endl;
//        cout << b.x << " " << b.y << endl;
//        cout << c.x << " " << c.y << endl;
        return true;
    }
    return false;
}

void solve(istream& cin, ostream& cout) {
    point a, b, c;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;

    if (can(a, b, c) ) {
        cout << "Yes";
    } else {
        cout << "No";
    }
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