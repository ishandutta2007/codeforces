#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-9;
int n, d1, d2, ans = 0;
struct th
{
    double pos;
    bool type1; // d1d2
    int type2; // 1-10
};
bool operator==(th x, th y)
{
    return abs(x.pos - y.pos) < eps;
}
vector<th> s;
struct pnt
{
    long long x, y;
    pnt() {}
    pnt(long long x, long long y) : x(x), y(y) {}
} a[100010], b[100010];
pnt operator+(pnt x, pnt y) { return pnt(x.x + y.x, x.y + y.y); }
pnt operator-(pnt x, pnt y) { return pnt(x.x - y.x, x.y - y.y); }
long long dis2(pnt x) { return x.x * x.x + x.y * x.y; }
long long operator*(pnt x, pnt y) { return x.x * y.x + x.y * y.y; }
struct dpnt
{
    double x, y;
    dpnt (double x, double y) : x(x), y(y) {}
};
dpnt operator+(pnt x, dpnt y) { return dpnt(x.x + y.x, x.y + y.y); }
dpnt operator-(dpnt x, dpnt y) { return dpnt(x.x - y.x, x.y - y.y); }
dpnt operator*(pnt x, double y) { return dpnt(x.x * y, x.y * y); }
double dis2(dpnt x) { return x.x * x.x + x.y * x.y; }

int cmp(th x, th y)
{
    return x.pos - y.pos < -eps;
}
int main()
{
    scanf("%d%d%d", &n, &d1, &d2);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld%lld%lld%lld", &a[i].x, &a[i].y, &b[i].x, &b[i].y);
    }
    for (int i = 1; i < n; i++)
    {
        pnt x = a[i] - b[i], y = (a[i + 1] - a[i]) - (b[i + 1] - b[i]);
        long long dot = x * y, dx = dis2(x), dy = dis2(y);
        if (dy)
        {
            long long delta = dot * dot - dy * (dx - d1 * d1);
            // printf("%lld\n", delta);
            if (delta >= 0)
            {
                long double hh = sqrtl((long double)delta);
                long double t1 = (hh - dot) / dy;
                if (t1 > -eps && t1 < 1 + eps) s.push_back((th){double(i + t1), 0, -2});
                long double t2 = (-hh - dot) / dy;
                if (t2 > -eps && t2 < 1 + eps) s.push_back((th){double(i + t2), 0, -2});
            }
            delta = dot * dot - dy * (dx - d2 * d2);
            if (delta >= 0)
            {
                long double hh = sqrtl((long double)delta);
                long double t1 = (hh - dot) / dy;
                if (t1 > -eps && t1 < 1 + eps) s.push_back((th){double(i + t1), 1, -2});
                long double t2 = (-hh - dot) / dy;
                if (t2 > -eps && t2 < 1 + eps) s.push_back((th){double(i + t2), 1, -2});
            }
        }
        else
        {
            if (dx == d1 * d1)
            {
                s.push_back((th){double(i), 0, 0});
                s.push_back((th){double(i + 1), 0, -2});
            }
            else if (dx == d2 * d2)
            {
                s.push_back((th){double(i), 1, 0});
                s.push_back((th){double(i + 1), 1, -2});
            }
        }
    }
    if (s.empty())
    {
        if (dis2(a[1] - b[1]) <= d1 * d1) puts("1");
        else puts("0");
        return 0;
    }
    sort(s.begin(), s.end(), cmp);
    for (int i = 0; i < s.size() - 1; i++)
    {
        if (s[i].pos == s[i + 1].pos)
        {
            if (s[i].type2 == -2) s[i].type2 = s[i + 1].type2;
            if (s[i + 1].type2 == -2) s[i + 1].type2 = s[i].type2;
        }
    }
    s.erase(unique(s.begin(), s.end()), s.end());
    for (int i = 0; i < s.size() - 1; i++)
    {
        if (s[i].type2 == 0) continue;
        double pos = (s[i].pos + s[i + 1].pos) / 2;
        int base = lround(floor(pos));
        dpnt x = a[base] + (a[base + 1] - a[base]) * (pos - base);
        dpnt y = b[base] + (b[base + 1] - b[base]) * (pos - base);
        double dis = dis2(x - y);
        if (s[i].type1 == 0) // d1
        {
            if (dis - d1 * d1 < -eps) s[i].type2 = -1;
            else s[i].type2 = 1;
        }
        else
        {
            if (dis - d2 * d2 < -eps) s[i].type2 = -1;
            else s[i].type2 = 1;
        }
    }/*
    for (auto x : s)
    {
        printf("%lf %d %d\n", x.pos, x.type1, x.type2);
    }*/
    bool tf = 1;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i].type1 == 0)
        {
            if (tf) ans++;
            tf = 0;
        }
        else if (s[i].type1 == 1)
        {
            if (s[i].type2 == 1) tf = 1;
        }
    }
    printf("%d\n", ans);
}