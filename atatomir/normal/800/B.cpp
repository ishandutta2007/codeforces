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

#define maxN 1024
#define eps 1e-7

struct Point {
    double x, y;

    bool operator==(Point &who) {
        if (-eps <= x - who.x && x - who.x <= eps)
            if (-eps <= y - who.y && y - who.y <= eps)
                return true;
        return false;
    }
};

int n, i;
Point P[maxN];
double ans = 1e36;

double dist(Point A, Point B) {
    B.x -= A.x;
    B.y -= A.y;
    return sqrt(B.x * B.x + B.y * B.y);
}

double cross(Point A, Point B, Point C) {
    B.x -= A.x;
    B.y -= A.y;

    C.x -= A.x;
    C.y -= A.y;

    return B.x * C.y - B.y * C.x;
}

double get_perp(Point A, Point B, Point C) {
    double area = abs(cross(A, B, C));
    return area / dist(B, C);
}

void check(Point A, Point B) {
    int i;

    for (i = 1; i <= n; i++) {
        if (P[i] == A) continue;
        if (P[i] == B) continue;

        ans = min(ans, get_perp(A, B, P[i]));
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%lf%lf", &P[i].x, &P[i].y);
    for (i = 1; i < n; i++) {
        check(P[i], P[i + 1]);
        check(P[i + 1], P[i]);
    }

    check(P[1], P[n]);
    check(P[n], P[1]);

    printf("%.10lf", ans / 2.00);

    return 0;
}