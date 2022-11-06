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

const int maxN = 100011;

struct point {
    ll x, y;

    ll dist(point who) {
        return (x - who.x) * (x - who.x) + (y - who.y) * (y - who.y);
    }

    bool operator<(const point& who)const {
        return mp(x, y) < mp(who.x, who.y);
    }
};

ll dot(point A, point B, point C) {
    B.x -= A.x;
    C.x -= A.x;

    B.y -= A.y;
    C.y -= A.y;

    return (B.x * C.x) + (B.y * C.y);
}

ll cross(point A, point B, point C) {
    B.x -= A.x;
    C.x -= A.x;

    B.y -= A.y;
    C.y -= A.y;

    return (B.x * C.y) - (B.y * C.x);
}


int n, m, i;
point P[maxN];
vector<ll> polyA, polyB;
vector<point> Hull;
vector<ll> data;

int get_best(int l, int r) {
    if (l == r) return l;

    int mid = (l + r) >> 1;
    int p1 = get_best(l, mid);
    int p2 = get_best(mid + 1, r);
    int sz = p2 - p1;

    for (int i = 0; i < sz; i++) {
        if (data[p1 + i] < data[p2 + i]) return p1;
        if (data[p1 + i] > data[p2 + i]) return p2;
    }

    return p1;
}

vector<ll> get_min_rot() {
    int n, i, pos;
    vector<ll> ans;

    n = data.size();
    for (i = 0; i < n; i++) data.pb(data[i]);

    pos = get_best(0, n - 1);
    ans.clear();

    for (i = 0; i < n; i++)
        ans.pb(data[pos + i]);

    return ans;
}

vector<ll> getPoly(int n) {
    int i, j, limit;
    vector<ll> ans;

    //! get convex hull
    sort(P + 1, P + n + 1);

    Hull = {P[1]};
    for (i = 2; i <= n; i++) {
        while (Hull.size() >= 2) {
            auto A = Hull[Hull.size() - 2];
            auto B = Hull[Hull.size() - 1];

            if (cross(A, B, P[i]) < 0) break;
            Hull.pop_back();
        }
        Hull.pb(P[i]);
    }

    limit = Hull.size();
    for (i = n - 1; i >= 1; i--) {
        while (Hull.size() >= limit + 1) {
            auto A = Hull[Hull.size() - 2];
            auto B = Hull[Hull.size() - 1];

            if (cross(A, B, P[i]) < 0) break;
            Hull.pop_back();
        }
        Hull.pb(P[i]);
    }

    //! get (not rotated) poly
    Hull.pb(Hull[1]);
    ans.clear();
    for (i = 0; i + 2 < Hull.size(); i++) {
        ans.pb(Hull[i].dist(Hull[i + 1]));
        ans.pb(dot(Hull[i + 1], Hull[i], Hull[i + 2]));
    }

    //! get rotated poly
    data = ans;
    ans = get_min_rot();

    return ans;
}

bool check() {
    if (polyA.size() != polyB.size()) return false;

    for (int i = 0; i < polyA.size(); i++)
        if (polyA[i] != polyB[i])
            return false;

    return true;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &m);


    for (i = 1; i <= n; i++) scanf("%lld%lld", &P[i].x, &P[i].y);
    polyA = getPoly(n);

    for (i = 1; i <= m; i++) scanf("%lld%lld", &P[i].x, &P[i].y);
    polyB = getPoly(m);

    if (check())
        printf("YES");
    else
        printf("NO");


    return 0;
}