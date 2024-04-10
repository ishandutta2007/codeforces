#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back

#define maxN 100011
#define pii pair<double, double>
#define eps 1e-13
#define inf 1e80

int n, i;
double p, q, max_x, max_y;
pii Points[maxN];
vector<pii> hull;

pii ans;

struct Line {
    double a, b, c;

    void get_from(pii p1, pii p2) {
        a = p2.second - p1.second;
        b = p1.first - p2.first;
        c = -( p1.first * a + p1.second * b );
    }

    pii intersect(Line& who) {
        double supp_x = b * who.c - who.b * c;
        double supp_y = a * who.c - who.a * c;
        double subb = who.a * b - a * who.b;

        if (-eps < subb && subb < eps)
            return mp(inf, inf);

        return mp(-supp_x / subb, supp_y / subb);
    }
};

double cross(pii a, pii b) {
    return a.first * b.second - a.second * b.first;
}

pii diff(pii a, pii b) {
    return mp(a.first - b.first, a.second - b.second);
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%lf%lf\n", &n, &p, &q);
    for (i = 1; i <= n; i++) {
        scanf("%lf %lf", &Points[i].first, &Points[i].second);
        max_x = max(max_x, Points[i].first);
        max_y = max(max_y, Points[i].second);
    }

    Points[++n] = mp(0, max_y + eps);
    Points[++n] = mp(max_x + eps, 0);

    sort(Points + 1, Points + n + 1);

    //! hull

    hull.pb(Points[1]);
    hull.pb(Points[2]);
    for (i = 3; i <= n; i++) {
        int sz = hull.size() - 1;

        while ( cross( diff(hull[sz], hull[sz - 1]),
                       diff(Points[i], hull[sz - 1])) > -eps ) {
            hull.pop_back();
            if (--sz < 1) break;
        }

        hull.pb(Points[i]);
    }

    int lim = hull.size();
    hull.pb(Points[n - 1]);

    for (i = n - 2; i >= 1; i--) {
        int sz = hull.size() - 1;

        while ( cross( diff(hull[sz], hull[sz - 1]),
                       diff(Points[i], hull[sz - 1])) > -eps ) {
            hull.pop_back();
            if (--sz < lim) break;
        }

        hull.pb(Points[i]);
    }

    //! hull

    Line origin ;
    origin.get_from(mp(0, 0), mp(p, q));

    for (i = 1; i < hull.size(); i++) {
        pii p1 = hull[i - 1];
        pii p2 = hull[i];

        double cross1 = cross(mp(p, q), p1);
        double cross2 = cross(mp(p, q), p2);

        if (cross1 * cross2 > eps)
            continue;

        Line aux;
        aux.get_from(p1, p2);

        pii aux_p = origin.intersect(aux);
        ans = max(ans, aux_p);

        break;
    }

    printf("%.10lf", q / ans.second);

    return 0;
}