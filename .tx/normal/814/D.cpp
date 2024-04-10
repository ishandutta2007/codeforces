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

struct circle {
    int x, y, r;
};

bool inside(const circle& in, const circle& out) {
    double d = sqrt(1LL * (in.x - out.x) * (in.x - out.x) + 1LL * (in.y - out.y) * (in.y - out.y));
    return d + in.r < out.r + 1e-9;
}

void solve(istream& cin, ostream& cout) {
    int n;
    cin >> n;
    vector<circle> a(n);
    rep(i, 0, n) {
        cin >> a[i].x >> a[i].y >> a[i].r;
    }
    sort(a.begin(), a.end(), [](const auto& p, const auto& q) {
        return p.r > q.r;
    });

    double ans = 0;
    rep(i, 0, n) {
        int cnt = 0;
        rep(j, 0, i) {
            if (inside(a[i], a[j])) {
                cnt++;
            }
        }
        if (cnt <= 1 || (cnt % 2 == 1)) {
            ans += acos(-1.0) * a[i].r * a[i].r;
        } else {
            ans -= acos(-1.0) * a[i].r * a[i].r;
        }
    }

    cout << setprecision(11) << fixed << ans;
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
}//kzheva