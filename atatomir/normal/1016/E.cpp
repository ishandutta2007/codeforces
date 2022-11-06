#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

const int maxN = 200011;
const double eps = 1e-6;

struct segm {
    double a, b;
};

struct point {
    double x, y;
};

struct line {
    double a, b, c;

    double eval(point P) {
        return a * P.x + b * P.y + c;
    }

    void from_points(point A, point B) {
        a = B.y - A.y;
        b = A.x - B.x;
        c = -(a * A.x + b * A.y);

        //if (abs(eval(A) - 0.00) > eps) cerr << "Err1";
        //if (abs(eval(B) - 0.00) > eps) cerr << "Err2";
    }

    point operator+(line B) {
        line A = *this;

        double upx = A.b * B.c - A.c * B.b;
        double upy = A.a * B.c - A.c * B.a;
        double down = A.a * B.b - A.b * B.a;

        double x = upx / down;
        double y = -upy / down;

        //if (abs(eval({x, y}) - 0.00) > eps) cerr << "Err3";
        //if (abs(B.eval({x, y}) - 0.00) > eps) cerr << "Err4";

        return {x, y};
    }
};

double sy, a, b;
int n, i, q;
segm S[maxN];
point P[maxN];

line base;
double len[maxN];

int find_first(point P) {
    int ans = 0;
    double act;
    line aux;

    for (int step = 1 << 18; step > 0; step >>= 1) {
        if (ans + step > n) continue;

        act = S[ans + step].b;
        aux.from_points(P, {act, 0});
        act = (aux + base).x;
        if (act < a + eps) ans += step;
    }

    return ans + 1;
}

int find_last(point P) {
    int ans = 0;
    double act;
    line aux;

    for (int step = 1 << 18; step > 0; step >>= 1) {
        if (ans + step > n) continue;

        act = S[ans + step].a;
        aux.from_points(P, {act, 0});
        act = (aux + base).x;
        if (act <= b + eps) ans += step;
    }

    return ans;
}

double get_inters(point P, segm S) {
    double act, p1, p2;
    line aux;

    act = S.a;
    aux.from_points(P, {act, 0});
    act = (aux + base).x;
    p1 = max(a, act);

    act = S.b;
    aux.from_points(P, {act, 0});
    act = (aux + base).x;
    p2 = min(b, act);

    return max(0.00, p2 - p1);
}

double solve(point P) {
    int bg = find_first(P);
    int en = find_last(P);

    if (bg > en) return 0;

    double sol = get_inters(P, S[bg]);
    if (bg != en) sol += get_inters(P, S[en]);

    double coef = (P.y - sy) / P.y;
    if (en - bg >= 2) sol += (len[en - 1] - len[bg]) * coef;

    return sol;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%lf%lf%lf", &sy, &a, &b);
    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%lf%lf", &S[i].a, &S[i].b);
    scanf("%d", &q);
    for (i = 1; i <= q; i++) scanf("%lf%lf", &P[i].x, &P[i].y);

    base.from_points({a, sy}, {b, sy});
    for (i = 1; i <= n; i++) {
        len[i] = S[i].b - S[i].a;
        len[i] += len[i - 1];
    }

    for (i = 1; i <= q; i++) {
        double ans = solve(P[i]);
        printf("%.20f\n", ans);
    }


    return 0;
}