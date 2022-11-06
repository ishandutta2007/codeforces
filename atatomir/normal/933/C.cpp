#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <complex>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define eps 1e-7
#define maxN 211

bool is_equal(double a, double b) {
    return -eps <= a - b && a - b <= eps;
}

struct Point {
    double x, y;

    bool operator==(Point who)const {
        return is_equal(x, who.x) && is_equal(y, who.y);
    }

    bool operator<(Point who)const {
        if (*this == who) return false;
        return mp(x, y) < mp(who.x, who.y);
    }
};

double dist_squared(Point A, Point B) {
    return (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y);
}

struct Circle {
    Point O;
    double R;

    bool on_circle(Point A) {
        double d = dist_squared(A, O);
        return (is_equal(d, R * R));
    }
};

int n, i, j, cnt_points, cnt_edges, cnt_comps, cnt_faces;
Circle C[maxN], act;
vector<Point> P;
vector<int> adj[maxN];
bool us[maxN];

bool any_intersection(Circle A, Circle B) {
    double R1 = A.R;
    double R2 = B.R;
    double dist = dist_squared(A.O, B.O);

    if (dist > (R1 + R2) * (R1 + R2) + eps) return false;
    if (dist < (R1 - R2) * (R1 - R2) - eps) return false;
    return true;
}

vector<Point> get_intersection(Circle A, Circle B) {
    complex<double> pA, pB;
    complex<double> trans, rot;
    complex<double> pAns, pAns2;
    Point ans, ans2;

    if (!any_intersection(A, B)) return {};

    pA = {A.O.x, A.O.y};
    pB = {B.O.x, B.O.y};

    trans = pA;
    pA -= trans;
    pB -= trans;

    rot = conj(pB) / sqrt(norm(pB));
    pA *= rot;
    pB *= rot;

    ans.x = (A.R * A.R - B.R * B.R + pB.real() * pB.real()) / (2.00 * pB.real());
    pAns.real(ans.x);

    ans.y = sqrt(max(0.00, A.R * A.R - ans.x * ans.x));
    pAns.imag(ans.y);
    pAns2 = conj(pAns);

    pAns /= rot;
    pAns2 /= rot;

    pAns += trans;
    pAns2 += trans;

    ans = {pAns.real(), pAns.imag()};
    ans2 = {pAns2.real(), pAns2.imag()};

    if (ans == ans2)
        return {ans};
    return {ans, ans2};
}

void dfs(int node) {
    us[node] = true;
    for (auto to : adj[node])
        if (!us[to])
            dfs(to);
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%lf%lf%lf", &C[i].O.x, &C[i].O.y, &C[i].R);
        act = C[i];

        P.pb({act.O.x - act.R, act.O.y});
        P.pb({act.O.x, act.O.y - act.R});
        P.pb({act.O.x + act.R, act.O.y});
        P.pb({act.O.x, act.O.y + act.R});
    }

    for (i = 1; i <= n; i++) {
        for (j = i + 1; j <= n; j++) {
            auto data = get_intersection(C[i], C[j]);
            for (auto e : data) P.pb(e);

            if (data.size() > 0) {
                adj[i].pb(j);
                adj[j].pb(i);
            }
        }
    }

    int i, j;
    for (i = 0; i < P.size(); i++) {
        for (j = i + 1; j < P.size(); j++) {
            if (P[i] == P[j]) {
                P[j] = P.back();
                P.pop_back();
                j--;
                continue;
            }
        }
    }

    cnt_points = P.size();
    for (i = 1; i <= n; i++) {
        for (auto p : P) {
            if (C[i].on_circle(p)) {
                cnt_edges++;
            }
        }
    }

    for (i = 1; i <= n; i++)
        if (!us[i])
            dfs(i), cnt_comps++;

    cnt_faces = 1 + cnt_edges - cnt_points + cnt_comps;
    printf("%d", cnt_faces);


    return 0;
}