#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 100011
#define eps 1e-7

struct Point {
    ll x, y;

    bool operator<(const Point& who) const {
        return mp(x, y) < mp(who.x, who.y);
    }
};

int n, i, tp;
ll mana, a, b, x, y, t, h;
ll last = 0;

set< Point > S;

ll cross(Point A, Point B, Point C) {
    B.x -= A.x;
    B.y -= A.y;

    C.x -= A.x;
    C.y -= A.y;

    return B.x * C.y - B.y * C.x;
}

void add_point(ll x, ll y) {
    Point P = {x, y};
    auto it = S.lower_bound(P);
    auto pre = it;

    // last point on hull
    if (it == S.end()) {
        S.insert(P);
    } else  {
        if (it->x == x) {
            // another point on hull with same x
            if (it->y <= y) return;
            S.erase(it);
            S.insert(P);
        } else {
            // no other point on hull with same x
            pre = it; pre--;
            if (cross(*pre, P, *it) <= 0LL) return;
            S.insert(P);
        }
    }

    // erase left points
    while (true) {
        it = S.lower_bound(P);
        pre = it; pre--;
        if (pre == S.begin()) break;
        auto prepre = pre; prepre--;

        if (cross(*prepre, *pre, *it) > 0LL) break;
        S.erase(pre);
    }

    // erase right points
    while (true) {
        it = S.lower_bound(P);
        auto nxt = it; nxt++;
        if (nxt == S.end()) break;
        auto nxtnxt = nxt; nxtnxt++;
        if (nxtnxt == S.end()) break;

        if (cross(*it, *nxt, *nxtnxt) > 0LL) break;
        S.erase(nxt);
    }
}

bool solve(ll t, ll h) {
    ll wanted_x = (h + t - 1) / t;
    auto it = S.lower_bound({wanted_x, 0});
    auto pre = it; pre--;

    if (it == S.end()) return false;

    Point p1 = *pre;
    Point p2 = *it;
    double x = 1.00 * h / t;
    double tg = (1.00 * p2.y - p1.y) / (1.00 * p2.x - p1.x);
    double y = 1.00 * p1.y + tg * (x - p1.x);
    double limit = 1.00 * mana / t;

    if (y <= limit + eps)
        return true;
    return false;
}

int main()
{
    //freopen("test.in","r",stdin);

    S.insert({0, 0});

    scanf("%d%lld", &n, &mana);
    for (i = 1; i <= n; i++) {
        scanf("%d%lld%lld", &tp, &a, &b);
        if (tp == 1) {
            x = (a + last) % 1000000; x++;
            y = (b + last) % 1000000; y++;

            add_point(x, y);
        } else {
            t = (a + last) % 1000000; t++;
            h = (b + last) % 1000000; h++;

            bool ans = solve(t, h);
            if (ans) {
                printf("YES\n");
                last = i;
            } else {
                printf("NO\n");
            }
        }
    }


    return 0;
}