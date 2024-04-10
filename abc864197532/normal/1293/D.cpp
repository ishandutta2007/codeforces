#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<lli,lli>
vector <pii> points;
lli xs,ys;

bool able(int m, lli t) {
    lli maxx = LLONG_MAX;
    if (m == 0) return true;
    fop (i,0,points.size() - m + 1) {
        lli aa = min(abs(xs - points[i+m-1].first) + abs(ys - points[i+m-1].second), abs(xs - points[i].first) + abs(ys - points[i].second));
        aa += abs(points[i+m-1].first - points[i].first) + abs(points[i+m-1].second - points[i].second);
        if (aa >= 0) maxx = min(maxx, aa);
    }
    return maxx <= t;
}


int main () {
    lli x0,y0,ax,ay,bx,by,t, MAXX = 3*1e16;
    cin >> x0 >> y0 >> ax >> ay >> bx >> by >> xs >> ys >> t;
    while (true) {
        points.eb(x0,y0);
        x0 = ax * x0 + bx;
        y0 = ay * y0 + by;
        if (x0 >= MAXX or y0 >= MAXX) break;

    }
    int l = 0, r = points.size() + 1, m = l + r >> 1;
    while (r > l) {
        if (able(m,t)) l = m + 1;
        else r = m; 
        m = l + r >> 1;
    }
    cout << l - 1 << endl;
}