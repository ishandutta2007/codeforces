#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 200011

struct Point {
    ll x, y;

    bool operator<(const Point& who) const {
        return mp(x, y) < mp(who.x, who.y);
    }

    bool operator==(const Point& who) const {
        return mp(x, y) == mp(who.x, who.y);
    }
};

int dim, n, i, cnt;
Point C[maxN];
map<Point, bool> M;
bool up, down, le, ri;
vector<Point> data, Hull;

ll cross(Point A, Point B, Point C) {
    B.x -= A.x;
    B.y -= A.y;

    C.x -= A.x;
    C.y -= A.y;

    return B.x * C.y - B.y * C.x;
}

void build_hull() {
    Hull.clear();
    sort(data.begin(), data.end());
    data.resize(unique(data.begin(), data.end()) - data.begin());
    dim = 2;
    for (auto p : data) {
        while (Hull.size() >= dim) {
            if (cross(Hull[Hull.size() - 2], Hull.back(), p) < 0) break;
            Hull.pop_back();
        }
        Hull.pb(p);
    }

    data.pop_back();
    reverse(data.begin(), data.end());
    dim = Hull.size() + 1;
    for (auto p : data) {
        while (Hull.size() >= dim) {
            if (cross(Hull[Hull.size() - 2], Hull.back(), p) < 0) break;
            Hull.pop_back();
        }
        Hull.pb(p);
    }

    Hull.pop_back();
}

void build_hull_of_cells() {
    int i;

    data.clear();
    for (i = 1; i <= n; i++) data.pb(C[i]);
    build_hull();

    n = 0;
    for (auto e : Hull) C[++n] = e;
    data.clear();
}

int main()
{
    //freopen("test.in","r",stdin);

    while (scanf("%d%d", &dim, &n)) {
        if (dim == 0 && n == 0) return 0;
        M.clear();
        data.clear();

        for (i = 1; i <= n; i++) scanf("%lld%lld", &C[i].x, &C[i].y), M[C[i]] = true;
        build_hull_of_cells();
        for (i = 1; i <= n; i++) {
            auto act = C[i];
            cnt = 0;

            up = M[{act.x, act.y + 1}]; cnt += up;
            down = M[{act.x, act.y - 1}]; cnt += down;
            le = M[{act.x - 1, act.y}]; cnt += le;
            ri = M[{act.x + 1, act.y}]; cnt += ri;

            if (cnt != 2) continue;
            if (up && le) data.pb({act.x - 1, act.y});
            if (up && ri) data.pb({act.x, act.y});
            if (down && le) data.pb({act.x - 1, act.y - 1});
            if (down && ri) data.pb({act.x, act.y - 1});
        }

        build_hull();
        printf("%d\n", Hull.size());
        for (auto e : Hull)
            printf("%lld %lld\n", e.x, e.y);
    }


    return 0;
}