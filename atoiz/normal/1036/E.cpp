#include <algorithm>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

pair<int, int> inter(int Ax, int Ay, int Bx, int By, int Cx, int Cy, int Dx, int Dy)
{
	long long a1 = Ay - By, b1 = Bx - Ax, c1 = 1ll * Bx * Ay - 1ll * Ax * By;
	long long a2 = Cy - Dy, b2 = Dx - Cx, c2 = 1ll * Dx * Cy - 1ll * Cx * Dy;

//    cout << 1ll * a1 * Ax << " + " << 1ll * b1 * Ay << " = " << c1 << endl;
//    cout << 1ll * a1 * Bx << " + " << 1ll * b1 * By << " = " << c1 << endl;
//    cout << 1ll * a2 * Cx << " + " << 1ll * b2 * Cy << " = " << c2 << endl;
//    cout << 1ll * a2 * Dx << " + " << 1ll * b2 * Dy << " = " << c2 << endl;

    if (1ll * a1 * b2 == 1ll * a2 * b1) return make_pair(INF, INF);

    long long ya = 1ll * c1 * a2 - 1ll * a1 * c2;
//    cerr << 1ll * c1 * a2 << ' ' << c1 << ' ' << a2 << endl;
    long long yb = 1ll * b1 * a2 - 1ll * a1 * b2;

    if (ya % yb != 0) return make_pair(INF, INF);
    long long y = ya / yb;

    long long xa = 1ll * c1 * b2 - 1ll * b1 * c2;
    long long xb = 1ll * a1 * b2 - 1ll * b1 * a2;
    if (xa % xb != 0) return make_pair(INF, INF);
	long long x = xa / xb;

    if (x < min(Ax, Bx) || x > max(Ax, Bx)) return make_pair(INF, INF);
    if (x < min(Cx, Dx) || x > max(Cx, Dx)) return make_pair(INF, INF);
    if (y < min(Ay, By) || y > max(Ay, By)) return make_pair(INF, INF);
    if (y < min(Cy, Dy) || y > max(Cy, Dy)) return make_pair(INF, INF);

    return make_pair(x, y);
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    int Ax[n], Bx[n], Ay[n], By[n];
    for (int i = 0; i < n; ++i) cin >> Ax[i] >> Ay[i] >> Bx[i] >> By[i];

    int ans = 0;
    for (int i = 0; i < n; ++i) ans += 1 + __gcd(abs(Ax[i] - Bx[i]), abs(Ay[i] - By[i]));

    vector< pair<int, int> > vec;
    vec.reserve(n*n);
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
			pair<int, int> p = inter(Ax[i], Ay[i], Bx[i], By[i], Ax[j], Ay[j], Bx[j], By[j]);
            if (p.first != INF) vec.push_back(p);
//            if (p.first != INF) cerr << i << ' ' << j << ": " << p.first << ' ' << p.second << endl;
        }
    }

//	cerr << vec.size() << endl;

    sort(vec.begin(), vec.end());
    for (int l = 0; l < vec.size(); ++l) {
        int r = l;
        while (r+1 < vec.size() && vec[l] == vec[r+1]) ++r;
        int a = r - l + 1;
        int x = (sqrt(8*a + 1) + 1) / 2;
        ans -= x - 1;
//		cerr << l << ' ' << r << endl;
        l = r;
    }

    cout << ans;
}