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

#define maxN 100011
#define eps (1e-9)

const double PI = acos(-1.00);

int n, i;
double X0, Y0, X, Y, R;
double speed, deadline, D;

vector< pair<double, double> > work;

double sum, last;

ll aux1, aux2, aux3;

int steps;
double xx, yy, ang, l, r, m1, m2, ang1, ang2, ans, a1, a2;



double dist(double x, double y) {
    return x * x + y * y;
}

pair<double, double> get_intr() {
    double xx, yy;
    double act_dist = dist(X, Y);

    if (act_dist > (D + R) * (D + R)) return mp(0.00, 0.00);

    double alfa1 = (R * R + act_dist - D * D) / (2 * R * sqrt(act_dist));
    alfa1 = acos(alfa1);

    double alfa2 = R / sqrt(act_dist);
    alfa2 = PI / 2 - asin(alfa2);

    if (D > sqrt(act_dist + R * R)) alfa1 = 1e18;

    if (alfa1 < alfa2) {
        alfa1 = (D * D + act_dist - R * R) / (2 * D * sqrt(act_dist));
        alfa1 = acos(alfa1);
    } else {
        alfa1 = R / sqrt(act_dist);
        alfa1 = asin(alfa1);
    }

    double ang = atan2(Y, X);
    double a1 = ang - alfa1;
    double a2 = ang + alfa1;


    a1 += 4 * PI; a2 += 4 * PI;
    while (a1 > PI) a1 -= 2 * PI;
    while (a2 > PI) a2 -= 2 * PI;

    if (a1 > a2) swap(a1, a2);
    return mp(a1, a2);
}


int main()
{
    //freopen("test.in","r",stdin);

    scanf("%lf%lf%lf%lf", &X0, &Y0, &speed, &deadline);
    D = speed * deadline;

    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%lf%lf%lf", &X, &Y, &R); R += eps;
        X -= X0;
        Y -= Y0;

        aux1 = R;
        aux2 = X;
        aux3 = Y;
        if (aux1 * aux1 - aux2 * aux2 - aux3 * aux3 >= 0) {
            printf("1.00");
            return 0;
        }

        auto act = get_intr();

        if (act.second - act.first <= PI) {
            work.pb(act);
        } else {
            work.pb(mp(act.second, PI));
            work.pb(mp(-PI, act.first));
        }
    }

    sort(work.begin(), work.end());

    sum = 0.00;
    last = -PI;

    for (auto e : work) {
        last = max(last, e.first);
        sum += max(0.00, e.second - last);
        last = max(last, e.second);
    }

    printf("%.9lf", sum / (2 * PI) );

    return 0;
}