#pragma target("sse4")
#include<bits/stdc++.h>
 
using namespace std;
 
struct pt {
    double x, y, r;
};
 
int const maxn = 1e5 + 5;
pt a[maxn];
double pi = atan2(0, -1);
double eps = 0.000000001;
pt ans[5];
int cur;
double Inf = 3000.0 * 1000.0 * 1000.0;
double s, F, x, A, B, C, y, go, d, f, h, x1;
 
inline double cross(pt a, pt b) {
    return a.x * b.y - a.y * b.x;
}
 
inline double dot(pt a, pt b) {
    return a.x * b.x + a.y * b.y;
}
 
inline double dist(pt a, pt b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
 
inline double dist_pt_line(pt a, double A, double B, double C) {
    return (A * a.x + B * a.y + C) / sqrt(A * A + B * B);
}
 
inline void check1(pt c, pt d) {
    A = 2 * d.x - 2 * c.x, B = 2 * d.y - 2 * c.y, C = c.x * c.x + c.y * c.y + d.r * d.r - c.r * c.r - d.x * d.x - d.y * d.y;
    go = dist_pt_line(c, A, B, C);
    cur = 0;
    if (abs(go) - c.r > eps) return;
    s = sqrt(c.r * c.r - go * go);
    F = sqrt(A * A + B * B);
    x = -go * A / F, y = -go * B / F;
    //vector < pt > ans;
    F = s / F;
    ans[cur++] = {x - B * F, y + A * F, 0.0};
    ans[cur++] = {x + B * F, y - A * F, 0.0};
}
 
inline void check2(pt c) {
    cur = 0;
    if (c.r == 0) {
        ans[cur++] = c, ans[cur++] = c;
        return;
    }
    d = sqrt(c.x * c.x + c.y * c.y);
    f = sqrt(d * d - c.r * c.r);
    h = c.r * f / d;
    x1 = f * h / c.r;
    A = c.x, B = c.y;
    F = sqrt(A * A + B * B);
    x = A * x1 / F, y = B * x1 / F;
    //vector < pt > ans;
    F = h / F;
    ans[cur++] = {x - B * F, y + A * F, 0};
    ans[cur++] = {x + B * F, y - A * F, 0};
    /*for (int j = 0; j < cur; ++j) {
        if (abs(dist({0, 0, 0}, ans[j]) - f) > 0.00001) {
            cout << 1 / 0 << '\n';
            exit(0);
        }
    }*/
    return;
}
 
inline pt check3(pt c, pt d) {
    s = c.r / sqrt(d.x * d.x + d.y * d.y);
    x = d.x * s, y = d.y * s;
    return {x, y, 0};
}
 
main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    double x0, y0, v, t;
    cin >> x0 >> y0 >> v >> t;
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i].x >> a[i].y >> a[i].r;
    for (int i = 1; i <= n; ++i) a[i].x -= x0, a[i].y -= y0;
    pt go = {0, 0, min(v * t, Inf)};
    for (int i = 1; i <= n; ++i) {
        if (a[i].x * a[i].x + a[i].y * a[i].y <= a[i].r * a[i].r) {
            cout << 1 << '\n';
            return 0;
        }
    }
    vector < pt > Q;
    for (int i = 1; i <= n; ++i) {
        check2(a[i]);
        pt c = a[i];
        d = sqrt(c.x * c.x + c.y * c.y);
        f = sqrt(d * d - c.r * c.r);
        if (f <= go.r) {
            for (int j = 0; j < cur; ++j) {
                Q.push_back(check3(go, ans[j]));
            }
        }
        check1(go, a[i]);
        for (int j = 0; j < cur; ++j) Q.push_back(ans[j]);
    }
    vector < pair < double, double > > S;
    for (int j = 0; j < (int)Q.size(); j += 2) {
        double agl1 = atan2(Q[j].y, Q[j].x);
        if (agl1 < 0) agl1 += 2 * pi;
        double agl2 = atan2(Q[j + 1].y, Q[j + 1].x);
        if (agl2 < 0) agl2 += 2 * pi;
        if (agl1 > agl2) swap(agl1, agl2);
        if (agl2 - agl1 < pi) S.push_back({agl1, agl2});
        else {
            S.push_back({agl2, 2 * pi});
            S.push_back({0, agl1});
        }
    }
    //cout << '\n';
    //cout << '\n';
    vector < pair < double, int > > T;
    for (auto key : S) {
        //cout << key.first << " " << key.second << '\n';
        T.push_back({key.first, 0});
        T.push_back({key.second, 1});
    }
    double sum = 0, last_l;
    int bal = 0;
    sort(T.begin(), T.end());
    for (auto key : T) {
        if (key.second == 0) {
            bal++;
            if (bal == 1) last_l = key.first;
        }
        else {
            bal--;
            if (bal == 0) {
                sum += (key.first - last_l);
                //cout << key.first << " " << last_l << '\n';
            }
        }
    }
    cout << fixed << setprecision(9) << sum / (2 * pi) << '\n';
    return 0;
}