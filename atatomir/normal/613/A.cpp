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

int n, i;
double R1, R2;
pair<double, double> P[maxN];

double dot(pii A, pii B) {
    return A.first * B.first + A.second * B.second;
}

pii diff(pii a, pii b) {
    return mp(a.first - b.first, a.second - b.second);
}

bool good(pii O, pii A, pii B) {
    if ( dot(diff(B, A), diff(O, A)) < 0 )
        return false;

    if ( dot(diff(A, B), diff(O, B)) < 0 )
        return false;

    return true;
}

double getMinimumDist(pii O, pii A, pii B) {
    if (!good(O, A, B))
        return 1e18;

    A.first -= O.first;
    A.second -= O.second;

    B.first -= O.first;
    B.second -= O.second;

    double area = A.first * B.second - A.second * B.first;
    area /= sqrt((A.first - B.first) * (A.first - B.first) + (A.second - B.second) * (A.second - B.second));

    if(area < 0)
        area *= -1;
    return area * area;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 0; i <= n; i++)
        scanf("%lf %lf", &P[i].first, &P[i].second);

    R1 = 1e80;
    R2 = 0.00;

    for (i = 1; i <= n; i++) {
        double dist = (P[i].first - P[0].first) * (P[i].first - P[0].first) +
                      (P[i].second - P[0].second) * (P[i].second - P[0].second);
        R1 = min(R1, dist);
        R2 = max(R2, dist);
    }

    P[n + 1] = P[1];
    for (i = 1; i <= n; i++)
        R1 = min(R1, getMinimumDist(P[0], P[i], P[i + 1]));


    double ans = (R2 - R1) * acos(-1);
    printf("%.20lf", ans);

    return 0;
}