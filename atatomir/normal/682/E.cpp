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

#define maxN 15016

struct Point {
    int x, y;

    Point operator-(const Point &a) {
        static Point aux;

        aux.x = x - a.x;
        aux.y = y - a.y;

        return aux;
    }

    bool operator<(const Point& who)const {
        return mp(x, y) < mp(who.x, who.y);
    }
};

ll cross(Point A, Point B) {
    return 1LL * A.x * B.y - 1LL * A.y * B.x;
}

ll area(Point A, Point B, Point C) {
    return cross(B - A, C - A);
}

Point symmetric(Point A, Point B, Point C) {
    B = B - A;
    C = C - A;

    A.x += B.x + C.x;
    A.y += B.y + C.y;

    return A;
}



int n, m, i, p1, p2, p3;
ll S;
Point P[maxN];
vector<Point> Hull;

Point A, B, C;


void make_hull() {
    int i, sz;
    int lim;

    sort(P + 1, P + n + 1);
    for (i = 1; i <= n; i++) P[n + i] = P[n - i + 1];

    Hull.pb(P[1]);
    lim = 2;

    for (i = 2; i <= 2 * n; i++) {
        if (i == n + 1)
            lim = Hull.size() + 1;

        while (Hull.size() >= lim) {
            sz = Hull.size() - 1;

            if (area(Hull[sz - 1], Hull[sz], P[i]) < 0) break;
            Hull.pop_back();
        }

        Hull.pb(P[i]);
    }

    n = Hull.size() - 1;
    for (i = 0; i < n; i++) P[i + 1] = Hull[i];
    for (i = 1; i <= n; i++) P[n + i] = P[i];
}

ll biggest(int p1, int p2) {
    int l = p2 + 1;
    int r = p1 + n - 1;
    int m1, m2;

    for (int step = 20; step > 0 && r - l + 1 > 3; step--) {
        m1 = (2 * l + r) / 3;
        m2 = (l + 2 * r) / 3;

        if ( abs(area(P[p1], P[p2], P[m1])) > abs(area(P[p1], P[p2], P[m2])) )
            r = m2;
        else
            l = m1;
    }

    ll val = abs(area(P[p1], P[p2], P[l]));
    int best = l;

    for (int i = l + 1; i <= r; i++) {
        ll act = abs(area(P[p1], P[p2], P[i]));

        if (val < act) {
            val = act;
            best = i;
        }
    }

    p3 = best;
    return val;
}

bool good(Point A, Point B, Point C) {
    int i;
    Point act;
    ll def = abs(area(A, B, C));

    for (i = 1; i <= n; i++) {
        act = P[i];

        ll aux = abs(area(A, B, act)) + abs(area(B, C, act)) + abs(area(C, A, act));
        if (aux != def)
            return false;
    }

    return true;
}



int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%lld", &n, &S);
    for (i = 1; i <= n; i++) scanf("%d%d", &P[i].x, &P[i].y);

    make_hull();

    for (p1 = p2 = 1; p1 + 2 <= n; p1++) {
        p2 = max(p1 + 1, p2);

        while ( biggest(p1, p2) < biggest(p1, p2 + 1) && p2 + 2 < p1 + n) p2++;
        biggest(p1, p2);

        A = symmetric(P[p1], P[p2], P[p3]);
        B = symmetric(P[p2], P[p1], P[p3]);
        C = symmetric(P[p3], P[p2], P[p1]);

        if (good(A, B, C)) {
            printf("%d %d\n", A.x, A.y);
            printf("%d %d\n", B.x, B.y);
            printf("%d %d\n", C.x, C.y);

            return 0;
        }
    }

    return 0;
}