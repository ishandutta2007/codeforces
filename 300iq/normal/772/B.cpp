/*

 
$












 
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct pt
{
    double x, y;
};

double dt(pt a, pt b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

double dist(pt p1, pt p2, pt q)
{
    double a = dt(q, p1);
    double b = dt(q, p2);
    double c = dt(p1, p2);
    if (a + c < b)
    {
        return sqrt(a);
    }
    if (b + c < a)
    {
        return sqrt(b);
    }
    double la = p2.y - p1.y;
    double lb = p1.x - p2.x;
    double lc = -p1.x * la - p1.y * lb;
    double ld = la * la + lb * lb;
    double d = la * q.x + lb * q.y + lc;
    return abs(d) / sqrt(ld);
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    vector <pt> p;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        p.push_back({x, y});
    }
    double ans = 1e18;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            ans = min(ans, dt(p[i], p[j]));
        }
    }
    for (int i = 0; i < n; i++)
    {
        ans = min(ans, dist(p[(i - 1 + n) % n], p[(i + 1) % n], p[i]));
    }
    cout << fixed << setprecision(20) << ans / 2 << endl;
}