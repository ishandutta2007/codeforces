#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 2017
#define eps 1e-7

struct Point {
    double x, y;

    Point() {}

    Point(double a, double b) {
        x = a; y = b;
    }

    Point operator+(Point who) {
        return {x + who.x, y + who.y};
    }

    Point operator-(Point who) {
        return {x - who.x, y - who.y};
    }

    Point operator/(double val) {
        return {x / val, y / val};
    }

    Point operator*(double val) {
        return {x * val, y * val};
    }

    bool operator==(const Point who)const {
        return max(abs(x - who.x), abs(y - who.y)) <= eps;
    }

    bool operator<(const Point who)const {
        if (*this == who) return false;
        return mp(x, y) < mp(who.x, who.y);
    }
};

struct Line {
    double a, b, c;

    Line() {};

    Line(double _a, double _b, double _c) {
        a = _a;
        b = _b;
        c = _c;
    }

    Line(Point A, Point B) {
        a = B.y - A.y;
        b = A.x - B.x;
        c = -(A.x * a + B.x * b);
    }

    Line operator||(Point A) {
        return {a, b, -(a * A.x + b * A.y)};
    }

    Line perp() {
        Line ans = {a, b, c};
        swap(ans.a, ans.b);
        ans.a *= -1;
        return ans;
    }

    Point intersect(Line who) {
        double up_x = who.c * b - c * who.b;
        double up_y = c * who.a - a * who.c;
        double down = a * who.b - b * who.a;
        return {up_x / down, up_y / down};
    }

    bool is_parallel(Line who) {
        return abs(a * who.b - b * who.a) <= eps;
    }
};

int n, i, j, ans;
Point P[maxN], mid, Origin(0.00, 0.00);
bool used[maxN];
Line aux;

Point _P[maxN], _mid;
map<Point, int> M;
vector<Line> ant;


void remove_sym() {
    int i, j;

    for (i = 1; i <= n; i++) {
        for (j = i; j <= n; j++) {
            if (used[j]) continue;

            if (P[i] + P[j] == mid * 2) {
                used[i] = used[j] = true;
                break;
            }
        }
    }
}

Point get_proj(Point A, Line L) {
    Line aux = (L.perp() || A);
    return aux.intersect(L);
}

bool check(Line act) {
    int i;
    int rm = 0;
    Point sym;

    M.clear();
    _mid = get_proj(mid, act);
    for (i = 1; i <= n; i++) {
        _P[i] = get_proj(P[i], act);

        if (_P[i] == _mid) {
            rm++;
            continue;
        }

        sym = _mid * 2 - _P[i];
        if (M[sym] > 0) {
            rm += 2;
            M[sym]--;
            continue;
        }

        M[_P[i]]++;
    }

    if (rm != n) return false;
    return true;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    mid = {0, 0};

    for (i = 1; i <= n; i++) {
        scanf("%lf%lf", &P[i].x, &P[i].y);
        mid = mid + P[i];
    }

    mid = mid / n;
    remove_sym();

    for (i = 1; used[i] && i <= n; i++);
    if (i == n + 1) {
        printf("-1");
        return 0;
    }

    for (j = i; j <= n; j++) {
        if (used[j]) continue;
        aux = Line(mid, (P[i] + P[j]) / 2);
        aux = (aux.perp() || Origin);

        bool ok = true;
        for (auto e : ant) {
            if (e.is_parallel(aux)) {
                ok = false;
                break;
            }
        }

        if (!ok) continue;
        ant.pb(aux);

        if (check(aux))
            ans++;
    }

    printf("%d", ans);


    return 0;
}