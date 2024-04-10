#include <bits/stdc++.h>

using namespace std;
#define link alflak
#define fpos ladla
#define all(x) begin(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define int int64_t

typedef long double ftype;
typedef complex<ftype> point;
#define x real
#define y imag

ftype cross(point a, point b) {
    return (conj(a) * b).y();
}

point inter(point a, point b, point c, point d) {
    return a + (b - a) * cross(c - a, d - c) / cross(b - a, d - c);
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ftype aa, bb, cc;
    ftype x1, y1, x2, y2;
    cin >> aa >> bb >> cc;
    cin >> x1 >> y1 >> x2 >> y2;
    point a = {x1, y1}, b = {x2, y2};
    point c = {x1, y2}, d = {x2, y1};
    pair<point, point> segs[4] = {{a, c}, {a, d}, {b, c}, {b, d}};
    ftype ans = abs(x1 - x2) + abs(y1 - y2);
    if(aa != 0 && bb != 0) {
        point A = {- cc / aa, 0};
        point B = A + point(0, 1) * point(aa, bb);
        for(int i = 0; i < 2; i++) {
            for(int j = 2; j < 4; j++) {
                point o1 = inter(segs[i].first, segs[i].second, A, B);
                point o2 = inter(segs[j].first, segs[j].second, A, B);
                ans = min(ans, abs(a - o1) + abs(o1 - o2) + abs(o2 - b));
            }
        }
    }
    cout << fixed << setprecision(12);
    cout << ans << endl;
    return 0;
}